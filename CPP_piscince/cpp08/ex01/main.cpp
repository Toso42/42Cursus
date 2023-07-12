#include "types.hpp"
#include "includes.hpp"
#define	TEST_SIZE 20

int main()
{
	Span sp = Span(5);
	//////////// EMPTY CASE ////////////////////
	try {
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	//////////// GENERIC CASE //////////////////
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl; };
	try {
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	/////////// HUGE CASE ////////////////

	std::cout << std::endl;
	std::cout << "Generating a RANDOM int vector" << std::endl;
	std::vector<int>	vec(TEST_SIZE);
	srand(time(NULL));
	for (size_t i = 0; i < TEST_SIZE; i++)
	{
		vec[i] = rand() % TEST_SIZE;
	}

	std::cout << "Trying to fill a Span from range" << std::endl;

	Span sp2 = Span(TEST_SIZE);
	std::vector<int>	sp2vec;

	sp2.fillRange(vec.begin(), vec.end());
	sp2vec = sp2.getArray(); // yeah i am making a copy because the subject is stupid and i don't wont to stray from it: an iterator wouldn't allow me to call vector.size() for instance.

	std::cout << "sp2 size: " << sp2vec.size() << std::endl;
	std::cout << sp2 << std::endl;
	std::cout << "let's check shortest and longest: " << std::endl;
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	std::cout << "done" << std::endl;

	// PS: IF YOU WANNA TEST __EXCEPTIONS__ REMEMBER TRY AND CATCHES
	return 0;
}