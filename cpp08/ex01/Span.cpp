/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:34:15 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/15 19:02:13 by amenesca         ###   ########.fr       */
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
	if (_elements.size() >= _N)
		throw LimitExceededException();
	else
		_elements.push_back(nbr);
}

long int Span::longestSpan(void) const {
	if (_elements.size() <= 1)
		throw NoSpanCanBeFound();
	long int min_element = *std::min_element(_elements.begin(), _elements.end());
	long int max_element = *std::max_element(_elements.begin(), _elements.end());
	return (max_element - min_element);
}

long int Span::shortestSpan(void) const{
	if (_elements.size() <= 1)
		throw NoSpanCanBeFound();
	std::vector<int> compare = _elements;
	std::sort(compare.begin(), compare.end());

	long int minSpan = static_cast<long int>(std::numeric_limits<int>::max()) - static_cast<long int>(std::numeric_limits<int>::min()) + 1;
	for (std::vector<int>::const_iterator it = compare.begin()++;
	 it != compare.end(); ++it)
	{
		long int span = std::abs(*it - *(it - 1));
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

void	Span::fillElements( std::vector<int>::iterator begin, std::vector<int>::iterator end )
{
	if (_elements.size() + std::distance(begin, end) > _N)
		throw LimitExceededException();
	_elements.insert(_elements.end(), begin, end);
}

const char* Span::LimitExceededException::what() const throw() {
	return "Exception: Limit of elements exceeded!";
}

const char* Span::NoSpanCanBeFound::what() const throw() {
	return "Exception: Insufficient amount of elements to calculate span";
}