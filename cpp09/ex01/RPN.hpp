/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:46:54 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/23 11:45:02 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <sstream>
# include <cstdlib>
# include <iostream>

class RPN {
	private:
		std::stack<int> _rpn;
	public:
		RPN(void);
		~RPN(void);
		RPN(const RPN& copy);
		RPN& operator=(const RPN& copy);
		
		void Operation(const std::string& input);
		
};

#endif