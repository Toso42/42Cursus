#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include "includes.hpp"
#include "classes.hpp"

class ScalarConverter
{
private:
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &instance);
	ScalarConverter &operator=(const ScalarConverter &instance);
	~ScalarConverter();

	static void convert(std::string literal);
	static std::string toChar(std::string arg);
	static std::string toInt(std::string arg);
	static std::string toDouble(std::string arg);
	static std::string toFloat(std::string arg);
	static bool isNum(std::string arg);
	static std::string int_to_string(int value);
	static std::string float_to_string(float value);
};

std::ostream &operator<<(std::ostream &output, const ScalarConverter &instance);

#endif


typedef struct s_string {
	char*	array;
	size_t	size;
} t_string;