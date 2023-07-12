/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:17:03 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/08 17:33:01 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main (void)
{
	Harl	harl;
	std::string	input;
	while (1)
	{
		input.clear();
		std::getline(std::cin, input, '\n');
		if (std::cin.eof() == true)
			return (1);
		harl.complain(input);
	}
	return (0);
}