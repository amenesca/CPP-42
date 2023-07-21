/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:02:04 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/21 13:04:51 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# pragma once
# include "./Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm {
    private:
	
        const std::string   _name;
        const int           _gradeToSign;
        const int           _gradeToExecute;
        bool				_signed;
    
	public:
	
        AForm(void);
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &Aform);
        virtual ~AForm(void);
		
        AForm	&operator=(const AForm &Aform);
		
        const std::string getName(void) const;
        bool getSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;
        
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
		void	executeCheck(const Bureaucrat &bureaucrat) const;
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class ExecuteNotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class FileOpeningFail : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream    &operator<<(std::ostream &out, const AForm &Aform);

#endif