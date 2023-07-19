/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:02:04 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/19 19:49:45 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# pragma once
# include "./Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form {
    private:
	
        const std::string   _name;
        const int           _gradeToSign;
        const int           _gradeToExecute;
        bool                _signed;
    
	public:
	
        Form(void);
        Form(const std::string &name, int gradeToSign, int gradeToExecute);
        Form(const Form &form);
        ~Form(void);
		
        Form	&operator=(const Form &form);
		
        const std::string getName(void) const;
        bool getSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;

		void beSigned(const Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("grade is too high!");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("grade is too low!");
				}
		};
};

std::ostream    &operator<<(std::ostream &out, const Form &form);

#endif