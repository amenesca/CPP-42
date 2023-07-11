/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:22 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/11 17:43:32 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

int main(void)
{
	// BASIC TEST
	try 
	{
		std::cout << std::endl <<"No error test.\n" << std::endl;
		Bureaucrat felix("felix", 10);
		std::cout << felix << std::endl;
		felix.decreaseGrade();
		std::cout << felix << std::endl;
		felix.increaseGrade();
		felix.increaseGrade();
		std::cout << felix << std::endl;	
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// TEST ERROR INCREASE GRADE
	try
	{
		std::cout << std::endl << "Increase error test.\n" << std::endl;
		Bureaucrat	jonas("jonas", 2);
		jonas.increaseGrade();
		std::cout << jonas << std::endl;
		jonas.increaseGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// TEST ERROR DECREASE GRADE
	try
	{
		std::cout << std::endl << "Decrease error test.\n" << std::endl;
		Bureaucrat miguel("miguel", 149);
		miguel.decreaseGrade();
		std::cout << miguel << std::endl;
		miguel.decreaseGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	// TEST CONSTRUCTOR GRADE TOO HIGH
	try
	{
		std::cout << "Constructor grade too high test.\n" << std::endl;
		Bureaucrat michelangelo("michelangelo", -2);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	// TEST CONSTRUCTOR GRADE TOO LOW
	try
	{
		std::cout << "Constructor grade too low test.\n" << std::endl;
		Bureaucrat marcelo("marcelo", 155);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}