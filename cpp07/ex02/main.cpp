/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:16:05 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/10 12:43:48 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void) {
	Array<int>	array(5);

	array[0] = 1;

	try {
		array[6] = 1;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		for (unsigned int i = 0; i < 10; i++) {
			std::cout << array[i] << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	Array<int> tabela(array);
	try {
		for (unsigned int i = 0; i < 10; i++) {
			std::cout << tabela[i] << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	tabela[0] = 2000;
	
	std::cout << array[0] << std::endl;
	std::cout << tabela[0] << std::endl;

	Array<int> testeleak(10);
	tabela = testeleak;
}