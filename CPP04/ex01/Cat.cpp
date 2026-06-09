/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:16:50 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/09 14:21:57 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
	this->brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( Cat const &src ) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = src.getType();
	this->brain = new Brain(*src.brain);
}

Cat &Cat::operator=( Cat const &rhs ) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.getType();
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const{
    std::cout << "MIAOU MIAOU" << std::endl;
}