/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberryCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:03:12 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/19 15:11:55 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERRYCREATIONFORM_HPP
# define SHRUBBERRYCREATIONFORM_HPP

# include <iostream>
# include "./Form.hpp"

class ShrubberryCreationForm : public Form
{

	public:

		ShrubberryCreationForm();
		ShrubberryCreationForm( ShrubberryCreationForm const & src );
		~ShrubberryCreationForm();

		ShrubberryCreationForm &		operator=( ShrubberryCreationForm const & rhs );

	private:
		const std::string target;

};

std::ostream &			operator<<( std::ostream & o, ShrubberryCreationForm const & i );

#endif /* ****************************************** SHRUBBERRYCREATIONFORM_H */