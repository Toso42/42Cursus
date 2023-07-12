#include "Animal.hpp"

Animal::Animal() : _type("Stem")
{
	std::cout << "an Animal born." << std::endl;
}

Animal::Animal(const Animal& instance)
{
	std::cout << "Animal copied" << std::endl;
	this->_type = instance._type;
}

Animal& Animal::operator=(const Animal& instance)
{
	if (this != &instance)
	{
		this->_type = instance._type;
	}
	return(*this);
}

Animal::~Animal()
{
	std::cout << "Animal terminated." << std::endl;
}

Animal::Animal(std::string type)
{
	this->_type = type;
}

void Animal::makeSound() const
{
	std::cout << "*Farts*" << std::endl;
}

