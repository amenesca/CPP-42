/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:01 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/15 11:07:54 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

// Forma canônica / Contrutores e Destrutor
Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	std::cout << "Bureaucrat: " << _name << " assignment constructor called." << std::endl;
	if (grade <= 0)
		throw GradeTooHighException();
	if (grade >= 151)
		throw GradeTooLowException();
	_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat._name)
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
	*this = bureaucrat;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called." << std::endl;
	return ;
}

// Sobrecarga de operadores
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	std::cout << "Bureaucrat copy assignment operator overload called." << std::endl;
	if (this != &bureaucrat)
		_grade = bureaucrat._grade;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", grade " << bureaucrat.getGrade();
	return (os);
}

// Funções Membro
void	Bureaucrat::increaseGrade(void)
{
	if (_grade < 2)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decreaseGrade(void)
{
	if (_grade > 149)
		throw GradeTooLowException();
	_grade++;
}
	
// Getters

const std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}
