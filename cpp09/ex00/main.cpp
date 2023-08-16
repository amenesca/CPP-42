/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:16:56 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/16 15:31:53 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main()
{
	BitcoinExchange transactions;

	const bool deumerda1 = transactions.setData("./data.csv");
	if (deumerda1 == true)
		return (1);
	transactions.printData();
}