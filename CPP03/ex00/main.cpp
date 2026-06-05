/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:04:44 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/05 17:21:51 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
    
    return 0;
}