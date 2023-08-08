/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:06:47 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/08 14:39:07 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <ostream>
#include <exception>

template <typename T>
class Array {
	private:
		T	*_array;
		unsigned int _size;
	public:
		Array(void);
		Array(unsigned int n);
		~Array(void);
		Array(const Array& copy);
		Array& operator=(const Array& copy);
		unsigned int size(void) const;

		T& operator[](const unsigned int index);
		
};

#endif