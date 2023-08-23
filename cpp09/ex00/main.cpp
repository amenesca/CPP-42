/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:16:56 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/23 14:16:51 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	BitcoinExchange transactions;

	if (argc == 2)
		transactions.initProgamm(argv[1]);
	else {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	return 0;
}