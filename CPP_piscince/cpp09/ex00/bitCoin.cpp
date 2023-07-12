# include "includes.hpp"
# include "types.hpp"

BitcoinExchange::BitcoinExchange()
{
	;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& instance)
{
	this->_db = instance._db;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& instance)
{
	this->_db = instance._db;
	return(*this);
}

BitcoinExchange::~BitcoinExchange()
{
	;
}

BitcoinExchange::BitcoinExchange(std::string csv)
{
	this->_db = this->_create_db(csv);
}

std::multimap<std::time_t, double> BitcoinExchange::_create_db(std::string csv)
{
	//	INPUT, READEN LINE
	std::ifstream	file(csv.c_str());
	std::string	line;
	//	READEN VALUES
	std::string	line_date;
	std::time_t	date_time;
	std::string	line_value;
	double	value;
	//	LINE STREAM, DB TO RETURN
	std::multimap<std::time_t, double>	db;

	if (!file.is_open()) {
	std::cerr << "Error opening CSV DB." << std::endl;
	return (db); 
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream	value_stream;
		std::istringstream sline;

		sline.str(line);

		std::getline(sline, line_date, ',');
		std::getline(sline, line_value);

		value_stream.str(line_value);
		value_stream >> value;
		if (value < 0) {
			std::cout << "Error: invalid CSV value conversion" <<  std::endl;
			return (db);
		}

		date_time = this->_ymd_utime(line_date);
		db.insert(std::make_pair(date_time, value));
	}
	file.close();
	return (db);
}

void BitcoinExchange::trade_values(std::string input)
{
	std::ifstream	file(input.c_str());
	bool									valid_date;
	bool									positive_value;
	bool									valid_range;
	t_input									input_struct;
	std::string								date;
	std::string								readenline;

	if (!file.is_open()) {
		std::cerr << "Error opening INPUT FILE." << std::endl;
		return;
	}
	while (std::getline(file, readenline))
	{
		input_struct = this->_create_inputStruct(readenline);
		if (input_struct.is_firstline == false)
		{
			valid_date = this->_isvalid_date(input_struct.date);
			positive_value = this->_ispositive_value(input_struct.amount);
			valid_range = this->_value_isinrange(input_struct.amount);

			if (!valid_date) {
				std::cout << "Error: bad input => " << input_struct.date << std::endl;
			}
			else if (!positive_value) {
				std::cout << "Error: not a positive number." << std::endl;
			}
			else if (!valid_range) {
				std::cout << "Error: too large a number." << std::endl;
			}
			else {
				std::cout << input_struct.date << " => " << input_struct.amount << " = " << this->_tradeValue(input_struct.date, input_struct.amount) << std::endl;
			}
		}
	}	
}

void BitcoinExchange::print_db(std::multimap<std::time_t, double> map)
{
	std::cout << "----------DATABASE DUMP----------" << std::endl;
	for (std::multimap<std::time_t, double>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
	std::cout << "----------------------------------" << std::endl;
}

std::multimap<std::time_t, double> BitcoinExchange::get_db()
{
	return(this->_db);
}

t_input BitcoinExchange::_create_inputStruct(std::string input)
{
	t_input		answer;
	std::istringstream	stream_line;
	std::string	date;
	std::string	amount;
	double		amount_fl;
	std::istringstream amount_stream;

	answer.is_firstline = false;
	stream_line.str(input);

	std::getline(stream_line, date, '|');
		if (date.empty())
			date = "";
	std::getline(stream_line, amount);
		if (amount.empty())
			amount = "";

	date = this->_trim(date);
	amount = this->_trim(amount);

	// if it's not an header line, we'll insert the first map value (we'll check later if it's invalid)
	if (date == "date" && amount == "value")
	{
		answer.is_firstline = true;
		return answer;
	}
		std::getline(stream_line, date, '|');
		std::getline(stream_line, amount);
		date = this->_trim(date);
		amount = this->_trim(amount);

		amount_stream.str(amount);
		amount_stream >> amount_fl;
		answer.date = date;
		answer.amount = amount_fl;
		return (answer);

}

std::time_t BitcoinExchange::_ymd_utime(std::string date)
{
	std::tm timeInfo = {};
	std::istringstream iss(date);
	std::string day, month, year;

	if (!std::getline(iss, year, '-') || !std::getline(iss, month, '-') || !std::getline(iss, day)) {
		std::cerr << "Error parsing date string: " << date << std::endl;
		return 0;
	}

	std::istringstream(day) >> timeInfo.tm_mday;
	std::istringstream(month) >> timeInfo.tm_mon;
	std::istringstream(year) >> timeInfo.tm_year;

	std::time_t timestamp = std::mktime(&timeInfo);
	if (timestamp == -1) {
		std::cerr << "Error converting date to timestamp: " << date << std::endl;
		return 0;
	}

	return timestamp;
}

bool BitcoinExchange::_isvalid_date(std::string date)
{
	int	leapyears[1000] = {1804, 1808, 1812, 1816, 1820, 1824, 1828, 1832, 1836, 1840, 1844, 1848, 1852, 1856, 1860, 1864, 1868, 1872, 1876, 1880, 1884, 1888, 1892, 1896, 1904, 1908, 1912, 1916, 1920, 1924, 1928, 1932, 1936, 1940, 1944, 1948, 1952, 1956, 1960, 1964, 1968, 1972, 1976, 1980, 1984, 1988, 1992, 1996, 2000, 2004, 2008, 2012, 2016, 2020, 2024, 2028, 2032, 2036, 2040, 2044, 2048, 2052, 2056, 2060, 2064, 2068, 2072, 2076, 2080, 2084, 2088, 2092, 2096 };
	int	thirthymonts[5] = {4, 6, 9, 11};
	std::tm timeInfo = {};
	std::istringstream iss(date);
	std::string day, month, year;

	getline(iss, year, '-');
	getline(iss, month, '-');
	getline(iss, day);
	std::istringstream(day) >> timeInfo.tm_mday;
	std::istringstream(month) >> timeInfo.tm_mon;
	std::istringstream(year) >> timeInfo.tm_year;

	if (timeInfo.tm_mday <= 0 || timeInfo.tm_mon <= 0 || timeInfo.tm_year <= 0)
		return false;
	for (int x = 0; leapyears[x]; x++)
	{
		if (timeInfo.tm_year == leapyears[x] && timeInfo.tm_mon == 2 && timeInfo.tm_mday >= 28)
			return (false);
		else if (timeInfo.tm_mon == 2 && timeInfo.tm_mday > 28)
			return (false);
	}
	for (int x = 0; thirthymonts[x]; x++)
	{
		if (timeInfo.tm_mon == thirthymonts[x] && timeInfo.tm_mday > 30)
			return (false);
	}
	if (timeInfo.tm_mon > 31)
		return (false);
	return(true);
}

bool BitcoinExchange::_ispositive_value(const double value)
{
	if (value < 0)
		return (false);
	return true;
}

bool BitcoinExchange::_value_isinrange(const double value)
{
	if (value > 1000)
		return (false);
	return true;
}

double BitcoinExchange::_tradeValue(const std::string date, const double amount)
{
	(void)date;
	(void)amount;
	double	closest = this->_find_closest(this->_ymd_utime(date));
//	std::cout << "RETOURNING CLOSEST * AMOUNT = " << closest << " " << amount << std::endl;
	return (closest * amount);
	//return 0;
}

// SUBJECTS STATES:
// If the date used in the input does not exist in your DB then you
// must use the closest date contained in your DB. Be careful to use the
// lower date and not the upper one.
// THEREFORE IT'S NOT THE MINOR HALF, BUT THE MINOR VALUE OF ANY UNMATCHED VALUE IN ANY GIVEN INTERVAL
double BitcoinExchange::_find_closest(const std::time_t time)
{
	std::map<std::time_t, double>::iterator	it = this->_db.begin();
	std::map<std::time_t, double>::iterator	next_it;

	while (it != this->_db.end())// && (this->_ut(time) - this->_ut(it->first)) >= 0)
	{
		next_it = it;
		++next_it;
		if (next_it == this->_db.end()
			|| (this->_ut(time) >= this->_ut(it->first) && this->_ut(time) < this->_ut(next_it->first)))
		{
			return (it->second);
		}
		it++;
	}
	if (it == this->_db.end())
		std::cout << "we looped until the end, but couldn't find a match" << std::endl;
	return (-1);
}

std::string BitcoinExchange::_trim(const std::string& str)
{
	std::string trimmed = str;
	size_t start = trimmed.find_first_not_of(" ");
	size_t end = trimmed.find_last_not_of(" ");

	if (start != std::string::npos && end != std::string::npos)
		trimmed = trimmed.substr(start, end - start + 1);
	else
		trimmed.clear();

	return trimmed;	
}

double BitcoinExchange::_ut(const std::time_t& time)
{
	return(static_cast<double>(time));
}
