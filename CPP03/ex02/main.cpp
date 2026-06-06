/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:04:44 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/06 16:49:09 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap ryu("Ryu");
    
    ScavTrap serena("Serena");
    serena.attack("Ryu");
    serena.guardGate();

    FragTrap cl4p_tp("CL4P-TP");

    cl4p_tp.attack("Serena");
    
    cl4p_tp.takeDamage(50);
    cl4p_tp.beRepaired(50);

    cl4p_tp.highFivesGuys();
    return 0;
}