/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:23:06 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/14 17:10:35 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
	public:
		MutantStack() {}
		
		MutantStack(const MutantStack& copy) {
			*this = copy;
		}
		virtual ~MutantStack() {}
		
		MutantStack& operator=(const MutantStack& copy) {
  			if (this != &copy) {
            	std::stack<T, std::deque<T> >::operator=(copy); // Chama o operador de atribuição da classe base
			}
    		return *this;
		}

		typedef typename std::stack<T, std::deque<T> >::container_type::iterator iterator;
		typedef typename std::stack<T, std::deque<T> >::container_type::const_iterator const_iterator;


		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}

		const_iterator begin() const {return this->c.begin;}
		const_iterator end() const {return this->c.begin;}

		
};

#endif