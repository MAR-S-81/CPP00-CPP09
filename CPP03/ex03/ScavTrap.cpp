/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:39:08 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/05 18:12:20 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    this->Hit = 100;
    this->Energy = 50;
    this->Attack = 20;
    std::cout << "ScavTrap " << _name << " is born from the ashes of a ClapTrap!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->Hit = 100;
    this->Energy = 50;
    this->Attack = 20;
    std::cout << "ScavTrap " << _name << " is born from the ashes of a ClapTrap!" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &src ) : ClapTrap(src) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=( ScavTrap const &rhs ) {
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap " << _name << " has been destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (Hit <= 0) {
        std::cout << "ScavTrap " << _name << " is dead." << std::endl;
        return;
    }
    if (Energy <= 0) {
        std::cout << "ScavTrap " << _name << " has no more energy." << std::endl;
        return;
    }
    Energy--;
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << Attack << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(){
    if (this->Hit <= 0) {
        std::cout << "ScavTrap " << this->_name << " is dead and cannot guard the gate." << std::endl;
        return;
    }
    if (this->Energy <= 0) {
        std::cout << "ScavTrap " << this->_name << " is out of energy and cannot guard the gate." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}