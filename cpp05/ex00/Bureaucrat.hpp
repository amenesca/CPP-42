/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:11 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/11 13:24:13 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <ostream>
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
    private:
    // atributos privados da classe
    	const std::string	_name;
    	int					_grade;
	
	public:
    // Forma canônica
		Bureaucrat(void); // construtor padrão
		Bureaucrat(const std::string &name, int grade); // construtor de atribuição
		Bureaucrat(const Bureaucrat &bureaucrat); // construtor de cópia
		virtual ~Bureaucrat(void); // destrutor virtual

	// Sobrecarga de Operador
		Bureaucrat	&operator=(const Bureaucrat &bureaucrat); // sobrecarga do operador de atribuição de cópia

	// Funções membro
		void	increaseGrade(void);
		void	decreaseGrade(void);
	// Getters
		const std::string	getName(void) const;
		int					getGrade(void) const;

	// Exceptions
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