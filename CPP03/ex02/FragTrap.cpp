/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:35:38 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/06 16:47:43 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
    this->Hit = 100;
    this->Energy = 100;
    this->Attack = 30;
    std::cout << "FragTrap " << _name << " is born from the ashes of a ClapTrap!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->Hit = 100;
    this->Energy = 100;
    this->Attack = 30;
    std::cout << "FragTrap " << _name << " is born from the ashes of a ClapTrap!" << std::endl;
}

FragTrap::FragTrap( FragTrap const &src ) : ClapTrap(src) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=( FragTrap const &rhs ) {
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap " << _name << " has been destroyed." << std::endl;
}

void FragTrap::highFivesGuys() {
    if (this->Hit <= 0) {
        std::cout << "FragTrap " << this->_name << " is dead and cannot request high-fives." << std::endl;
        return;
    }
    if (this->Energy <= 0) {
        std::cout << "FragTrap " << this->_name << " is out of energy and cannot request high-fives." << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->_name << " says: HEY GUYS! GIMME A HIGH-FIVE!" << std::endl;
}