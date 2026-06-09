/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:46:14 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/09 17:48:20 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() {
    this->_type = "ice";
}

Ice::Ice( Ice const &src ) {
    this->_type = src.getType();
}

Ice &Ice::operator=( Ice const &rhs ) {
    (void)rhs;
    return *this;
}

Ice::~Ice() {
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}