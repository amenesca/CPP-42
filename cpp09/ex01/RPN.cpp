/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:46:51 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/23 11:18:13 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void RPN::Operation(const std::string& input) {
	std::istringstream iss(input);

	std::string element;
	while (iss >> element) {
		if (element >= "0" && element <= "9") {
			_rpn.push(std::atoi(element.c_str()));
		} else if (element == "+" || element == "-" || element == "*" || element == "/") {
			if (_rpn.size() < 2) {
				std::cerr << "Error" << std::endl;
				return;
			}
			int y = _rpn.top();
			_rpn.pop();
			int x = _rpn.top();
			_rpn.pop();

			if (element == "+") {
				_rpn.push(x + y);
			} else if (element == "-") {
				_rpn.push(x - y);
			} else if (element == "*") {
				_rpn.push(x * y);
			} else if (element == "/") {
				if (y == 0) {
					std::cerr << "Error" << std::endl;
					return;
				}
				_rpn.push(x / y);
			}
		} else {
			std::cerr << "Error" << std::endl;
			return;
		}
	}

	if (_rpn.size() != 1) {
		std::cerr << "Error" << std::endl;
		return;
	}

	std::cout << _rpn.top() << std::endl;
}