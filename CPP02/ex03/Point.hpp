/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:48:42 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/02 13:59:20 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point();
	Point( float const x_val, float const y_val );
	Point( Point const &src );
    Point &operator=( Point const & rhs );
	~Point();
	Fixed getX( void ) const;
	Fixed getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif