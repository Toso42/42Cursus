#include "ScavTrap.hpp"

//########	ORTHODOX
ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hitP = 100;
	this->_energyP = 100;
	this->_attackD = 30;
	std::cout << "ScavTrap instantiated"  << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& instance)
{
	this->_name = instance._name;
	this->_attackD = instance._attackD;
	this->_energyP = instance._energyP;
	this->_hitP = instance._hitP;
	std::cout << "Copy constructor called for "<< instance._name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& instance)
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

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destroyed." << std::endl;
}

//########	OTHER CONSTRUCTORS
ScavTrap::ScavTrap(const std::string name)
{
	this->_name = name;
	this->_hitP = 100;
	this->_energyP = 100;
	this->_attackD = 30;
	std::cout << "ScavTrap instantiated"  << std::endl;
}

void	ScavTrap::attack(ClapTrap& whom)
{
	if (this->_energyP <= 0)
		return;
	std::cout << this->getName() << " attacks " << whom.getName() << " and deals " << this->_attackD << " damage!" << std::endl;
}

//########	METHODS
void ScavTrap::guardGate()
{
	if (this->_energyP <= 0)
		return;
	std::cout	<< this->getName() << " entering GATEKEEPER mode!!!" << std::endl;
}

