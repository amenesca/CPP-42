/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:03:02 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/20 22:19:06 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(void)\
 : AForm("Robotomy Request Form", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)\
 : AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm assignment constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)\
 : AForm("Robotomy Request Form", 72, 45), _target(src._target)
{
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
	(void)obj;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
std::rand() para gerar um número aleatório entre 0 e RAND_MAX,\
 que é uma constante definida na biblioteca <cstdlib>.\
  Ao dividir esse número por RAND_MAX + 1, obtemos um valor entre 0 e 1.

Se o valor gerado for menor do que a probabilidade de sucesso \
(definida como 0.5, ou 50%), a condição será verdadeira e você imprimirá "Sucesso!".\
 Caso contrário, a condição será falsa e você imprimirá "Fracasso!".
*/

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->AForm::executeCheck(executor);
	std::srand(std::time(0));
	double chance = (double)((std::rand()) / (RAND_MAX + (double)1));
	double probability = 0.5;

	if (chance > probability) {
		std::cout << "We inform that " << _target << " has been robotomized." << std::endl;
	} else {
		std::cout << "We inform that unfortunately robotomy failed." << std::endl;
	}
}