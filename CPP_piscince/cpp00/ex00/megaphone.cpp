/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:39:00 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/08 16:40:04 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void ampliphy(char c)
{
    std::cout << char(std::toupper(c));
}

int main(int argc, char **argv)
{
    if (argc <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int x = 1; x < argc; x++)
    {
        for (int y = 0; argv[x][y]; y++)
            ampliphy(argv[x][y]);
    }
    std::cout << std::endl;
}