#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Stem")
{
	std::cout << "a Dog was born, with it's own brain." << std::endl;
	this->_brain = new Brain;
}

Dog::Dog(const Dog& instance) : Animal("Stem")
{
	this->_type = instance._type;
	this->_brain = new Brain;
	this->_brain = instance._brain;
	std::cout << "Dog copied" << std::endl;
}

Dog& Dog::operator=(const Dog& instance)
{
	if (this != &instance)
	{
		this->_type = instance._type;
		this->_brain = instance._brain;
	}
	return(*this);
}

Dog::~Dog()
{
	delete (this->_brain);
	std::cout << "Dog terminated." << std::endl;
	
}

Dog::Dog(std::string type)
{
	this->_type = type;
}

void Dog::makeSound() const
{
	std::cout << "*Barks*" << std::endl;
}