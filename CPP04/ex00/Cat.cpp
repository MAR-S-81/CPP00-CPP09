/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:16:50 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/08 17:18:11 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( Cat const &src ) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = src.getType();
}

Cat &Cat::operator=( Cat const &rhs ) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "MIAOU MIAOU" << std::endl;
}