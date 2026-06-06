/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:54:20 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/06 17:41:04 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap("Default"), FragTrap("Default"), _name("Default") {
    this->Hit = 100;
    this->Energy = 50;
    this->Attack = 30;
    std::cout << "DiamondTrap " << _name << " is born from the ashes of a ScavTrap and a FragTrap!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name){
    this->Hit = 100;
    this->Energy = 50;
    this->Attack = 30;
    std::cout << "DiamondTrap " << _name << " is born from the ashes of a ScavTrap and a FragTrap!" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const &src ) : ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name){
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=( DiamondTrap const &rhs ) {
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
        this->_name = rhs._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap " << _name << " has been destroyed." << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << this->_name << ", and my ClapTrap name is " << ClapTrap::_name << "!" << std::endl;
}
