/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:11 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/21 13:14:04 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# pragma once
# include <iostream>
# include "./Form.hpp"

class Form;

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
		void	signForm(Form &form);
		const std::string	getName(void) const;
		int					getGrade(void) const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif