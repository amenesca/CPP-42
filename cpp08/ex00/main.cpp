/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:45:40 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/15 17:41:53 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <iostream>
#include <list>

int main() {
    std::vector<int> nums_vector;

    nums_vector.push_back(10);
    nums_vector.push_back(20);
    nums_vector.push_back(30);
    nums_vector.push_back(40);
    nums_vector.push_back(50);

	std::cout << "Vector Test:" << std::endl;
    int target = 30;
    try {
        std::vector<int>::iterator result = easyfind(nums_vector, target);
        std::cout << "Number " << target << " found in the index " << std::distance(nums_vector.begin(), result);
        std::cout << " The value is obviously: " << *result << std::endl;
    } catch (const ElementNotFoundException& ex) {
        std::cout << ex.what() << std::endl;
    }

	std::list<int> nums_list;

	nums_list.push_back(10);
    nums_list.push_back(20);
    nums_list.push_back(30);
    nums_list.push_back(40);
    nums_list.push_back(50);

	std::cout << std::endl << "List Test:" << std::endl;
	int tofind = 40;
    try {
        std::list<int>::iterator list_pos = easyfind(nums_list, tofind);
        std::cout << "Number " << tofind << " found in the index " << std::distance(nums_list.begin(), list_pos);
        std::cout << " The value is obviously: " << *list_pos << std::endl;
    } catch (const ElementNotFoundException& ex) {
        std::cout << ex.what() << std::endl;
    }

	std::cout << std::endl << "Can't find test" << std::endl; 
	try {
		std::cout << "Trying to find 60 in the list container" << std::endl;
		easyfind(nums_list, 60);
	} catch (const ElementNotFoundException& ex) {
		std::cout << ex.what() << std::endl;
	}
    return 0;
}