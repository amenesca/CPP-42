/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:16:27 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/17 11:56:04 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool BitcoinExchange::setData(const std::string &filePath) {
	
	std::ifstream csvfile(filePath.c_str());
	
	if (!csvfile.is_open()) {
		std::cerr << "Error cannot open file" << std::endl;
		return (1);
	}
	std::string line;
	while (std::getline(csvfile, line))
	{
		std::string date, exchangeRate;
		size_t	commaPos;
		char *endPtr;
		double rate;

		commaPos = line.find(",");
		if (commaPos == std::string::npos || commaPos == 0 || commaPos >= line.length())
			continue ;
		date = line.substr(0 , 10);
		exchangeRate = line.substr(commaPos + 1);
		rate = std::strtod(exchangeRate.c_str(), &endPtr);
		if (endPtr == exchangeRate.c_str())
        	continue;
		_data[date] = rate;
	}
	csvfile.close();
	return (0); 
}

bool	BitcoinExchange::setInput(const std::string& inputFile) {
	std::ifstream infile(inputFile.c_str());
	
	if (!infile.is_open()) {
		std::cerr << "Error cannot open file" << std::endl;
		return (1);
	}
	
	std::string line;
	while (std::getline(infile, line))
	{
		std::string date, exchangeRate;
		size_t	divPos;
		char *endPtr;
		double rate;

		divPos = line.find("|");
		if (divPos == std::string::npos || divPos == 0 || divPos >= line.length())
			continue ;
		date = line.substr(0 , 10);
		exchangeRate = line.substr(divPos + 1);
		rate = std::strtod(exchangeRate.c_str(), &endPtr);
		if (endPtr == exchangeRate.c_str())
        	continue;
		_input[date] = rate;
	}
	infile.close();
	return (0);
}

static bool validateInput(const std::string date, const int value) {


}

void BitcoinExchange::doOperation(void) {

	std::map<std::string, double>::const_iterator inputIt;

	for (inputIt = _input.begin; inputIt < _input.end(); inputIt++)
	{
		
	}
}

// TEST FUNCTION ***
void	BitcoinExchange::printData(void)
{
	for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); it++)
	{
		std::cout << it->first << " " << std::fixed << std::setprecision(2) << it->second << std::endl;
	}
}

// TEST FUNCTION ***
void	BitcoinExchange::printInput(void)
{
	for (std::map<std::string, double>::iterator it = _input.begin(); it != _input.end(); it++)
	{
		std::cout << it->first << " " << std::fixed << std::setprecision(2) << it->second << std::endl;
	}
}