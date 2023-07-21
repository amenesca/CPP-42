/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:03:07 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/20 14:16:40 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(void)\
 : AForm("Shrubbery", 145, 137)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)\
 :AForm("Shrubbery", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)\
 : AForm("Shrubbery", 145, 137), _target(src._target)
{
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj)
{
	(void)obj;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->AForm::executeCheck(executor);

	std::string file_name = _target + "_shrubbery";
	const char *cString = file_name.c_str();
	std::ofstream file(cString);

	if (file.is_open()) {
		file << "    ccee88oo \n";
        file << " C8O8O8Q8PoOb o8oo \n";
        file << " dOB69QO8PdUOpugoO9bD \n";
        file << "CgggbU8OU qOp qOdoUOdcb \n";
        file << "    6OuU  /p u gcoUodpP \n";
        file << "      \\\\//  /douUP \n";
        file << "        \\\\//  \\ \n";
        file << "         |||/\\ \\ \n";
        file << "         |||\\ \\ \n";
        file << "         ||||\\ \\ \n";
        file << "   .....//||||\\ \\\\. . .";
	
		file.close();
		std::cout << "File " << _target << "_shrubbery has been created" << std::endl;
	} else {
		throw FileOpeningFail();
	}
}
