/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:50:32 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/31 08:41:28 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 2)
    	ScalarConverter::convert(argv[1]);
	else
		std::cerr << "Error: Bad argument" << std::endl; 
    return (0);
}

/*int main(void)
{
    ScalarConverter::convert("\n");
    return (0);
}
*/