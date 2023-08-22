/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:46:54 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/22 19:56:35 by amenesca         ###   ########.fr       */
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
		void Operation(const std::string& input);
		
};

#endif