/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:00:02 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/10 14:07:27 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include <iostream>
#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
private:
	AMateria* _sources[4];
public:
	MateriaSource();
    MateriaSource( MateriaSource const &src );
    MateriaSource &operator=( MateriaSource const & rhs );
    virtual ~MateriaSource();

	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const & type);
};

#endif