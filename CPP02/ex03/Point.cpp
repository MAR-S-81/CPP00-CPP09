/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:48:52 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/02 13:26:04 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point( float const x_val, float const y_val ) : _x(x_val), _y(y_val) {
}

Point::Point( Point const &src ) : _x(src._x), _y(src._y){
}

Point &Point::operator=( Point const &rhs ) {
    (void)rhs;
    return *this;
}

Point::~Point()
{
}

Fixed Point::getX( void ) const {
	return _x;
}

Fixed Point::getY( void ) const {
	return _y;
}