#include "includes.hpp"
#include "classes.hpp"


//Reinterpret_cast is an instruction to the compiler to treat a type or an object as a specified type/object without performing any action on it.
//This circumvents compiling errors. This is not a safe operation, but it's a behaviour that might be needed on extreme cases, such as situations
//in which other types of casts are impossible (typically compatibility issues).
int main()
{
	// uintptr_t uintptr;
	Data *dptr;
	Data *nptr;

	std::cout << "creating a Data struct" << std::endl;
	dptr = new(Data);
	std::cout << "assigning Data fields (Pippo 1)" << std::endl;
	dptr->string = "Pippo";
	dptr->number = 1;

	std::cout << "nptr = deserializing(serializing)" << std::endl;
	nptr = Serializer::deserialize(Serializer::serialize(dptr));

	std::cout << "reading dptr:" << std::endl;
	std::cout << dptr << std::endl;
	std::cout << "reading from dptr: " << dptr->string << " " << dptr->number << std::endl;
	std::cout << "reading nptr:" << std::endl;
	std::cout << nptr << std::endl;
	std::cout << "reading from nptr: " << nptr->string << " " << nptr->number << std::endl;
	free(dptr);
	return (0);
}