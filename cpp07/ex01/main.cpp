/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:37:12 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/07 11:55:42 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	sum2(int &arg)
{
	arg+=2;
}

void printarg(std::string &arg)
{
	std::cout << arg << std::endl;
}

int main(void)
{
	int arg[5] = {1,2,3,4,5};
	std::string arg2[3] = {"OI", "TUDO", "BEM?"};

	iter(arg, 5, sum2);
	for (int i = 0; i < 5; i++)
		std::cout << arg[i] << std::endl;

	iter(arg2, 3, printarg);
}