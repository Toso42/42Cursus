#include "includes.hpp"
#include "classes.hpp"

Base* generate()
{
	std::cout << "Generator called:" << std::endl;

	int random = (rand() % 3);
	std::cout << "rand % 3 = " << random << std::endl;
	std::cout << "case 0: A | case 1: B | case 2: C" << std::endl;
	switch(random)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return NULL;
	}
}


void try_recursively_refcasting(Base& ref, int index)
{
	try
	{
		switch(index)
		{
			case 0:
				std::cout << dynamic_cast<A&>(ref);
				break;
			case 1:
				std::cout << dynamic_cast<B&>(ref);
				break;
			case 2:
				std::cout << dynamic_cast<C&>(ref);
				break;
			case 3:
				std::cout << "Not a recognized Class" << std::endl;
		}
	}
	catch(const std::bad_cast& e)
	{
		try_recursively_refcasting(ref, index + 1);
	}
}

// dynamic_cast on a reference throws exceptions on failure, so a dynamic_cast on a reference should ideally be attempted in a try block with bad_cast exception handler.
void identify(Base &ref)
{
	try_recursively_refcasting(ref, 0);
}

// dynamic_cast on a pointer can be compared to a NULL pointer to check if operation succeded
void identify(Base *ptr)
{
	if (dynamic_cast<A*>(ptr))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(ptr))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(ptr))
		std::cout << "C" << std::endl;
	else
		std::cerr << "Cast is neither A, B nor C" << std::endl;
}

int main()
{
	Base* ptr;
	
	srand(time(NULL));
	ptr = generate();
	Base& ref = *ptr;
	std::cout << "Calling identifier through pointer" << std::endl;
	identify(ptr);
	std::cout << "Calling identifier through reference" << std::endl;
	identify(ref);
	delete(ptr);
}

std::ostream&	operator<<( std::ostream& stream, const A& obj ) {
	(void) obj;
	stream << "A" << std::endl;

	return (stream);
}

std::ostream&	operator<<( std::ostream& stream, const B& obj ) {
	(void) obj;
	stream << "B" << std::endl;

	return (stream);
}

std::ostream&	operator<<( std::ostream& stream, const C& obj ) {
	(void) obj;
	stream << "C" << std::endl;

	return (stream);
}