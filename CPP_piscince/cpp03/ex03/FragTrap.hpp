/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:46:22 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/13 19:50:27 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define	FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
public:
//####	Orthodox Canon
	FragTrap();
	FragTrap(const FragTrap& instance);
	FragTrap& operator=(const FragTrap& instance);
	~FragTrap();
//####	Other Constructors
	FragTrap(const std::string name);
	void	attack(ClapTrap& whom);

	void highFivesGuys(void);
};

#endif