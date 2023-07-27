/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:50:28 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/27 16:57:13 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"
#include <ios>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <cctype>

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

static bool onlyNumeric(std::string tocheck)
{
    for (size_t i = 0; i < tocheck.size() - 1; i++)
    {
        if (!std::isdigit(tocheck[i]))
        return (false);
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

static void convertChar(const char ch)
{
	char c;
    int i;
    float f;
    double d;
	c = ch;
	i = static_cast<int>(c);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	if (!(ch >= 32 && ch <= 126))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
	return ;
}

void    ScalarConverter::convert(std::string input)
{
    char c;
    int i;
    float f;
    double d;
    char* endPtr;
    
    if (input.size() == 1 && !(input >= "0" && input <= "9"))
    {
		convertChar(input[0]);
        return ;
    }

    if (input[input.size() - 1] == 'f')
    {
        if (!onlyNumeric(input))
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
        std::cout << "char: " << "'" << c << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
        return ;
    }
}