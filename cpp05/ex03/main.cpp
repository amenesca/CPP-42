/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:01:57 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/21 13:47:37 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <exception>
#include <iostream>

int main(void) {
	try {
		Intern estagiario;
		AForm *shrubbery = estagiario.makeForm("shrubbery creation", "Deorum");
		AForm *robotomy = estagiario.makeForm("robotomy request", "Deorum");
		AForm *pardon = estagiario.makeForm("presidential pardon", "Deorum");
		std::cout << std::endl;
		Bureaucrat Alan("Alan", 1);
		Alan.signForm(*shrubbery);
		Alan.executeForm(*shrubbery);
		std::cout << std::endl;
		Alan.signForm(*robotomy);
		Alan.executeForm(*robotomy);
		std::cout << std::endl;
		Alan.signForm(*pardon);
		Alan.executeForm(*pardon);
		std::cout << std::endl;
		delete shrubbery;
		delete robotomy;
		delete pardon;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
		try {
		Intern estagiario;
		AForm *shrubbery = estagiario.makeForm("form form", "Deorum");
		(void)shrubbery;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}