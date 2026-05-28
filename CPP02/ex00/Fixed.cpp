/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:46:34 by mchesnea          #+#    #+#             */
/*   Updated: 2026/05/28 17:24:33 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    Fixed::_value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &src ) {
    std::cout << "Copy constructor called" << std::endl;
    this->_value = src.getRawBits();
}

Fixed &Fixed::operator=( Fixed const &rhs ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->_value = rhs.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return(_value);
}

void Fixed::setRawBits( int const raw ) {
    _value = raw;
}
