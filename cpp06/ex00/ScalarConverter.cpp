/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:50:28 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/30 19:27:37 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"
#include <climits>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <ostream>

ScalarConverter::ScalarConverter(void)
{
	return;
}

ScalarConverter::~ScalarConverter(void)
{
	return;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
	return;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	static_cast<void>(copy);
	return *this;
}

static int countPrecision(const std::string& tocheck)
{
	int dotflag = 0;
	int precision = 0;
	
	for (size_t i = 0; i < tocheck.size(); i++)
	{
		if (tocheck[i] == '.')
		{
			if (dotflag == 1)
				return false;
			dotflag = 1;
			continue;
        }
		if (dotflag == 1)
			precision = precision + 1;
	}
	return precision;
}

void convertDouble(const std::string input)
{
	char c = '\0';
	int i = 0;
	float f = 0;
	double d = 0;
	char *endPtr;
	int precision;

	d = std::strtod(input.c_str(), &endPtr);
	if (d < 0 || d > 127)
		std::cout << "char: Impossible" << std::endl;
	else if (d >= 32 && d <= 126) {
		c = static_cast<char>(d);
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else {
		std::cout << "char: Non displayable" << std::endl;
	}
	if (d < INT_MIN || d > INT_MAX)
		std::cout << "int: Impossible" << std::endl;
	else {
		i = static_cast<int>(d);
		std::cout << "int: " << i << std::endl;
	}
	f = static_cast<float>(d);
	precision = countPrecision(input);
	if (precision == 0)
		precision = 1;
	std::cout << std::fixed << std::setprecision(precision) << "float: " << f << "f"<< std::endl;
	std::cout << std::fixed << std::setprecision(precision) << "double: " << d << std::endl;
	return ;
}

void    ScalarConverter::convert(const std::string& input)
{
//	float f;
	double intLimit;
	char *endPtr;

	intLimit = std::strtod(input.c_str(), &endPtr);
	
	if ((intLimit < INT_MIN || intLimit > INT_MAX) && *endPtr == '\0')
		return convertDouble(input);
/*	else
		return convertInt(input);
	
	f = std::strtof(input.c_str(), &endPtr);
	if (*endPtr == 'f' && *(endPtr + 1) == '\0')
		return convertFloat(f);*/

	return;
}