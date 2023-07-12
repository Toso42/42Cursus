#include "WrongCat.hpp"
#include "Brain.hpp"

WrongCat::WrongCat() : WrongAnimal("Stem")
{
	std::cout << "a WrongCat was born, with it's own brain." << std::endl;
	this->_brain = new Brain;
}

WrongCat::WrongCat(const WrongCat& instance) : WrongAnimal("Stem")
{
	std::cout << "WrongCat copied" << std::endl;
	this->_brain = new Brain;
	this->_brain = instance._brain;
	this->_type = instance._type;
}

WrongCat& WrongCat::operator=(const WrongCat& instance)
{
	if (this != &instance)
	{
		this->_type = instance._type;
		this->_brain = instance._brain;
	}
	return(*this);
}

WrongCat::~WrongCat()
{
	delete (this->_brain);
	std::cout << "WrongCat terminated." << std::endl;
}

WrongCat::WrongCat(std::string type)
{
	this->_type = type;
}

void WrongCat::makeSound() const
{
	std::cout << "*Meows*" << std::endl;
}