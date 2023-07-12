#include "types.hpp"
#include "types.hpp"
#include "includes.hpp"

// for the purpose of this main, your binary takes many words as arguments and fills a vector with all argvs,
// so that we can test our easyfind template function on vectors of strings (we go beyond the subject): 
// The program then prompts the user for a word to find in the vector and test the easyfind() template.
// For completeness a list and an an array of ints are created and tested, as the subject requires.
// **For ease no input check is handled, so invalid inputs may break the execution.

int main(int argc, char **argv)
{
	std::vector<std::string>	vec;
	std::string	input;
	std::vector<std::string>::iterator found;
	
	for(int i = 0; i < argc; i++)
	{
		vec.push_back(argv[i]);// = argv[i];
	}
	// PART 1: vector
	std::cout << "what word are we searching in the container?" << std::endl;
    std::getline(std::cin, input, '\n');
	try {
		found = easyfind(vec, input);
		std::cout << "The element found refers to: " << *found << std::endl;
	}
    catch(std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	// PART 2: list
	std::cout << "We will try to initialize a std::list ranging from 0 to 6, and call our easyfind to find 4 in it!" << std::endl;
	std::list<int> list;
	std::list<int>::iterator listit;
	for (size_t i = 0; i < 6; i++)
	{
		list.push_back(i);
	}
	try {
		listit = easyfind(list, 4);
		std::cout << "The element found refers to: " << *listit << std::endl;
	}
    catch(std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
    return (0);
}
