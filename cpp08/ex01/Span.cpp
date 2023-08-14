/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:34:15 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/14 15:02:43 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

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
	static unsigned int i;
	if (i >= _N)
		throw LimitExceededException();
	else
	{
		_elements.push_back(nbr);
		i++;
	}
}

int Span::longestSpan(void) {
	if (_N <= 1)
		throw NoSpanCanBeFound();
	std::vector<int>::iterator min_element = std::min_element(_elements.begin(), _elements.end());
	std::vector<int>::iterator max_element = std::max_element(_elements.begin(), _elements.end());
	return (*max_element - *min_element);
}

int Span::shortestSpan(void) {
	if (_N <= 1)
		throw NoSpanCanBeFound();
	std::vector<int> compare = _elements;
	std::sort(compare.begin(), compare.end());

	int minSpan = std::numeric_limits<int>::max();
	for (std::vector<int>::iterator it = compare.begin()++;
	 it != compare.end(); ++it)
	{
		int span = std::abs(*it - *(it - 1));
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

const char* Span::LimitExceededException::what() const throw() {
	return "Exception: Limit Exceeded!";
}

const char* Span::NoSpanCanBeFound::what() const throw() {
	return "Exception: Insufficient amount of elements to calculate span";
}