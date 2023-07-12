#include "includes.hpp"
#include "types.hpp"

int	toNumber(std::string token)
{
	std::istringstream	iss;
	long int	number;

	iss.str(token);
	iss >> number;
	if (number >= std::numeric_limits<int>::max())
		return std::numeric_limits<int>::max();
	else if (number <= std::numeric_limits<int>::min())
		return std::numeric_limits<int>::min();
	return number;
}

bool isInteger(const std::string& str) {
    if (str.empty()) {
        return false;
    }

    std::istringstream iss(str);
    long int value;
    return (iss >> value) && iss.eof();
}

std::vector<int>	create_vec(const char* argv)
{
	std::istringstream	input;
	input.str(argv);
	std::string	token;
	long int	arg;
	std::vector<int>	vec;



	while (input >> token) {
		if (!isInteger(token)) {
			throw BadInputException();
		}
		arg = toNumber(token);
		vec.push_back(static_cast<int>(arg));
	}
	return(vec);
}



int main(int argc, char **argv)
{
	if (argc != 2) {
	std::cout << "Error: could not open file." << std::endl;
	return 1;
	}

	std::vector<int>	vec;
	std::list<int>		lst;
	
	try {
//    	std::cout << std::setprecision(10) << std::fixed;
		std::cout << "Vector creation:" << std::endl;
		vec = create_vec(argv[1]);
		printContainer(vec);
		std::cout << "List creation:" << std::endl;
		lst = createContainer<std::list<int> >(vec);
		printContainer(lst);
		std::cout << std::endl;
		std::cout << " ## Vector Benchmark ##" << std::endl;
		benchmark(vec);
		if (isAscendingOrder(vec))
		    std::cout << "\033[1;32mResult is correct.\033[0m" << std::endl;
		std::cout << " ## List Benchmark ##" << std::endl;
		benchmark(lst);
		if (isAscendingOrder(lst))
		    std::cout << "\033[1;32mResult is correct.\033[0m" << std::endl;
	}
	catch(std::exception& e){ std::cout << e.what() << std::endl;};



	std::cout << "done" << std::endl;
    return 0;
}
