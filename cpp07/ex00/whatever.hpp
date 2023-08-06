/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:42:27 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/06 19:21:30 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template< typename T >
T	max( const T& x, const T& y ) {
	if (x > y)
		return x;
	else
		return y;
}

template< typename T>
T	min( const T& x, const T& y ) {
	if (x < y)
		return x;
	else
		return y;
}

template< typename T >
void	swap( T& x, T& y )
{
	T	aux;
	aux = x;
	x = y;
	y = aux;
}

#endif
