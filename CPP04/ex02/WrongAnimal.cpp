/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:20:40 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/08 17:21:39 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    this->type = "WrongAnimal";
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &src ) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->type = src.getType();
}

WrongAnimal &WrongAnimal::operator=( WrongAnimal const &rhs ) {
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
    return(type);
}

void WrongAnimal::makeSound() const{
    std::cout << "***An unknown wrong animal noise sounds***" << std::endl;
}