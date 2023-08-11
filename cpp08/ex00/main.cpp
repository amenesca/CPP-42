/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:45:40 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/11 17:34:36 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <iostream>

int main() {
    std::vector<int> nums;

    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);
    nums.push_back(40);
    nums.push_back(50);

    int target = 30;
    try {
        std::vector<int>::iterator result = easyfind(nums, target);
        std::cout << "Elemento " << target << " encontrado no índice " << std::distance(nums.begin(), result);
        std::cout << " e seu valor é: " << *result << std::endl;
    } catch (const ElementNotFoundException& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}