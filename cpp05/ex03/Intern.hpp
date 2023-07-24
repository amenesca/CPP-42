/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:48:23 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/21 16:36:02 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern &intern);
		~Intern(void);

		Intern	&operator=(const Intern &intern);
		AForm *makeForm(const std::string formName, const std::string target) const;

		class MakeFormErrorException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

};

/*Essa declaração usando using cria um alias de tipo chamado constructorPtr,\
 que representa um ponteiro para função que retorna um ponteiro para AForm\
 e recebe um parâmetro do tipo const std::string.*/

typedef AForm* (*ConstructorPtr)(const std::string);

#endif
