/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:33:51 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/15 18:59:12 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

class Span {
	private:
		unsigned int _N;
		std::vector<int> _elements;
	public:
		Span(void);
		~Span(void);
		Span(unsigned int N);
		Span(const Span& copy);

		Span& operator=(const Span& copy);
		
		void addNumber(int nbr);
		long int longestSpan(void) const;
		long int shortestSpan(void)const;
		void	fillElements( std::vector<int>::iterator begin, std::vector<int>::iterator end);
		class LimitExceededException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
				class NoSpanCanBeFound : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
};

#endif