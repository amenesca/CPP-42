/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:02:52 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/21 13:43:16 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

class AForm;
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(void)\
 : AForm("Presidential Pardon Form", 25, 5)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)\
 : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)\
 : AForm("Presidential Pardon Form", 25, 5), _target(src._target)
{
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &obj)
{
	(void)obj;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->AForm::executeCheck(executor);
	std::cout << "We came to inform that " << _target\
	 << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}