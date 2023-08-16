/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:16:27 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/16 15:45:09 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

bool BitcoinExchange::setData(const std::string &filePath) {
	
	std::ifstream csvfile(filePath.c_str());
	
	if (!csvfile.is_open()) {
		std::cout << "Deu ruim para abrir" << std::endl;
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