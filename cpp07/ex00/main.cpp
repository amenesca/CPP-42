/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:05:00 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/06 19:30:53 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main( void )
{
	int a = 2;
	int b = 3;
	
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "swap( a, b )" << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "swap( c, d )" << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl << std::endl;

	float x = 2;
	float y = 3;
	
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "swap( x, y )" << std::endl;
	::swap( x, y );
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl;
	std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl << std::endl;
	
	double z = 4.2;
	double n = 2.5;
	
	std::cout << "z = " << z << ", n = " << n << std::endl;
	std::cout << "swap( z, n )" << std::endl;
	::swap(z, n);
	std::cout << "z = " << z << ", n = " << n << std::endl;
	std::cout << "min( z, n ) = " << ::min( z, n ) << std::endl;
	std::cout << "max( z, n ) = " << ::max( z, n ) << std::endl;

	return 0;
}