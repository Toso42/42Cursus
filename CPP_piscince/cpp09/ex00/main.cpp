#include "includes.hpp"



int main(int argc, char **argv) {

	//checks
	if (argc != 2) {
	std::cout << "Error: could not open file." << std::endl;
	return 1;
	}
    std::ifstream   input(argv[1]);
	if (!input) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;		
	}
	else { input.close(); }

	// declarations
    std::cout << std::setprecision(4) << std::fixed;
	BitcoinExchange Ex("data.csv");
	std::cout.unsetf(std::ios::fixed);
//	Ex.print_db(Ex.get_db());
//	std::cout << "Exchange created." << std::endl;
//	std::ifstream	input(argv[1]);

	Ex.trade_values(argv[1]);

	return 0;
}