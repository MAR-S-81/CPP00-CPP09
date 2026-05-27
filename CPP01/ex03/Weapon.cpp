/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:23:11 by mchesnea          #+#    #+#             */
/*   Updated: 2026/05/27 16:09:30 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	Weapon::_type = type;
}

Weapon::~Weapon() {
}

const std::string &Weapon::getType() {
	return(Weapon::_type);
}

void Weapon::setType(std::string new_weapon) {
	Weapon::_type = new_weapon;
}