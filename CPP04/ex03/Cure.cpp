/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:47:06 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/09 17:49:12 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() {
    this->_type = "cure";
}

Cure::Cure( Cure const &src ) {
    this->_type = src.getType();
}

Cure &Cure::operator=( Cure const &rhs ) {
    (void)rhs;
    return *this;
}

Cure::~Cure() {
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}