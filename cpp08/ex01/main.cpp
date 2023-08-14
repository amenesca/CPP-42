/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:34:09 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/13 22:28:31 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <iostream>

int main()
{
	Span int_vector(10);
	int_vector.addNumber(26);
	int_vector.addNumber(8);
	int_vector.addNumber(5);
	int_vector.addNumber(28);
	int_vector.addNumber(31);
	int_vector.addNumber(20);
	int_vector.addNumber(7);
	int_vector.addNumber(12);
	int_vector.addNumber(40);
	int_vector.addNumber(30);
	
	try {
		int_vector.addNumber(5);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << int_vector.longestSpan() << std::endl;
	std::cout << int_vector.shortestSpan() << std::endl;
}