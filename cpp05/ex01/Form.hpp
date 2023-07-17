/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:02:04 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/17 18:54:46 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "./Bureaucrat.hpp"
class Bureaucrat;
class Form {
    private:
    // Atributos privados
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;
    public:
        Form(void);
        Form(const std::string &name, int gradeToSign, int gradeToExecute);
        Form(const Form &form);
        virtual ~Form(void);
		
        Form	&operator=(const Form &form);

        void	beSigned(const Bureaucrat &bureaucrat);
        const std::string	getName(void) const;
        bool	getSigned(void) const;
        int	getGradeToSign(void) const;
        int	getGradeToExecute(void) const;
		
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