/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:11 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/20 22:02:09 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# pragma once
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
    private:
    	const std::string	_name;
    	int					_grade;
	
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		~Bureaucrat(void);

		Bureaucrat	&operator=(const Bureaucrat &bureaucrat);

		void	increaseGrade(void);
		void	decreaseGrade(void);
		const std::string	getName(void) const;
		int		getGrade(void) const;
		void	signForm(AForm &Aform);
		void	executeForm(const AForm &form) const;


	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Bureaucrat::exception : Grade is too high!");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Bureaucrat::exception : Grade is too low!");
			}
	};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif