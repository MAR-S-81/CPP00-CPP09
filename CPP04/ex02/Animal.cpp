/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:26:45 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/09 14:53:46 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal() {
    this->type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal( AAnimal const &src ) {
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = src.getType();
}

AAnimal &AAnimal::operator=( AAnimal const &rhs ) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
    return(type);
}