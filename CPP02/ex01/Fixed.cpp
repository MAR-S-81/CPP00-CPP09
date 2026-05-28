/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:46:34 by mchesnea          #+#    #+#             */
/*   Updated: 2026/05/28 19:10:47 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    Fixed::_value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &src ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=( Fixed const &rhs ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->_value = rhs._value;
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

Fixed::Fixed(int const nb) {
    std::cout << "Int constructor called" << std::endl;
    this->_value = nb << _bits;
}

Fixed::Fixed(float const nb) {
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(nb * (1 << _bits));
}

int Fixed::toInt() const {
    return (this->_value >> _bits);
}

float Fixed::toFloat() const {
    return ((float)this->_value / (float)(1 << _bits));
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}

