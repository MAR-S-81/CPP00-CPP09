/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:27:17 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/09 14:52:48 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal( AAnimal const &src );
        AAnimal &operator=( AAnimal const & rhs );
        virtual ~AAnimal();
        
        std::string     getType(void) const;
        virtual void    makeSound(void) const = 0;
};

#endif