/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:45:32 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/13 20:09:08 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>

class ElementNotFoundException : public std::exception {
public:
    virtual const char* what() const throw();
};

template<typename T>
typename T::iterator easyfind(T& container, typename T::value_type element);

#include "easyfind.tpp"

#endif