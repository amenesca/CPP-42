/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:02:09 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/21 13:27:30 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"

AForm::AForm(void)\
 : _name("default"), _gradeToSign(150), _gradeToExecute(150), _signed(false)
{
    return ;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)\
 : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw AForm::GradeTooLowException();
    return ;
}

AForm::AForm(const AForm &Aform)\
 : _name(Aform._name), _gradeToSign(Aform._gradeToSign), _gradeToExecute(Aform._gradeToExecute)
{
    *this = Aform;
    return ;
}

AForm::~AForm(void)
{
    return ;
}

AForm &AForm::operator=(const AForm &Aform)
{
	if (this != &Aform)
		_signed = Aform._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const AForm &rhs) {
	o << rhs.getName() << ", Aform sign is " << std::boolalpha << rhs.getSigned() << \
	", grade to sign is " << rhs.getGradeToSign() << ", grade to execute is " << rhs.getGradeToExecute();
	return o;
}

const std::string AForm::getName(void) const
{
	return(_name);
}

bool AForm::getSigned(void) const
{
	return(_signed);
}

int AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::executeCheck(const Bureaucrat &bureaucrat) const
{
	if (!this->getSigned())
		throw AForm::ExecuteNotSigned();
	if (this->getGradeToExecute() < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Error: Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Error: Grade is too low";
}

const char *AForm::ExecuteNotSigned::what() const throw() {
	return "Error: Form is not signed";
}

const char *AForm::FileOpeningFail::what() const throw() {
	return "Error: Cannot open file";
}