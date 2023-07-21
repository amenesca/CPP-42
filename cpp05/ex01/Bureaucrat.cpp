/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:01 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/21 13:30:27 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

// Forma canônica / Contrutores e Destrutor
Bureaucrat::Bureaucrat(void)\
 : _name("default"), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)\
 : _name(name)
{
	if (grade <= 0)
		throw GradeTooHighException();
	if (grade >= 151)
		throw GradeTooLowException();
	_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)\
 : _name(bureaucrat._name)
{
	*this = bureaucrat;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	return ;
}

// Sobrecarga de operadores
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
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

void	Bureaucrat::signForm(Form &form)
{
	try 
	{
			form.beSigned(*this);
			std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e) 
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
	
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Error: Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Error: Grade is too low";
}