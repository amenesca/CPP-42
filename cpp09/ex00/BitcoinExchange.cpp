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

/* TEST FUNCTION ***
void	BitcoinExchange::printData(void)
{
	for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); it++)
	{
		std::cout << it->first << " " << std::fixed << std::setprecision(2) << it->second << std::endl;
	}
}*/