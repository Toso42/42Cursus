#include "DiamondTrap.hpp"

//########	ORTHODOX
DiamondTrap::DiamondTrap(void) : _name("Void")
{
	ClapTrap::_name = _name + "_clap_name";
	this->_energyP = ScavTrap::_energyP;
	this->_attackD = FragTrap::_attackD;
	this->_hitP = FragTrap::_hitP;
	std::cout << "DiamondTrap instantiated"  << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& instance)
{
	this->_name = instance._name;
	this->_attackD = instance._attackD;
	this->_energyP = instance._energyP;
	this->_hitP = instance._hitP;
	std::cout << "Copy constructor called for "<< instance._name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& instance)
{
	if (this != &instance)
	{
		this->_name = instance._name;
		this->_attackD = instance._attackD;
		this->_energyP = instance._energyP;
		this->_hitP = instance._hitP;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destroyed." << std::endl;
}

//########	OTHER CONSTRUCTORS
DiamondTrap::DiamondTrap(const std::string name)
{
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_energyP = ScavTrap::_energyP;
	this->_attackD = FragTrap::_attackD;
	this->_hitP = FragTrap::_hitP;
	std::cout << "DiamondTrap instantiated"  << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Hi! i am " << this->_name << " but implicitly i am also called " << ClapTrap::getName() << std::endl;
}


//########	METHODS


