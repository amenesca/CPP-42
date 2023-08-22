/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:16:27 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/22 12:21:55 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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
        std::cerr << "Error: invalid date format." << std::endl;
		*error = 1;
		return intDate;
	}
    intDate[0] = std::strtol(date.substr(0, hyphen1).c_str(), &endPtr, 10);
	if (*endPtr != '\0')
	{
		std::cerr << "Error: invalid date." << std::endl;
		*error = 1;
		return intDate;
	}
    intDate[1] = std::strtol(date.substr(hyphen1 + 1, hyphen2 - hyphen1 - 1).c_str(), &endPtr, 10);
	if (*endPtr != '\0')
	{
		std::cerr << "Error: invalid date." << std::endl;
		*error = 1;
		return intDate;
	}
	intDate[2] = std::strtol(date.substr(hyphen2 + 1).c_str(), &endPtr, 10);
	if (*endPtr != '\0')
	{
		std::cerr << "Error: invalid date." << std::endl;
		*error = 1;
		return intDate;
	}

//	std::cout << "Ano: " << intDate[0] << ", Mês: " << intDate[1] << ", Dia: " << intDate[2] << std::endl;
	return intDate;
}

static int validateValue(const float& value)
{
	if (value < static_cast<float>(0))
	{
		std::cerr << "Error: not a positive number." << std::endl;

	}
	if (value > static_cast<float>(1000))
	{
		std::cerr << "Error: too large a number." << std::endl;
		return -1;
	}
	return 1;
}

/*static void doOperation(void)
{
	
}*/

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
			i = 0;
			continue ;
		}

		
		size_t pipePos;
		pipePos = line.find("|");
		if (pipePos == std::string::npos || pipePos != 11 || line.size() < 14)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		
		
		int error = 0;
		int *intDate = DateToInt(line.substr(0, 10), &error);
		if (error == 1)
		{
			delete [] intDate;
			error = 0;
			continue;
		}
//		validateDate(intDate);
		
		char *endPtr;
		float value = std::strtof(line.substr(pipePos + 2).c_str(), &endPtr);
		if (*endPtr == '\0' || (*endPtr == 'f' && *(endPtr + 1) == '\0'))
		{
			if (validateValue(value) == -1)
				continue ;
		}
		else {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		
//		doOperation();

		
		delete [] intDate;
	}
	
	inFile.close();
}

// TEST FUNCTION ***
void	BitcoinExchange::printData(void)
{
	for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++)
	{
		std::cout << it->first << " " << std::fixed << std::setprecision(2) << it->second << std::endl;
	}
}