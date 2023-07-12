/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tcorax42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:32:56 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/01/25 16:56:54 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string whoisit = "HI THIS IS BRAIN";
	std::string	*stringPTR = &whoisit;
	std::string &stringREF = whoisit;

	std::cout << "whoisit address: " << &whoisit << std::endl;
	std::cout << "stringPTR value: " << stringPTR << std::endl;
	std::cout << "memory address held by stringREF: " << &stringREF << std::endl << std::endl;

	std::cout << "string value " << whoisit << std::endl;
	std::cout << "value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value pointed by stringREF: " << stringREF << std::endl;

}