/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberryCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:03:12 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/19 20:16:02 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERRYCREATIONFORM_HPP
# define SHRUBBERRYCREATIONFORM_HPP

# include <iostream>
# include "./AForm.hpp"

class ShrubberryCreationForm : public AForm
{

	public:

		ShrubberryCreationForm(void);
		ShrubberryCreationForm(ShrubberryCreationForm const &src);
		~ShrubberryCreationForm(void);

		ShrubberryCreationForm &operator=(ShrubberryCreationForm const &rhs);

	private:
		const std::string target;

};

std::ostream &operator<<(std::ostream &o, ShrubberryCreationForm const &i);

#endif /* ****************************************** SHRUBBERRYCREATIONFORM_H */