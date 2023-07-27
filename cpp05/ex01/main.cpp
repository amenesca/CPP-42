/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:01:57 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/26 14:53:19 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
	Bureaucrat	jotaro("Jotaro", 10);
	Bureaucrat	dio("Dio", 10);
	Form		noUse("Useless form", 9, 9);
	Form		oraOra("Ora Ora form", 10, 10);

	std::cout << std::endl;
	std::cout << "Error test: too high form.\n";
	try {
		Form tooHighForm("High Form", 0,0);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;		
	}
	std::cout << std::endl;
	std::cout << "Error test: too low form.\n";
	try {
		Form tooLowForm("Low Form", 151, 151);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Error test: no error test.\n";
	try {
		std::cout << oraOra << std::endl;
		jotaro.signForm(oraOra);
		std::cout << oraOra << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Error test: Insuficient grade to sign.\n";
	try {
		std::cout << noUse << std::endl;
		dio.signForm(noUse);
		std::cout << noUse << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	return (0);
}