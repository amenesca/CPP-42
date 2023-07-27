/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:50:28 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/26 18:25:12 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"
#include <ios>
#include <iostream>
#include <cstring>
#include <iomanip>

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

void    ScalarConverter::convert(std::string input)
{
    char c;
    int i;
    float f;
    double d;
    
    if (input.size() == 1 && !(input >= "0" && input <= "9")\
     && (input[0] >= 33 && input [0] <= 126))
    {
        c = static_cast<char>(input[0]);
        i = static_cast<int>(c);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        std::cout << "char: " << c << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
        return;
    }
}