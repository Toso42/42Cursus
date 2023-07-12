#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "a Brain turned on" << std::endl;
}

Brain::Brain(const Brain& instance)
{
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = instance.ideas[i];	
}

Brain& Brain::operator=(const Brain& instance)
{
	if (this != &instance)
	{
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = instance.ideas[i];
	}
	return(*this);
}

Brain::~Brain()
{
	std::cout << "a Brain turned off" << std::endl;
}
