/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:04:19 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/05 18:04:26 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("DefaultRobot"), Hit(10), Energy(10), Attack(0) {
    std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), Hit(10), Energy(10), Attack(0) {
    std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &src ) {
    this->_name = src._name;
    this->Hit = src.Hit;
    this->Energy = src.Energy;
    this->Attack = src.Attack;
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=( ClapTrap const &rhs ) {
    if (this != &rhs) {
        this->_name = rhs._name;
        this->Hit = rhs.Hit;
        this->Energy = rhs.Energy;
        this->Attack = rhs.Attack;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << _name << " has been destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (Hit <= 0) {
        std::cout << "ClapTrap " << _name << " is dead." << std::endl;
        return;
    }
    if (Energy <= 0) {
        std::cout << "ClapTrap " << _name << " has no more energy." << std::endl;
        return;
    }
    Energy--;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << Attack << " points of damage!" << std::endl;
}
    
void ClapTrap::takeDamage(unsigned int amount){
    if (Hit <= 0) {
        std::cout << "ClapTrap " << _name << " is dead." << std::endl;
        return;
    }
    if (amount >= Hit)
        Hit = 0;
    else
        Hit -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}
    
void ClapTrap::beRepaired(unsigned int amount){
    if (Hit <= 0) {
        std::cout << "ClapTrap " << _name << " is dead." << std::endl;
        return;
    }
    if (Energy <= 0) {
        std::cout << "ClapTrap " << _name << " has no more energy." << std::endl;
        return;
    }
    if (Hit + amount < Hit) {
        Hit = 4294967295;
    } else {
        Hit += amount;
    }
    std::cout << "ClapTrap " << _name << " has recovered " << amount << " hp!" << std::endl;
    Energy--;
}