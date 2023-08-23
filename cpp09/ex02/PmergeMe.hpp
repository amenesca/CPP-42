/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:48:53 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/23 19:21:47 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>
#include <ctime>

class PmergeMe {
	private:
		std::vector<int> _veccont;
		std::list<int> _listcont;
	public:
		void populateContainersVec(char **args);
		void populateContainersList(char **args);
		void doOperation(int argc, char **args);
		void displayAfter(void);
};

#endif