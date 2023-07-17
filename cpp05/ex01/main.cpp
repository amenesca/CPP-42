/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:01:57 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/17 18:16:48 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Bureaucrat	alan("alan", 20);
	Form		seila("burro", 30, 10);

	alan.signForm(seila);
	return (0);
}