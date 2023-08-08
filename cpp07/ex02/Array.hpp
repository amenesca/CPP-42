/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:06:47 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/08 11:34:27 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
	private:
		T	*_array;
	public:
		Array(void);
		Array(unsigned int n);
		~Array(void);
//		Array(const Array& copy);
//		Array& operator=(const Array& copy);
		unsigned int size(void);
};

#endif