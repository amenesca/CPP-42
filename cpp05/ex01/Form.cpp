#include "Form.hpp"

// Forma canônica / Contrutores e Destrutor

Form::Form(void)\
 : _gradeToExecute(50), _gradeToSign(30),\
  _name("default"), _signed(0)
{
    std::cout << "Form default constructor called." << std::endl;
    return ;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)\
 : _name(name), _gradeToSign(gradeToSign),\
  _gradeToExecute(gradeToExecute), _signed(0)
{
    std::cout << "Form:" << _name << " assignment constructor called." << std::endl;
    return ;
}

Form::Form(const Form &form)\
 : _name(form._name), _gradeToExecute(form._gradeToExecute),\
  _gradeToSign(form._gradeToSign)
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


// Getters

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
