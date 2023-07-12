#include "includes.hpp"

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

void	perform_operation(std::deque<int>& numbers, std::string op)
{
	int	rhs = numbers.front();
	numbers.pop_front();
	int lhs = numbers.front();
	numbers.pop_front();
	if (!op.compare("+")) {
		numbers.push_front(lhs + rhs);
	}
	if (!op.compare("-")) {
		numbers.push_front(lhs - rhs);
	}
	if (!op.compare("*")) {
		numbers.push_front(lhs * rhs);
	}
	if (!op.compare("/")) {
		if (lhs == 0 || rhs == 0) {
			std::cout << "{ warning: dividing by zero: 0 value assigned to answer }" << std::endl;
			numbers.push_front(0);
			return ;
		}
		numbers.push_front(lhs / rhs);
	}
}

bool isInteger(const std::string& str) {
    if (str.empty()) {
        return false;
    }

    std::istringstream iss(str);
    int value;
    return (iss >> value) && iss.eof();
}

bool isOperator(const std::string& str) {
    static const std::string operators = "+-*/";
    return (str.size() == 1) && (operators.find(str) != std::string::npos);
}

int main(int argc, char **argv) {
    //std::string input = "   2        2147483647 1 +";

	if (argc != 2) {
		std::cout << "Error" << std::endl;
		return (1);
	}
	std::string	input(argv[1]);
    std::istringstream iss(input);
    std::vector<std::string> tokens;
    std::string token;
	int				number;
	std::deque<int>	numbers;

    while (iss >> token) {
        if (isInteger(token)) {
//            std::cout << "Integer: " << token << std::endl;
			number = toNumber(token);
			numbers.push_front(number);
        } else if (isOperator(token)) {
//            std::cout << "Operator: " << token << std::endl;
			perform_operation(numbers, token);
        } else {
            std::cout << "Invalid element: " << token << std::endl;
			return 1;
        }
    }
	std::cout << numbers.front() << std::endl;
    return 0;
}