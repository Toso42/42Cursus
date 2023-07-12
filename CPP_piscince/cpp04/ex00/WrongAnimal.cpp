#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Stem")
{
	std::cout << "WrongAnimal born." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& instance)
{
	std::cout << "WrongAnimal copied" << std::endl;
	this->_type = instance._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& instance)
{
	if (this != &instance)
	{
		this->_type = instance._type;
	}
	return(*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal terminated." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->_type = type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "*Farts*" << std::endl;
}

