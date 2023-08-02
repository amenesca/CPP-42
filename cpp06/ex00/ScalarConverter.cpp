/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:50:28 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/02 11:08:26 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"

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
	int i = -1;
	int precision = 0;
	
	while (tocheck[++i] != '\0')
	{
		if (tocheck[i] == '.')
		{
			dotflag = 1;
			continue;
        }
		if (dotflag == 1 && tocheck[i] != 'f')
			precision++;
	}
	return precision;
}

void convertDouble(const double& d,const std::string input)
{
	char c = '\0';
	int i = 0;
	float f = 0;
	int precision;

	if (d < 0 || d > 127)
		std::cout << "char: Impossible" << std::endl;
	else if (d >= 32 && d <= 126) {
		c = static_cast<char>(d);
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else if (input == "+nan" || input == "-nan" || input == "nan")
		std::cout << "int: Impossible" << std::endl;
	else {
		std::cout << "char: Non displayable" << std::endl;
	}
	if (d < INT_MIN || d > INT_MAX)
		std::cout << "int: Impossible" << std::endl;
	else if (input == "+nan" || input == "-nan" || input == "nan")
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

void convertInt(const int& i)
{
	char c = '\0';
	float f = 0;
	double d = 0;
	int precision = 1;

	if (i < 0 || i > 127)
		std::cout << "char: Impossible" << std::endl;
	else if (i >= 32 && i <= 126) {
		c = static_cast<char>(i);
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else {
		std::cout << "char: Non displayable" << std::endl;
	}
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(precision) << "float: " << f << "f"<< std::endl;
	std::cout << std::fixed << std::setprecision(precision) << "double: " << d << std::endl;
	return ;
}

void convertFloat(const float& f, const std::string& input)
{
	char c = '\0';
	int i = 0;
	double d = 0;
	int precision;
	
	if (f < 0 || f > 127)
		std::cout << "char: Impossible" << std::endl;
	else if (f >= 32 && f <= 126) {
		c = static_cast<char>(f);
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else if (input == "+nanf" || input == "-nanf" || input == "nanf")
		std::cout << "char: Impossible" << std::endl;
	else {
		std::cout << "char: Non displayable" << std::endl;
	}
	d = static_cast<double>(f);
	if (d < INT_MIN || d > INT_MAX)
		std::cout << "int: Impossible" << std::endl;
	else if (input == "+nanf" || input == "-nanf" || input == "nanf")
		std::cout << "int: Impossible" << std::endl;
	else {
		i = static_cast<int>(f);
		std::cout << "int: " << i << std::endl;
	}
	precision = countPrecision(input);
	if (precision == 0)
		precision = 1;
	std::cout << std::fixed << std::setprecision(precision) << "float: " << f << "f"<< std::endl;
	std::cout << std::fixed << std::setprecision(precision) << "double: " << d << std::endl;
	return ;
}

void convertChar(const std::string& input)
{
	char c;
	int i;
	float f;
	double d;

	c = input[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	
	if (f >= 32 && f <= 126)
	{
		c = static_cast<char>(f);
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else 
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;			
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f"<< std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}

void    ScalarConverter::convert(const std::string& input)
{
	float f;
	int i;
	double d;
	char *endPtr;
	
	d = std::strtod(input.c_str(), &endPtr);
	if ((d < INT_MIN || d > INT_MAX) && *endPtr == '\0')
		return convertDouble(d, input);
	i = std::strtol(input.c_str(), &endPtr, 10);
	if (*endPtr == '\0')
		return convertInt(i);	
	f = std::strtof(input.c_str(), &endPtr);
	if (*endPtr == 'f' && *(endPtr + 1) == '\0')
		return convertFloat(f, input);
	d = std::strtod(input.c_str(), &endPtr);
	if (*endPtr == '\0')
		return convertDouble(d, input);
	if (!(input[0] >= '0' && input[0] <= '9') && input[1] == '\0')
		return convertChar(input);
	
	std::cerr << "Error: Bad Input" << std::endl;
	return ;
}