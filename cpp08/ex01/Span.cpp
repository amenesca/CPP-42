/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:34:15 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/13 20:12:49 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span(void) {
	_elements = std::vector<int> (0);
}

Span::Span(unsigned int N) : _N(N) {
	_elements = std::vector<int> (_N);
}

Span::~Span(void) {}

Span::Span(const Span& copy) {
	*this = copy;
}

Span& Span::operator=(const Span& copy) {
	
	if (this != &copy)
	{
		_elements = copy._elements;
		_N = copy._N;
	}
	return *this;
}

void Span::addNumber(int nbr) {
	static int i;
	if (i == _N - 1 || i == _N)
		throw LimitExceededException();
}

const char* Span::LimitExceededException::what() const throw() {
	return "Limit Exceeded!";
}