/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:47:17 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/09 17:47:47 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure( Cure const &src );
        Cure &operator=( Cure const & rhs );
        virtual ~Cure();

		virtual AMateria* Cure::clone() const;
		virtual void use(ICharacter& target);
};

#endif