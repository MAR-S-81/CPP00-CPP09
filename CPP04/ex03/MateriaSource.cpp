/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:00:15 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/10 13:37:17 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void){
	for(int i = 0; i < 4; i++) {
		_sources[i] = NULL;
	}
}

MateriaSource::MateriaSource( MateriaSource const &src ) {
	for(int i = 0; i < 4; i++) {
		if(src._sources[i])
			this->_sources[i] = src._sources[i]->clone();
		else
			this->_sources[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=( MateriaSource const &rhs ) {
    if (this != &rhs) {
		for(int i = 0; i < 4; i++) {
			if (_sources[i])
				delete _sources[i];
		}
		for(int i = 0; i < 4; i++) {
		if(rhs._sources[i])
			this->_sources[i] = rhs._sources[i]->clone();
		else
			this->_sources[i] = NULL;
	}
    }
    return *this;
}

MateriaSource::~MateriaSource() {
	for(int i = 0; i < 4; i++) {
		if (_sources[i])
			delete _sources[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m)
		return;
	for(int i = 0; i < 4; i++) {
		if (this->_sources[i] == NULL) {
			this->_sources[i] = m;
			return;
		}	
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for(int i = 0; i < 4; i++) {
		if (this->_sources[i] != NULL)
			if (_sources[i]->getType() == type)
				return _sources[i]->clone();
	}
	return 0;
}