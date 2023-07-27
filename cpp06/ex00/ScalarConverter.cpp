/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:50:28 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/27 18:29:33 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"
#include <ios>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <sys/types.h>

ScalarConverter::ScalarConverter(void)
{
    return ;
}

ScalarConverter::~ScalarConverter(void)
{
    return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
    *this = copy;
    return ;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
    static_cast<void>(copy);
    return (*this);
}

static bool onlyNumericFloat(const std::string tocheck, int *precision)
{
	int dotflag = 0;
	
    for (size_t i = 0; i < tocheck.size() - 1; i++)
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
            return (false);
        }
	}
	return (true);
}

static void throwImpossible(void)
{
	std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
    return ;
}

static void outChar(const char c)
{
	if (!(c >= 32 && c <= 126))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << c << "'" << std::endl;
}

static void convertChar(const std::string input)
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
	return ;
}

static void convertFloat(const std::string input)
{
	char c;
	int i;
	float f;
	double d;
	char *endPtr;
	int precision = 0;
	
	if (!onlyNumericFloat(input, &precision))
	{	
		throwImpossible();
		return ;
	}
	f = std::strtof(input.c_str(), &endPtr);
	if (input.c_str() == endPtr)
	{
		throwImpossible();
		return ;
	}
	c = static_cast<char>(f);
	i = static_cast<int>(f);
	d = static_cast<double>(f);
	if (f < 0 || f > 127)
		std::cout << "char: impossible" << std::endl;
	else
	{
		outChar(c);
	}
	std::cout << "int: " << i << std::endl;
	if (precision == 0)
		precision = 1;
	std::cout << std::fixed << std::setprecision(precision) << "float: " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(precision) << "double: " << d << std::endl;
	return ;
}

void    ScalarConverter::convert(std::string input)
{
	if (input.size() == 0)
	{
		throwImpossible();
		return ;
	}	
    if (input.size() == 1 && !(input >= "0" && input <= "9"))
    {
		convertChar(input);
        return ;
    }

    if (input[input.size() - 1] == 'f')
    {
		convertFloat(input);
        return ;
    }
}