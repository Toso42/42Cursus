#include "ClapTrap.hpp"

//########	ORTHODOX CANON
ClapTrap::ClapTrap()
{
	this->_hitP = 20;
	this->_energyP = 10;
	this->_attackD = 0;
	std::cout << "ClapTrap constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& instance)
{
	this->_name = instance._name;
	this->_attackD = instance._attackD;
	this->_energyP = instance._energyP;
	this->_hitP = instance._hitP;
	std::cout << "Copy constructor called for "<< instance._name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& instance)
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

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Denstructor called." << std::endl;
}

//#########	OTHER CONSTRUCTORS
ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitP = 20;
	this->_energyP = 10;
	this->_attackD = 0;
	std::cout << "Constructor called for "<< name << std::endl;
}

//########	PUBLIC METHODS

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyP == 0)
		return ;
	std::cout << this->_name << " attacks " << target << "... It's Super Effective!!! It causes " << this->_attackD << " damage."<< std::endl;
	this->_energyP = this->_energyP - 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitP -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyP == 0)
		return ;
	std::cout << this->_name << " repair itself..." << std::endl;
	this->_hitP = amount;
	this->_energyP = this->_energyP - 1;
}

int ClapTrap::getAttackDamage(void)
{
	return(this->_attackD);
}

const std::string ClapTrap::getName(void)
{
	return(this->_name);
}
