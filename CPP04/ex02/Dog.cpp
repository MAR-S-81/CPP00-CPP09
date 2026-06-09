/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:09:59 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/09 14:16:50 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
	this->brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( Dog const &src ) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = src.getType();
	this->brain = new Brain(*src.brain);
}

Dog &Dog::operator=( Dog const &rhs ) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.getType();
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const{
    std::cout << "OUAF OUAF" << std::endl;
}