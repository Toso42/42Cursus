/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deathnote.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tcorax42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:05:06 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/01/15 13:50:45 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.Class.hpp"
#include "PhoneBook.Class.hpp"
#include <iostream>
#include <cstdlib>
# define TABBING "	"
# define HEAD_SPACE "\n\n"



int parse_command(std::string input, PhoneBook *deathlist)
{
	// static int	local_index = -1;
	
	// if (local_index == 7)
	// 	local_index = 0;
	// else
	// 	local_index += 1;
	if (!input.compare("EXIT"))
	{
//		std::cout << "exiting";
		exit(0);
	}
	else if (!input.compare("SEARCH"))
	{
		deathlist->search_subroutine();
//		deathlist->get_fname();
	}
	else if (!input.compare("ADD")
			&& deathlist->add_subroutine())
		return (1);
	return (0);
}

int main (void) 
{
	std::string	input;
	PhoneBook deathlist;

	do {
		input.erase(0);
		std::system("clear");
		std::cout << HEAD_SPACE << TABBING << "Death Note: \n" << TABBING << "Give me 8 names!" << std::endl;
		std::cout << "\n" TABBING << "Should i ADD, SEARCH, or EXIT ?" << std::endl;
		std::cout << HEAD_SPACE << std::endl << TABBING;
		std::getline (std::cin, input, '\n');
	} while (std::cin.eof() == false && !parse_command(input, &deathlist));
	return (0);
}