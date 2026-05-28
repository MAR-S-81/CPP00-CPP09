/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:46:44 by mchesnea          #+#    #+#             */
/*   Updated: 2026/05/28 18:56:25 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _bits = 8;
    public:
        Fixed();
        Fixed( Fixed const &src );
        Fixed &operator=( Fixed const & rhs );
        ~Fixed();
        Fixed(int const nb);
        Fixed(float const nb);
    
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        int     toInt(void) const;
        float   toFloat(void) const;
};

std::ostream &operator<<( std::ostream & o, Fixed const & i );

#endif