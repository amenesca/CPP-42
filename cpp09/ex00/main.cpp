/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:16:56 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/17 11:55:31 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	BitcoinExchange transactions;

	if (argc == 2)
	{
		const bool testError = transactions.setData("./data.csv");
		if (testError == true)
			return 1;

		const bool testError2 = transactions.setInput(argv[1]);
		if (testError2 == true)
			return 2;
		//transactions.printData();// TEST FUNCTION ***
		transactions.printInput();// TEST FUNCTION ***
	}
	else {
		std::cerr << "Missing input file" << std::endl;
		return 3;
	}
	return 0;
}