/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:34:30 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/29 19:58:27 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{ 
	Data* data1 = new Data;
	uintptr_t ptr;
	Data* data2;
	

	data1->c = 'c';
	data1->nbr = 1;
	data1->nbr2 = 2.2;

	ptr = Serializer::serialize(data1);
	data2 = Serializer::deserialize(ptr);
	std::cout << data2->nbr2 << std::endl;

	data2->nbr2 = 4.5;

	std::cout << data1->nbr2 << std::endl;
	
	delete data1;
}