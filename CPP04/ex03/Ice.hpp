/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:37:03 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/09 17:47:23 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice( Ice const &src );
        Ice &operator=( Ice const & rhs );
        virtual ~Ice();

		virtual AMateria* Ice::clone() const;
		virtual void use(ICharacter& target);
};

#endif