#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	this->announce();
}

Zombie::~Zombie(void)
{
	std::cout << "\e[1m  *" << this->_name << " was killed. Again.*\e[0m" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": \"BraiiiiiiinnnzzzZ...\"" << std::endl;
}


// void Zombie::_set_name(std::string name)
// {
// 	this->name = name;
// }
