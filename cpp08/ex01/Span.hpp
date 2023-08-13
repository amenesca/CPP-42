/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:33:51 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/13 20:11:33 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

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
		
		class LimitExceededException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		void addNumber(int nbr);
};

#endif