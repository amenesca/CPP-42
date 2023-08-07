/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:06:47 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/07 15:27:43 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
class Array {
	private:
		T	*_array;
	public:
		Array(void) {
			_array = new T[0];
		}
		Array(unsigned int n) {
			_array = new T[n];
		}
		~Array(void) {
			delete[] _array;
		}
//		Array(const Array& copy);
//		Array& operator=(const Array& copy);
		unsigned int size(void) {
			unsigned int i = 0;
			while (this->_array[i++] != 0)
			return (i);
		}
};

#endif