/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseTypes.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:05:38 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/01 16:15:04 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseTypes.hpp"
#include <typeinfo>

Base* generate(void)
{
	srand((unsigned)time(0));
	int random = rand()%3;

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else if (random == 2)
		return new C();

	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Pointer to object of \"A\" class" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Pointer to object of \"B\" class" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Pointer to object of \"C\" class" << std::endl;
}

void identify(Base& p)
{
	try {
		A typea = dynamic_cast<A&>(p);
		std::cout << "Reference to Object of \"A\" class" << std::endl;
		static_cast<void>(typea);
	} catch (std::bad_cast &bc) {}
	try {
		B typeb = dynamic_cast<B&>(p);
		std::cout << "Reference to Object of \"B\" class" << std::endl;
		static_cast<void>(typeb);
	} catch (std::bad_cast &bc) {}
	try {
		C typec = dynamic_cast<C&>(p);
		std::cout << "Reference to Object of \"C\" class" << std::endl;
		static_cast<void>(typec);
	} catch (std::bad_cast &bc) {}
}