/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:20:58 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/25 12:42:45 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){
}

Serializer::Serializer( Serializer const &src ){
	(void)src;
}

Serializer &Serializer::operator=( Serializer const &rhs ) {
	(void)rhs;
    return *this;
}

Serializer::~Serializer(){
}

uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t ret = reinterpret_cast<uintptr_t>(ptr);
	return ret;
}

Data* Serializer::deserialize(uintptr_t raw) {
	Data* ret = reinterpret_cast<Data*>(raw);
	return ret;
}