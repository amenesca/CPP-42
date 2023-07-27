/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:48:18 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/26 14:53:11 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	return ;
}

Intern::Intern(const Intern &intern)
{
	*this = intern;
	return ;
}

Intern::~Intern(void)
{
	return ;
}

Intern	&Intern::operator=(const Intern &intern)
{
	(void)intern;
	return (*this);
}

static AForm	*newShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*newRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*newPresidential(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string formName, const std::string target) const
{
	ConstructorPtr constructorPtr[3] = {&newShrubbery, &newPresidential, &newRobotomy};
	std::string		formNames[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	AForm *formPtr = NULL;
	int i = 0;

	while (i < 3)
	{
		if (formName == formNames[i])
		{
			formPtr = constructorPtr[i](target);
			std::cout << "Intern created " << formPtr->getName() << " form." << std::endl;
			return (formPtr);
			break ;
		}
		i++;
	}
	throw MakeFormErrorException();
}

const char *Intern::MakeFormErrorException::what() const throw() { 
	return "Error: Intern couldn' create form.";
}