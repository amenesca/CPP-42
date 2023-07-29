/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:11:40 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/29 19:59:46 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include "./Data.hpp"

class Serializer {
	private:
		Serializer(void);
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& copy);
	public:
		~Serializer(void);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif