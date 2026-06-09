/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:01:29 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/09 18:43:47 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void){
	this->_name = "Default";
	for(int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(std::string const &name){
	this->_name = name;
	for(int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character( Character const &src ) {
    this->_name = src._name;
	for(int i = 0; i < 4; i++) {
		if(src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character &Character::operator=( Character const &rhs ) {
    if (this != &rhs) {
        this->_name = rhs._name;
		for(int i = 0; i < 4; i++) {
			if (_inventory[i])
				delete _inventory[i];
		}
		for(int i = 0; i < 4; i++) {
		if(rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
    }
    return *this;
}

Character::~Character() {
	for(int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const &Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria* m) {
	if (!m)
		return;
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			return;
		}	
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL) {
		this->_inventory[idx]->use(target);
	}
}