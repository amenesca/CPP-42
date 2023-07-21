/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:02:57 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/20 15:12:02 by amenesca         ###   ########.fr       */
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

		void execute(Bureaucrat const & executor) const;
		
	private:
		const std::string _target;

};

#endif