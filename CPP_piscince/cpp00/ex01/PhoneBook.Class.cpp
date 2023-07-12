/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:27:07 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/08 16:36:51 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.Class.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <cstdlib>
#include <stdio.h>
# define TABBING "	"
# define HEAD_SPACE "\n\n"

PhoneBook::PhoneBook(void) {
	this->_current_index = -1;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

int PhoneBook::add_subroutine(void)
{
	std::string	local_input;
	
	if (this->_current_index == 7)
		this->_current_index = 0;
	else
		this->_current_index += 1;
//	std::system("clear");
	std::system("clear");
	std::cout << HEAD_SPACE << std::endl;
	// printf("current index before call: %d\n", this->_current_index);
	this->_Contacts[this->_current_index].set_fname();
	this->_Contacts[this->_current_index].set_index((_current_index + 1));
	this->_Contacts[this->_current_index].set_lname();
	this->_Contacts[this->_current_index].set_nname();
	this->_Contacts[this->_current_index].set_tel();
	this->_Contacts[this->_current_index].set_secret();
	std::cout << TABBING "done. Type anything to return to Menu" << std::endl;
	std::getline (std::cin, local_input, '\n');
	if (std::cin.eof() == true)
		return (1);
	return (0);
}

void PhoneBook::expand_contact(Contact *match)
{
	std::string	local_input;

	std::system("clear");
	std::cout << HEAD_SPACE TABBING "What have you told me about this person:" << std::endl;
	std::cout << TABBING << match->get_fname() << std::endl;
	std::cout << TABBING << match->get_lname() << std::endl;
	std::cout << TABBING << match->get_nname() << std::endl;
	std::cout << TABBING << match->get_tel() << std::endl;
	std::cout << TABBING << match->get_secret() << std::endl;
	std::cout << HEAD_SPACE TABBING "Type anything to return." << std::endl;

	std::getline (std::cin, local_input, '\n');
	std::cout << std::flush;
	if (std::cin.eof() == true)
	{
//		std::cout << "eof" << std::endl;
//		std::getline(std::cin, field);
		exit(0);
	}
}

void PhoneBook::search_subroutine(void)
{
	std::string	field;
	std::string	index_line = "	|";
	std::string	local_input;

//	std::stringstream	index_input;

	std::system("clear");
	if (this->_Contacts[0].is_used() == false)
	{
		std::cout << HEAD_SPACE TABBING "Empty list, type anything to return." << std::endl;
		std::getline (std::cin, local_input, '\n');
		if (std::cin.eof() == true)
			exit(0);
		return ;
	}
	do {
		std::system("clear");
		std::string	_headline = "	|      index | first name |  last name |   nickname |\n	=====================================================";
		std::cout << HEAD_SPACE << _headline << std::endl;
		for (int x = 0; x < 8; x++)
		{
			if (this->_Contacts[x].is_used() == false)
			{
				//std::cout << "not used index" << std::endl;
				break;
			}
			std::cout << "	| " << std::setw(10) << this->_Contacts[x].get_index();
			std::cout << " | " << std::setw(10) << this->format_string(this->_Contacts[x].get_fname());
			std::cout << " | " << std::setw(10) << this->format_string(this->_Contacts[x].get_lname());
			std::cout << " | " << std::setw(10) << this->format_string(this->_Contacts[x].get_nname());
			std::cout << " |" << std::endl;
		}
		std::cout << "\n" << TABBING "If you want more details on someone on the list, please type it's index number. \n	Type EXIT instead if you want to stop reviewing your deathnote." << std::endl << TABBING;;
		local_input.empty();
		std::getline (std::cin, local_input, '\n');
		std::cout << std::flush;
		if (std::cin.eof() == true)
		{
//			std::cout << "eof" << std::endl;
//			std::getline(std::cin, field);
			exit(0);
		}
		if (local_input.size() <= 0)
		{
			std::cout << std::flush;
		}
		for (int x = 0; x < 8; x++)
		{
			if ((std::atoi(local_input.c_str()) > 0) && (std::atoi(local_input.c_str()) == this->_Contacts[x].get_index()))
			{
//				std::cout << TABBING "FOUND SOMETHING" << std::endl;
//				sleep(2);
				this->expand_contact(&this->_Contacts[x]);
				return ;
			}
		}
	} while (std::cin.eof() == false && local_input.compare("EXIT"));
	if (std::cin.eof() == true)
		exit(0);
}

std::string PhoneBook::format_string(std::string field_string)
{
	std::string formatted_field;

//	printf("format_string called {%s}\n", field_string.c_str());
	if (field_string.size() > 10)
	{
		formatted_field = field_string.substr(0, 10);
		formatted_field[9] = '.';
		return(formatted_field);
	}
	else
		return(field_string);
}
