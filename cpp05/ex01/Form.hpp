/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:02:04 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/17 18:24:36 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "./Bureaucrat.hpp"

class Form {
    private:
    // Atributos privados
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;
    public:
    // Forma canônica
        Form(void); // construtor padrão
        Form(const std::string &name, int gradeToSign, int gradeToExecute); // construtor de atribuição
        Form(const Form &form); // construtor de cópia
        virtual ~Form(void); // destrutor virtual

    // Sobrecarga de Operador

        Form    &operator=(const Form &form); // sobrecarga do operador de atribuição de cópia
    // Funções membro

        void    beSigned(const Bureaucrat &bureaucrat);
    // Getters

        const std::string   getName(void) const;
        bool                getSigned(void) const;
        int           getGradeToSign(void) const;
        int           getGradeToExecute(void) const;
	//exceptions

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Form::exception grade is too high!");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Form::exception grade is too low!");
				}
		};
};

std::ostream    &operator<<(std::ostream &out, const Form &form);

#endif