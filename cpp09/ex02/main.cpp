/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:48:45 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/24 11:55:09 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
	PmergeMe orderAndProgess;
	
	if (argc > 1) {
		orderAndProgess.doOperation(argc, argv);	
	} else {
		std::cerr << "Error: insuficient input quantity" << std::endl;
	}
}