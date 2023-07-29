/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:11:26 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/29 19:55:43 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::~Serializer(void) {}

Serializer::Serializer(const Serializer& copy)
{
	*this = copy;
}

Serializer& Serializer::operator=(const Serializer& copy)
{
	static_cast<void>(copy);
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t serialized;

	serialized = reinterpret_cast<uintptr_t>(ptr);
	return serialized;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* deserialized;

	deserialized = reinterpret_cast<Data*>(raw);
	return deserialized;
}