/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:48:50 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/23 19:34:08 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	*this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
	if (this == &copy) {
		return (*this);
	}
	_listcont = copy._listcont;
	_veccont = copy._veccont;
	return (*this);
}

static void mergeVec(std::vector<int>::iterator begin,
					std::vector<int>::iterator mid,
					std::vector<int>::iterator end) {
	
    std::vector<int> merged;
    merged.reserve(std::distance(begin, end));

	std::vector<int>::iterator left = begin;
   	std::vector<int>::iterator right = mid;

    while (left != mid && right != end) {
        if (*left <= *right) {
            merged.push_back(*left);
            ++left;
        } else {
            merged.push_back(*right);
            ++right;
        }
    }

    while (left != mid) {
        merged.push_back(*left);
        ++left;
    }

    while (right != end) {
        merged.push_back(*right);
        ++right;
    }

    std::copy(merged.begin(), merged.end(), begin);
}

static void mergeSortVec(std::vector<int>::iterator begin,
						std::vector<int>::iterator end) {

    if (std::distance(begin, end) > 1) {
        std::vector<int>::iterator mid = begin;
        std::advance(mid, std::distance(begin, end) / 2);

        mergeSortVec(begin, mid);
        mergeSortVec(mid, end);

        mergeVec(begin, mid, end);
    }
}

static void mergeList(std::list<int>::iterator begin,
				std::list<int>::iterator mid,
				std::list<int>::iterator end) {
	
   	std::list<int> merged;

   	std::list<int>::iterator left = begin;
   	std::list<int>::iterator right = mid;

    while (left != mid && right != end) {
        if (*left <= *right) {
            merged.push_back(*left);
            ++left;
        } else {
            merged.push_back(*right);
            ++right;
        }
    }

    while (left != mid) {
        merged.push_back(*left);
        ++left;
    }

    while (right != end) {
        merged.push_back(*right);
        ++right;
    }

    std::copy(merged.begin(), merged.end(), begin);
}

static void mergeSortList(std::list<int>::iterator begin,
						 std::list<int>::iterator end) {

    if (std::distance(begin, end) > 1) {
        std::list<int>::iterator mid = begin;
        std::advance(mid, std::distance(begin, end) / 2);

        mergeSortList(begin, mid);
        mergeSortList(mid, end);

        mergeList(begin, mid, end);
    }
}

static int ValidateArgs(char **args) {
	args++;
	for (int i = 0; args[i] != NULL; i++)
	{
		int nbr;
		char *endPtr;
		nbr = strtol(args[i], &endPtr, 10);
		if (nbr <= 0 || *endPtr != '\0')
		{
			std::cerr << "Error" << std::endl;
			return -1;
		}
	}
	return 0;
}

void displayBefore(char **args) {
	args++;
	std::cout << "Before:  ";
	for (int i = 0; args[i] != NULL; i++)
	{
		std::cout << args[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::doOperation(int argc, char **args) {
	
	if (ValidateArgs(args) == -1)
		return ;
	displayBefore(args);
	
	clock_t starTList = clock();
	this->populateContainersList(args);
	mergeSortList(_listcont.begin(), _listcont.end());
	clock_t listTime = clock() - starTList;
	
	clock_t startVector = clock();
	this->populateContainersVec(args);
	mergeSortVec(_veccont.begin(), _veccont.end());
	clock_t vecTime = clock() - startVector;

	displayAfter();
	
	 std::cout<< "Time to process a range of " << argc - 1 << " elements of std::list   " << static_cast<double>(listTime)/CLOCKS_PER_SEC * 1000<< " ms" << std::endl;
	 std::cout<< "Time to process a range of " << argc - 1 << " elements of std::vector " << static_cast<double>(vecTime)/CLOCKS_PER_SEC * 1000<< " ms" << std::endl;
}

void PmergeMe::displayAfter(void) {
	std::cout << "After:   ";
		std::list<int>::iterator it;
	for (it = _listcont.begin(); it != _listcont.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::populateContainersVec(char **args)
{
	args++;
	
	for (int i = 0; args[i] != NULL; i++)
	{
		int nbr;
		char *endPtr;
		nbr = strtol(args[i], &endPtr, 10);
		_veccont.push_back(nbr);
	}
}

void PmergeMe::populateContainersList(char **args)
{
	args++;
	
	for (int i = 0; args[i] != NULL; i++)
	{
		int nbr;
		char *endPtr;
		nbr = strtol(args[i], &endPtr, 10);
		_listcont.push_back(nbr);
	}
}