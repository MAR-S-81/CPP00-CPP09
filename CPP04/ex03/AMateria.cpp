/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:56:06 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/09 16:06:11 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void) : _type("Default"){}

AMateria::AMateria(std::string const &type) : _type(type){}

AMateria::AMateria( AMateria const &src ) {
    this->_type = src._type;
}

AMateria &AMateria::operator=( AMateria const &rhs ) {
    (void)rhs;
    return *this;
}

AMateria::~AMateria() {
}

std::string const &AMateria::getType() const{
	return (_type);
}

void AMateria::use(ICharacter& target) {
    (void)target;
}