/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:50:32 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/28 14:50:31 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 2)
    	ScalarConverter::convert(argv[1]);
    return (0);
}