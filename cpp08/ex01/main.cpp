/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:34:09 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/15 19:25:49 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <limits>

int randInt(void) {
    int random_int = (rand() % 100001) - 50000;
    return random_int;
}

int main()
{
	Span int_vector(10);

	try {
		std::cout << "TEST - Trying to get span of an empty container" << std::endl;
			int_vector.longestSpan();
	} catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	int_vector.addNumber(26);
	int_vector.addNumber(8);
	int_vector.addNumber(5);
	int_vector.addNumber(28);
	int_vector.addNumber(31);
	int_vector.addNumber(20);
	int_vector.addNumber(15);
	int_vector.addNumber(12);
	int_vector.addNumber(40);
	int_vector.addNumber(35);
	
	std::cout << std::endl;
	try {
		std::cout << "TEST - Trying to add more elements than the limit" << std::endl;
		int_vector.addNumber(5);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "TEST - Everythin is ok!" << std::endl;	
	std::cout << "Longest Span in int_vector is: " << int_vector.longestSpan() << std::endl;
	std::cout << "Shortest Span in int_vector is: " <<int_vector.shortestSpan() << std::endl;
	
	std::cout << std::endl;
	std::cout << "TEST - 10000 Elements" << std::endl;
	srand(time(0));
	Span Span_vector(10000);
	std::vector<int> freedom(10000, 0);
	for (size_t i = 0; i < freedom.size(); i++)
		freedom[i] = randInt();
	Span_vector.fillElements(freedom.begin(), freedom.end());
	std::cout << "Longest Span in Span_vector is: " << Span_vector.longestSpan() << std::endl;
	std::cout << "Shortest Span in Span_vector is: " << Span_vector.shortestSpan() << std::endl;
}