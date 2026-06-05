/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:04:44 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/05 18:17:06 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    
    ClapTrap ryu("Ryu");
    ClapTrap ken("Ken");
    ClapTrap sacDeFrappe;

    for (int i = 0; i < 11; i++) {
        std::cout << "Attaque " << i + 1 << " : ";
        ryu.attack("Ken");
    }

    ken.takeDamage(5);
    ken.beRepaired(3);
    ken.takeDamage(15);

    ken.attack("Ryu");
    ken.takeDamage(5);
    ken.beRepaired(10);

    sacDeFrappe.beRepaired(4294967295);
    ScavTrap serena("Serena");
    
    serena.attack("Ryu"); 
    serena.takeDamage(50);
    serena.beRepaired(25);

    serena.guardGate();
    
    return 0;
}