/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:26:45 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/08 17:00:41 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    this->type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( Animal const &src ) {
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = src.getType();
}

Animal &Animal::operator=( Animal const &rhs ) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
    return(type);
}

void Animal::makeSound() const{
    std::cout << "***An unknown animal noise sounds***" << std::endl;
}