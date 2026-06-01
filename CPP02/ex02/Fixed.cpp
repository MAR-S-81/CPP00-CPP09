/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:46:34 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/01 18:51:12 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    Fixed::_value = 0;
}

Fixed::Fixed( Fixed const &src ) {
    *this = src;
}

Fixed &Fixed::operator=( Fixed const &rhs ) {
    if (this != &rhs) {
        this->_value = rhs._value;
    }
    return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits() const {
    return(_value);
}

void Fixed::setRawBits( int const raw ) {
    _value = raw;
}

Fixed::Fixed(int const nb) {
    this->_value = nb << _bits;
}

Fixed::Fixed(float const nb) {
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

bool Fixed::operator>( Fixed const & rhs ) const {
    return (this->_value > rhs._value);
}

bool Fixed::operator<( Fixed const & rhs ) const {
    return (this->_value < rhs._value);
}

bool Fixed::operator!=( Fixed const & rhs ) const {
    return (this->_value != rhs._value);
}

bool Fixed::operator==( Fixed const & rhs ) const {
    return (this->_value == rhs._value);
}

bool Fixed::operator>=( Fixed const & rhs ) const {
    return (this->_value >= rhs._value);
}

bool Fixed::operator<=( Fixed const & rhs ) const {
    return (this->_value <= rhs._value);
}

Fixed Fixed::operator+( Fixed const & rhs ) const {
	Fixed ret;
	ret.setRawBits(this->_value + rhs._value);
	return ret;
}

Fixed Fixed::operator-( Fixed const & rhs ) const {
	Fixed ret;
	ret.setRawBits(this->_value - rhs._value);
	return ret;
}

Fixed Fixed::operator*( Fixed const & rhs ) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/( Fixed const & rhs ) const {
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++() {
	Fixed::_value++;
	return *this;
}

Fixed &Fixed::operator--() {
	Fixed::_value--;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->_value++;
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->_value--;
	return tmp;
}

Fixed & Fixed::min( Fixed & first, Fixed & second ) {
    if (first.getRawBits() < second.getRawBits())
        return first;
    return second;
}

Fixed & Fixed::max( Fixed & first, Fixed & second ) {
    if (first.getRawBits() > second.getRawBits())
        return first;
    return second;
}

Fixed const & Fixed::min( Fixed const & first, Fixed const & second ) {
	if (first.getRawBits() < second.getRawBits())
        return first;
    return second;
}

Fixed const & Fixed::max( Fixed const & first, Fixed const & second ) {
	if (first.getRawBits() > second.getRawBits())
        return first;
    return second;
}