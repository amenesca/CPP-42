/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:46:45 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/23 11:17:44 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	RPN rpn;
	if (argc == 2)
	{
		rpn.Operation(argv[1]);
	}
	else
	{
		std::cerr << "Error: Invalid arguments." << std::endl;
		return 1;
	}
	return 0;
}