/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:03:02 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/21 15:56:09 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(void)\
 : AForm("RobotomyRequestForm", 72, 45)
{
 return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)\
 : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)\
 : AForm("RobotomyRequestForm", 72, 45), _target(src._target)
{
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
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