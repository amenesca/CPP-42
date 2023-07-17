/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:02:09 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/17 18:23:52 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"

// Forma canônica / Contrutores e Destrutor

Form::Form(void)\
 : _gradeToExecute(150), _gradeToSign(150), _name("default"), _signed(false)
{
    std::cout << "Form default constructor called." << std::endl;
    return ;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)\
 : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
    std::cout << "Form:" << _name << " assignment constructor called." << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw Form::GradeTooLowException();
    return ;
}

Form::Form(const Form &form)\
 : _name(form._name), _gradeToExecute(form._gradeToExecute), _gradeToSign(form._gradeToSign)
{
    std::cout << "Form copy constructor called." << std::endl;
    *this = form;
    return ;
}

Form::~Form(void)
{
    std::cout << "Form destructor called." << std::endl;
    return ;
}

// Sobrecarga de operadores

Form &Form::operator=(const Form &form)
{
	std::cout << "Form copy operator called." << std::endl;
	if (this != &form)
		_signed = form._signed;
	return (*this);
}

// Getters's grade

const std::string Form::getName(void) const
{
	return(_name);
}

bool Form::getSigned(void) const
{
	return(_signed);
}

int Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}