/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberryCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:03:12 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/19 19:43:56 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERRYCREATIONFORM_HPP
# define SHRUBBERRYCREATIONFORM_HPP

# include <iostream>
# include "./AForm.hpp"

class ShrubberryCreationForm : public AForm
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