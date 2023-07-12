#include "Form.hpp"

// Forma canônica / Contrutores e Destrutor

Form::Form(void)\
 : _gradeToExecute(50), _gradeToSign(30), _name("default"), _signed(0)
{
    std::cout << "Form default constructor called." << std::endl;
    return ;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)\
 : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form:" << _name << " assignment constructor called." << std::endl;
    return ;
}

Form::Form(const Form &form)
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

Form &Form::operator=(const Form &form)
{
	std::cout << "Form copy operator called." << std::endl;
	if (this != &form)
		_signed = form._signed;
	return ;
}
