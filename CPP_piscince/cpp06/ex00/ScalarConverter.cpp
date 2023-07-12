#include "classes.hpp"
#include "includes.hpp"


ScalarConverter::ScalarConverter()
{
	;
}

ScalarConverter::ScalarConverter(const ScalarConverter& instance)
{
	(void)instance;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& instance)
{
	(void)instance;
	return(*this);
}

ScalarConverter::~ScalarConverter()
{
	;
}

// METHODS
void ScalarConverter::convert(std::string literal)
{
	std::cout << "##########################" << std::endl;
	std::cout << ScalarConverter::toChar(literal) << std::endl;
	std::cout << ScalarConverter::toInt(literal) << std::endl;
	std::cout << ScalarConverter::toFloat(literal) << std::endl;
	std::cout << ScalarConverter::toDouble(literal) << std::endl;
	std::cout << "##########################" << std::endl;
}

bool ScalarConverter::isNum(std::string arg)
{
	size_t	pointCounter = 0;

	if (!arg.compare("-inf") || !arg.compare("+inf") || !arg.compare("-inff") || !arg.compare("+inff"))
		return(true);
	for (size_t x = 0; x < (arg.size() - 1); x++)
	{
		if (!std::isdigit(arg[x]) && arg[x] != '.' && arg[x] != '+' && arg[x] != '-')
			return(false);
		if (arg[x] == '.')
			++pointCounter;
	}
	if (!std::isdigit(arg[arg.size() - 1]) && arg[arg.size() - 1] != 'f')
		return(false);
	if (pointCounter > 1)
		return (false);
	return(true);
}

std::string ScalarConverter::toChar(std::string arg)
{
	std::string conversion = "char: ";
	char str[2];

	if (!(arg.compare("-inf") || arg.compare("+inf") || arg.compare("-inff") || arg.compare("+inff")))
		conversion += "Impossible";
	else if (arg.size() == 1)
	{ 
		if ((int)arg.c_str()[0] < 32 || (int)arg.c_str()[0] > 126)
			conversion += "Not Displayable";
		else
		{
			int	num = static_cast<int> (arg[0]);
			str[0] = num;
			str[1] = 0;
			conversion += str;
		}
	}
	else
	{ 
		int num = std::atoi(arg.c_str());
		str[0] = num;
		str[1] = 0;
		conversion += str;
	}
	return(conversion);
}

std::string ScalarConverter::toInt(std::string arg)
{
	std::stringstream conversion;
	long int	num = std::atol(arg.c_str());

	conversion << "int: ";
	if (!arg.compare("-inf") || !arg.compare("-inff") || !arg.compare("+inff") || !arg.compare("+inf"))
		conversion <<"Out of range";
	else if (!(arg.compare("nan") || arg.compare("nanf")))
		conversion << "Nan";
	else if (ScalarConverter::isNum(arg) == false)
		conversion << "Nan";
	else if (num > INT_MAX || num < INT_MIN)
		conversion << "Out of range";
	else
		conversion << static_cast<int>(num);
	return(conversion.str());
}

// subject asks explicitly to make use of static_cast, but another implicit rule is to only use c++98 compliant
// standard namespace functions. Atof is the only possible solution here without rewriting a custom
// solution. Unfortunately Atof also rounds the fixed point only up to 5 decimals, making the float/double
// conversion pointless. C++11 introduces more precise methods. The sole point for this subject is to
// make use of type casting.
std::string ScalarConverter::toFloat(std::string arg)
{
	std::stringstream conversion;
	double	number;
	
	conversion << "float: ";	
	if (!arg.compare("-inf") || !arg.compare("-inff"))
		conversion << "-Inff";
	else if(!arg.compare("+inff") || !arg.compare("+inf"))
		conversion << "Inff";
	else if (!arg.compare("nan") || !arg.compare("nanf"))
		conversion << "Nanf";
	else if (ScalarConverter::isNum(arg) == false)
		conversion << "Nanf";
	else
	{
		number = static_cast<float>(atof(arg.c_str()));
		conversion << number << "f";
	}

	return(conversion.str());
}


std::string ScalarConverter::toDouble(std::string arg)
{
	std::stringstream conversion;
	float	number;
	
	conversion << "double: ";
	if (!((arg.compare("-inf") || arg.compare("-inff"))))
		conversion << "-Inff";
	else if(!(arg.compare("+inff") || arg.compare("+inf")))
		conversion << "Inff";
	else if (!(arg.compare("nan") || arg.compare("nanf")))
		conversion << "Nan";
	else if (ScalarConverter::isNum(arg) == false)
		conversion << "Nan";
	else
	{
		number = static_cast<double>(atof(arg.c_str()));
		conversion << number;
	}
		return(conversion.str());
}

std::string ScalarConverter::int_to_string(int value)
{
	std::string result;
	if (value == 0) {
		return "0";
	}
	if (value < 0) {
		result += '-';
		value = -value;
	}
	while (value > 0) {
		char digit = '0' + (value % 10);
		result = digit + result;
		value /= 10;
	}
	return result;
}

std::string ScalarConverter::float_to_string(float value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();	
}
