/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:03:05 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/19 20:15:51 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "./AForm.hpp"

class RobotomyRequestForm : public AForm
{

	public:

		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		~RobotomyRequestForm(void);

		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

	private:
		const std::string target;

};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i);

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */