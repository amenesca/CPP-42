/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:28:26 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/13 18:31:33 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include "easyfind.hpp"

const char* ElementNotFoundException::what() const throw() {
	return "Exception: Element not found.";
}

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