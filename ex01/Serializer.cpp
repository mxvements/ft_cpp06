/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:20:44 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/27 20:15:56 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

/* ************************************************************************** */

Serializer::Serializer(){}
Serializer::~Serializer(){}
Serializer::Serializer(Serializer const &src){
	*this = src;
}
Serializer &Serializer::operator=(Serializer const &src){
	if (this != &src) {}
	return (*this);
}
