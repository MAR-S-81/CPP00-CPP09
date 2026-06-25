/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:43:16 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/25 12:53:18 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main () {
	Data originalData(42, "BDC");
	Data* originalPtr = &originalData;

	std::cout << "Adress : " << originalPtr << std::endl;
    std::cout << "ID     : " << originalPtr->getId() << std::endl;
    std::cout << "Name   : " << originalPtr->getName() << std::endl;

	uintptr_t rawAddress = Serializer::serialize(originalPtr);
	std::cout << "(uintptr_t) : " << rawAddress << std::endl;

	Data* deserializedPtr = Serializer::deserialize(rawAddress);
	std::cout << deserializedPtr << std::endl;

	if (deserializedPtr == originalPtr) {
        std::cout << "SUCCES" << std::endl;
    } 
	else {
        std::cout << "FAIL" << std::endl;
    }
	return 0;
}