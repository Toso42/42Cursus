/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:46:22 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/13 18:08:34 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define	SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
private:
	std::string	_name;
	int			_hitP;
	int			_energyP;
	int			_attackD;
public:
//####	Orthodox Canon
	ScavTrap();
	ScavTrap(const ScavTrap& instance);
	ScavTrap& operator=(const ScavTrap& instance);
	~ScavTrap();
//####	Other Constructors
	ScavTrap(const std::string name);
	void	attack(ClapTrap& whom);

	void	guardGate();
};

#endif