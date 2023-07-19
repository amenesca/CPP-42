/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:01:57 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/19 19:32:25 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
	// No erro test
	Bureaucrat	jotaro("Jotaro", 10);
	Bureaucrat	dio("Dio", 10);
	Form		noUse("Useless form", 9, 9);
	Form		oraOra("Ora Ora form", 10, 10);

	std::cout << std::endl;
	try {
		Form tooHighForm("High Form", 0,0);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;		
	}
	std::cout << std::endl;
	try {
		Form tooLowForm("Low Form", 151, 151);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << oraOra << std::endl;
		jotaro.signForm(oraOra);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		dio.signForm(noUse);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}