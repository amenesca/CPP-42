/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:16:27 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/22 16:14:18 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const std::map<std::string, float>& data)
{
	this->_data = data;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this == &copy)
        return *this;
	
	this->_data = copy.getData();
    return(*this);
}

std::map<std::string, float> BitcoinExchange::getData() const
{
	return (_data);
}

bool BitcoinExchange::setData(const std::string &filePath) {
	
	std::ifstream csvfile(filePath.c_str());
	
	if (!csvfile.is_open()) {
		std::cerr << "Error: cannot open data file" << std::endl;
		return (1);
	}
	std::string line;
	while (std::getline(csvfile, line))
	{
		std::string date, exchangeRate;
		size_t	commaPos;
		char *endPtr;
		float rate;

		commaPos = line.find(",");
		if (commaPos == std::string::npos || commaPos == 0 || commaPos >= line.length())
			continue ;
		date = line.substr(0 , 10);
		exchangeRate = line.substr(commaPos + 1);
		rate = std::strtof(exchangeRate.c_str(), &endPtr);
		if (endPtr == exchangeRate.c_str())
        	continue;
		_data[date] = rate;
	}
	csvfile.close();
	return (0); 
}

int* DateToInt(const std::string& date, int *error)
{
    size_t hyphen1 = date.find('-');
    size_t hyphen2 = date.find('-', hyphen1 + 1);
	int* intDate = new int[3];
	char *endPtr;

    if (hyphen1 == std::string::npos || hyphen2 == std::string::npos || hyphen1 != 4 || hyphen2 != 7)
	{
        std::cerr << "Error: invalid date format => " << date << std::endl;
		*error = 1;
		return intDate;
	}
    intDate[0] = std::strtol(date.substr(0, hyphen1).c_str(), &endPtr, 10);
	if (*endPtr != '\0')
	{
		std::cerr << "Error: invalid date => " << date << std::endl;
		*error = 1;
		return intDate;
	}
    intDate[1] = std::strtol(date.substr(hyphen1 + 1, hyphen2 - hyphen1 - 1).c_str(), &endPtr, 10);
	if (*endPtr != '\0')
	{
		std::cerr << "Error: invalid date => " << date << std::endl;
		*error = 1;
		return intDate;
	}
	intDate[2] = std::strtol(date.substr(hyphen2 + 1).c_str(), &endPtr, 10);
	if (*endPtr != '\0')
	{
		std::cerr << "Error: invalid date => " << date << std::endl;
		*error = 1;
		return intDate;
	}
	return intDate;
}

static int validateValue(const float& value)
{
	if (value < static_cast<float>(0))
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return -1;
	}
	if (value > static_cast<float>(1000))
	{
		std::cerr << "Error: too large a number." << std::endl;
		return -1;
	}
	return 1;
}

static int validateDate(const int* intDate, const std::string& date)
{
	int year = intDate[0];
    int month = intDate[1];
    int day = intDate[2];

    if (year < 2009 || (year == 2009 && month == 1 && day < 3)) {
        std::cerr << "Error: No data in that period => " << date << std::endl;
        return -1;
    }

    if (month < 1 || month > 12) {
        std::cerr << "Error: invalid date => " << date << std::endl;
        return -1;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30)) {
        std::cerr << "Error: invalid date => " << date << std::endl;
        return -1;
    }

    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

        if ((isLeapYear && (day < 1 || day > 29)) || (!isLeapYear && (day < 1 || day > 28))) {
            std::cerr << "Error: invalid date => " << date << std::endl;
            return -1;
        }
    }

    if ((month != 4 && month != 6 && month != 9 && month != 11) && (day < 1 || day > 31)) {
        std::cerr << "Error: invalid date => " << date << std::endl;
        return -1;
    }

    return 1;
}

void BitcoinExchange::doOperation(const std::string& date, const float& value) const
{
	float rate = (--this->_data.upper_bound(date))->second;
    std::cout << date << " => " << value << " = " << value * rate << std::endl;
}

static int testDate(const std::string& line)
{
	int error = 0;
	std::string date = line.substr(0, 10);
	int *intDate = DateToInt(date, &error);
	if (error == 1)
	{
		delete [] intDate;
		error = 0;
		return -1;
	}
	if (validateDate(intDate, line.substr(0, 10)) != 1)
	{
		delete [] intDate;
		return -1;
	}
	delete [] intDate;
	return 1;
}

static int testValue(const std::string& line, size_t pipePos, float* retValue)
{
	char *endPtr;
	float value = std::strtof(line.substr(pipePos + 2).c_str(), &endPtr);
	if (*endPtr == '\0' || (*endPtr == 'f' && *(endPtr + 1) == '\0'))
	{
		if (validateValue(value) != 1)
			return -1;
	}
	else {
		std::cerr << "Error: invalid value => " << line << std::endl;
		return -1;
	}
	*retValue = value;
	return 1;
}

void BitcoinExchange::initProgamm(const std::string& inputFile) const {

	std::ifstream inFile(inputFile.c_str());
	if (!inFile.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	int i = 1;

	std::string line;
	while (getline(inFile, line))
	{
		if (i == 1 && line == "date | value") {
			i++;
			continue ;
		}

		size_t pipePos;
		pipePos = line.find("|");
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		
		if (testDate(line) != 1)
			continue;
		
		float value;
		if (testValue(line, pipePos, &value) != 1)
			continue;
		
		doOperation(line.substr(0, 10), value);
	}
	
	inFile.close();
}