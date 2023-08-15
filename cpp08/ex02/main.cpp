/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:23:01 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/15 19:37:51 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::cout << "Basic Test with MutantStack" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl;
	std::cout << "Same Test but with Vector(some functions changed to equivalent)" << std::endl;
	
	std::vector<int> vec_numbers;
	vec_numbers.push_back(5);
	vec_numbers.push_back(17);
	std::cout << vec_numbers.back() << std::endl;
	vec_numbers.pop_back();
	std::cout << vec_numbers.size() << std::endl;
	vec_numbers.push_back(3);
	vec_numbers.push_back(5);
	vec_numbers.push_back(737);
	//[...]
	vec_numbers.push_back(0);
	std::vector<int>::iterator it_vec = vec_numbers.begin();
	std::vector<int>::iterator ite_vec = vec_numbers.end();
	++it_vec;
	--it_vec;
	while (it_vec != ite_vec)
	{
		std::cout << *it_vec << std::endl;
		++it_vec;
	}
	return 0;
}