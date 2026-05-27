/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:23:48 by mchesnea          #+#    #+#             */
/*   Updated: 2026/05/27 16:12:09 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	HumanB::_name = name;
	HumanB::_weapon = NULL;
}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon &weapon) {
	HumanB::_weapon = &weapon;
}

void HumanB::attack(void){
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon to attack with!" << std::endl;
}