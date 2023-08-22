/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:46:51 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/22 20:03:01 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void RPN::Operation(const std::string& input) {
	std::istringstream iss(input);

	std::string element;
	while (iss >> element) {
		if (element >= "0" && element <= "9")
		{
			_rpn.push(std::atoi(element.c_str()));
			continue;
		}
		else
		{
			int x = _rpn.top();
			_rpn.pop();
			int y = _rpn.top();
			_rpn.pop();
			if (element == "+")
			{
				_rpn.push(x + y);
				continue;
			}
			if (element == "-")
			{
				_rpn.push(x - y);
				continue;
			}	
			if (element == "*")
			{
				_rpn.push(x * y);
				continue;
			}
			if (element == "/")
			{
				_rpn.push(x / y);
				continue;
			}
		}
	}
	std::cout << _rpn.top() << std::endl;
}