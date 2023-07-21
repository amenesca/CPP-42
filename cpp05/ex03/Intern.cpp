/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:48:18 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/21 16:34:54 by amenesca         ###   ########.fr       */
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
	constructorPtr *constructorPtr[3] = {&newShrubbery, &newPresidential, &newRobotomy};
	std::string		formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *formPtr = NULL;
	int i = 0;

	while (i < 3)
	{
		if (formName == formNames[i])
		{
			formPtr = constructorPtr[i](target);
			std::cout << "Intern created " << formPtr->getName() << " form." << std::endl;
			break ;
		}
		i++;
	}
	if (i == 3)
		std::cout << "Intern couldn't create " << formName << "form." << std::endl;
	return (formPtr); 	
}