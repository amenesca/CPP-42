/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:30:06 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/08 11:35:35 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) {
	_array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) {
	_array = new T[n];
}

template <typename T>
Array<T>::~Array(void) {
	delete[] _array;
}

template <typename T>
Array<T>::size()  {
	unsigned int i = 0;
	while (_array[i++] != 0) {}
	return (i);
}

#endif