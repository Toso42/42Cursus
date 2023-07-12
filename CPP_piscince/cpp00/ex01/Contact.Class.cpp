/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   Contact.Class.cpp								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tdi-leo <tdi-leo@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/10 11:58:55 by tdi-leo		   #+#	#+#			 */
/*   Updated: 2023/01/14 15:43:24 by tdi-leo		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "Contact.Class.hpp"
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# define TABBING "	"


bool Contact::is_valid_stream(void)
{
	if (std::cin.eof() == false)
		return (true);
	return (false);
}

Contact::Contact(void)
{
	this->_is_used = false;
	this->set_index(-1);
	return;
}

void Contact::set_used(void)
{
	this->_is_used = true;
}

bool Contact::is_used(void)
{
	if (this->_is_used == true)
		return (true);
	return (false); 
}

void Contact::set_index(int index)
{
	// char	indexchar[99999];
	
	// sprintf(indexchar, "%d", index);
	this->_index = index;
}

int Contact::get_index(void)
{
	return (this->_index);
}

void Contact::set_fname()
{
	std::string input;

	std::cout << TABBING "Tell me the person first name." << std::endl << TABBING;
	std::getline(std::cin, input, '\n');
	if (this->is_valid_stream() == false)
		exit(0);
	if (input.length() > 0)
	{
		this->_first_name.clear();
		this->_first_name = input.substr(0, input.size());
		this->set_used();
	}
	else
	{
		std::cout << TABBING "No Empty fields allowed!" << std::endl;
	//	sleep(1);
		this->set_fname();
	}
}

void Contact::set_lname(void)
{
	std::string input;

	std::cout << TABBING "Tell me the person last name." << std::endl << TABBING;
	std::getline(std::cin, input, '\n');
	if (this->is_valid_stream() == false)
		exit(0);
	if (input.length() > 0)
	{
		this->_last_name.clear();
		this->_last_name = input.substr(0, input.size());
		this->set_used();
	}
	else
	{
		std::cout << TABBING "No Empty fields allowed!" << std::endl;
	//	sleep(1);
		this->set_lname();
	}
}

void Contact::set_nname(void)
{
	std::string input;

	std::cout << TABBING "Tell me the person nickname" << std::endl << TABBING;
	std::getline(std::cin, input, '\n');
	if (this->is_valid_stream() == false)
		exit(0);
	if (input.length() > 0)
	{
		this->_nickname.clear();
		this->_nickname = input.substr(0, input.size());
		this->set_used();
	}
	else
	{
		std::cout << TABBING "No Empty fields allowed!" << std::endl;
	//	sleep(1);
		this->set_nname();
	}
}

void Contact::set_tel(void)
{
	std::string input;

	std::cout << TABBING "Tell me the person telephone number" << std::endl << TABBING;
	std::getline(std::cin, input, '\n');
	if (this->is_valid_stream() == false)
		exit(0);
	if (input.length() > 0)
	{
		this->_tel_number.clear();
		this->_tel_number = input.substr(0, input.size());
		this->set_used();
	}
	else
	{
		std::cout << TABBING "No Empty fields allowed!" << std::endl;
	//	sleep(1);
		this->set_tel();
	}
}

void Contact::set_secret(void)
{
	std::string input;

	std::cout << TABBING "Tell me the person darkest secret" << std::endl << TABBING;
	std::getline(std::cin, input, '\n');
	if (this->is_valid_stream() == false)
		exit(0);
	if (input.length() > 0)
	{
		// this->_is_used = true;
		this->_secret = input.substr(0, input.size());
		this->set_used();
	}
	else
	{
		std::cout << TABBING "No Empty fields allowed!" << std::endl;
	//	sleep(1);
		this->set_secret();
	}
}

std::string Contact::get_fname(void)
{
	return (this->_first_name);
	//std::cout << this->_first_name << std::endl;
}

std::string Contact::get_lname(void)
{
	return (this->_last_name);
//	std::cout << this->_last_name << std::endl;
}
std::string Contact::get_nname(void)
{
	return (this->_nickname);
//	std::cout << this->_nickname << std::endl;
}

std::string Contact::get_tel(void)
{
	return (this->_tel_number);
//	std::cout << this->_tel_number << std::endl;
}

std::string Contact::get_secret(void)
{
	return (this->_secret);
//	std::cout << this->_secret << std::endl;
}
