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
#include "PresidentialPardonForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"

int main(void) {
	//test no error
	try {
	ShrubberyCreationForm plant_tree("Alan");
	PresidentialPardonForm pardon("Alan");
	RobotomyRequestForm gpt("Alan");
	Bureaucrat alan("Alan", 1);
	
	std::cout << std::endl;
	alan.signForm(plant_tree);
	alan.signForm(pardon);
	alan.signForm(gpt);
	std::cout << std::endl;
	alan.executeForm(plant_tree);
	std::cout << std::endl;
	alan.executeForm(pardon);
	std::cout << std::endl;
	alan.executeForm(gpt);
	std::cout << std::endl;
	std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	//test execute not signed
	try {
		PresidentialPardonForm forgives("Fernando");
		Bureaucrat fabricio("Fabricio", 26);

		fabricio.signForm(forgives);
		fabricio.executeForm(forgives);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		ShrubberyCreationForm tree("Fernando");
		Bureaucrat fabricio("Fabricio", 150);

		fabricio.signForm(tree);
		fabricio.executeForm(tree);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		RobotomyRequestForm robotomy("Fernando");
		Bureaucrat fabricio("Fabricio", 100);

		fabricio.signForm(robotomy);
		fabricio.executeForm(robotomy);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}