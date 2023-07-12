/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:46:22 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/13 19:30:19 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define	DIAMONDTRAP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{

public:
//####	Orthodox Canon
	DiamondTrap();
	DiamondTrap(const DiamondTrap& instance);
	DiamondTrap& operator=(const DiamondTrap& instance);
	~DiamondTrap();
//####	Other Constructors
	DiamondTrap(const std::string name);
	using	ScavTrap::attack;

	void	whoAmI();

private:
	std::string		_name;
};

#endif