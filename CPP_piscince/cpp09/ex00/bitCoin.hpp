#ifndef BITCOIN_HPP
# define BITCOIN_HPP
# include "includes.hpp"
# include "types.hpp"

class BitcoinExchange {
private:
	std::multimap<std::time_t, double>		_db;
	std::multimap<std::time_t, double>		_create_db(std::string csv);
//	std::multimap<std::string, double>		_inputMap;
	t_input									_create_inputStruct(std::string input);
	std::time_t								_ymd_utime(std::string date);
	bool									_isvalid_date(std::string date);
	bool									_ispositive_value(const double value);
	bool									_value_isinrange(const double value);
	double									_tradeValue(const std::string date, const double amount);
	double									_find_closest(const std::time_t time);
	std::string								_trim(const std::string& str);
	double									_ut(const std::time_t& time);

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& instance);
	BitcoinExchange& operator=(const BitcoinExchange& instance);
	~BitcoinExchange();
	//
	BitcoinExchange(std::string csv);
	//
	void	trade_values(std::string input);
	void	print_db(std::multimap<std::time_t, double> map);
	std::multimap<std::time_t, double>	get_db();

	class invalidValue : public std::exception
	{
		public:
			virtual const char *what() const throw() {
				return("Invalid value in input file");
				}
	};
	class invalidFirstline : public std::exception
	{
		public:
			virtual const char *what() const throw() {
				return("Invalid first line in input file");
				}
	};
};

#endif