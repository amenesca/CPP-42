/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:02:57 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/19 20:15:38 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "./AForm.hpp"

class PresidentialPardonForm : public AForm
{

	public:

		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const& src);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);

		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

	private:
		const std::string target;

};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i);

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */