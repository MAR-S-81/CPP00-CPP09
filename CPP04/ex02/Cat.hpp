/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:17:01 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/09 14:51:56 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain* brain;
    public:
        Cat();
        Cat( Cat const &src );
        Cat &operator=( Cat const & rhs );
        virtual ~Cat();
        
        virtual void    makeSound(void) const;
};

#endif