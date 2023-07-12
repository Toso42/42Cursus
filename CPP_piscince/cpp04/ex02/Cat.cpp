#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Stem")
{
	std::cout << "a was Cat born, with it's own brain." << std::endl;
	this->_brain = new Brain;
}

Cat::Cat(const Cat& instance) : Animal("Stem")
{
	std::cout << "Cat copied" << std::endl;
	this->_brain = new Brain;
	this->_brain = instance._brain;
	this->_type = instance._type;
}

Cat& Cat::operator=(const Cat& instance)
{
	if (this != &instance)
	{
		this->_type = instance._type;
		this->_brain = instance._brain;
	}
	return(*this);
}

Cat::~Cat()
{
	delete (this->_brain);
	std::cout << "Cat terminated." << std::endl;
}

Cat::Cat(std::string type)
{
	this->_type = type;
}

void Cat::makeSound() const
{
	std::cout << "*Meows*" << std::endl;
}