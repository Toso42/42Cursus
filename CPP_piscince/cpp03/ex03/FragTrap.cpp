#include "FragTrap.hpp"

//########	ORTHODOX
FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hitP = 100;
	this->_energyP = 100;
	this->_attackD = 30;
	std::cout << "FragTrap instantiated"  << std::endl;
}

FragTrap::FragTrap(const FragTrap& instance)
{
	this->_name = instance._name;
	this->_attackD = instance._attackD;
	this->_energyP = instance._energyP;
	this->_hitP = instance._hitP;
	std::cout << "Copy constructor called for "<< instance._name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& instance)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destroyed." << std::endl;
}

//########	OTHER CONSTRUCTORS
FragTrap::FragTrap(const std::string name) :ClapTrap(name)
{
	this->_hitP = 100;
	this->_energyP = 100;
	this->_attackD = 30;
	std::cout << "FragTrap instantiated"  << std::endl;
}

void	FragTrap::attack(ClapTrap& whom)
{
	if (this->_energyP <= 0)
		return;
	std::cout << this->getName() << " attacks " << whom.getName() << " and deals " << this->_attackD << " damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_energyP <= 0)
		return;
	std::cout << this->_name << " raises his hand... is he asking for a High Five here...?" << std::endl;
}

//########	METHODS


