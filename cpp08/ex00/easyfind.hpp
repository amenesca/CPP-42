/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:45:32 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/11 17:32:37 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

class ElementNotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Exception: Element not found.";
    }
};

template<typename T>
typename T::iterator easyfind(T& container, typename T::value_type element)
{
	typename T::iterator it;
	it = find(container.begin(), container.end(), element);
	if (it == container.end())
		throw ElementNotFoundException();
	else
		return it;
}

#endif