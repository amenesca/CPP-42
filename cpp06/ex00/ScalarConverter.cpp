/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:50:28 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/28 15:30:20 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>

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

static bool isNbr(const std::string& tocheck, int* precision)
{
	int dotflag = 0;

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
			*precision = *precision + 1;
		if (!std::isdigit(tocheck[i]))
		{
			return false;
		}
	}
	return true;
}

static bool onlyNumeric(const std::string& tocheck)
{
	for (size_t i = 0; i < tocheck.size(); i++) {
		if (!std::isdigit(tocheck[i]))
			return false;
	}
	return true;
}

static void throwImpossible(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
	return;
}

static void outChar(const char c)
{
	if (!(c >= 32 && c <= 126))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << c << "'" << std::endl;
	return;
}

static bool hasDot(const std::string& tocheck)
{
	int dot = 0;

	for (size_t i = 0; i < tocheck.size(); i++)
	{
		if (tocheck[i] == '.')
		{
			if (dot == 1)
				return false;
			dot = 1;
		}
	}
	if (dot == 1)
		return true;
	else
		return false;
}

static void convertChar(const std::string& input)
{
	char c;
	int i;
	float f;
	double d;
	c = input[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	outChar(c);
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
	return;
}

static void convertInf(const std::string& input)
{
	char c;
	int i;
	float f;
	double d;
	
	if (input == "inf" || input == "+inf")
	{
		d = std::numeric_limits<double>::infinity();
		f = static_cast<float>(d);
		c = static_cast<char>(d);
		i = static_cast<int>(d);
	}
	else if(input == "-inf")
	{
		d = -std::numeric_limits<double>::infinity();
		f = static_cast<float>(d);
		c = static_cast<char>(d);
		i = static_cast<int>(d);
	}
	else if (input == "inff" || input == "+inff")
	{		
		f = std::numeric_limits<double>::infinity();
		d = static_cast<double>(f);
		c = static_cast<char>(f);
		i = static_cast<int>(f);
	}
	else if (input == "-inff")
	{
		f = -std::numeric_limits<double>::infinity();
		d = static_cast<double>(f);
		c = static_cast<char>(f);
		i = static_cast<int>(f);
	}
	outChar(c);
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

static void convertFloat(const std::string& input)
{
	char c;
	int i;
	float f;
	double d;
	char *endPtr;
	int precision = 0;
	std::string tocheck = input;
	
	tocheck.erase(tocheck.size() - 1, 1);
	if (!isNbr(tocheck, &precision))
	{	
		throwImpossible();
		return;
	}
	f = std::strtof(input.c_str(), &endPtr);
	if (input.c_str() == endPtr)
	{
		throwImpossible();
		return;
	}
	c = static_cast<char>(f);
	i = static_cast<int>(f);
	d = static_cast<double>(f);
	outChar(c);
	std::cout << "int: " << i << std::endl;
	if (precision == 0)
		precision = 1;
	std::cout << std::fixed << std::setprecision(precision) << "float: " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(precision) << "double: " << d << std::endl;
	return;
}

static void convertDouble(const std::string& input)
{
	char c;
	int i;
	float f;
	double d;
	char *endPtr;
	int precision = 0;

	if (!(isNbr(input, &precision)))
	{
		throwImpossible();
		return;
	}
	d = std::strtod(input.c_str(), &endPtr);
	if (input.c_str() == endPtr)
	{
		throwImpossible();
		return;
	}
	c = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<float>(d);
	outChar(c);
	std::cout << "int: " << i << std::endl;
	if (precision == 0)
		precision = 1;
	std::cout << std::fixed << std::setprecision(precision) << "float: " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(precision) << "double: " << d << std::endl;
}

void	convertInt(const std::string& input)
{
	char c;
	int i;
	float f;
	double d;
	char *endPtr;

	i = std::strtol(input.c_str(), &endPtr, 10);
	if (input.c_str() == endPtr)
	{
		throwImpossible();
		return;
	}
	c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	outChar(c);
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}

void    ScalarConverter::convert(const std::string& input)
{
	if (input.size() == 0)
	{
		throwImpossible();
		return;
	}
	if (input.size() == 1 && !(input >= "0" && input <= "9"))
	{
		convertChar(input);
		return;
	}
	else if(input == "inf" || input == "+inf" || input == "-inf"\
	 || input == "inff" || input == "+inff" || input == "-inff")
	{
		convertInf(input);
		return;
	}
	else if (input[input.size() - 1] == 'f')
	{
		convertFloat(input);
		return;
	}
	else if (hasDot(input))
	{
		convertDouble(input);
		return;
	}
	else if (onlyNumeric(input))
	{
		convertInt(input);
		return;
	}
	throwImpossible();
	return;
}