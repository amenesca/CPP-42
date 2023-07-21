/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:02:09 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/21 13:30:02 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"

Form::Form(void)\
 : _name("default"), _gradeToSign(150), _gradeToExecute(150), _signed(false)
{
    return ;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)\
 : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw Form::GradeTooLowException();
    return ;
}

Form::Form(const Form &form)\
 : _name(form._name), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute)
{
    *this = form;
    return ;
}

Form::~Form(void)
{
    return ;
}

Form &Form::operator=(const Form &form)
{
	if (this != &form)
		_signed = form._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Form &rhs) {
	o << rhs.getName() << ", form sign is " << std::boolalpha << rhs.getSigned() << ", grade to sign is " << rhs.getGradeToSign() << ", grade to execute is " << rhs.getGradeToExecute();
	return o;
}

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
	return (this->_gradeToExecute);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Error: Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Error: Grade is too low";
}