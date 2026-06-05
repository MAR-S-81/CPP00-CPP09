/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:39:22 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/05 17:55:03 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap 
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap( ScavTrap const &src );
    ScavTrap &operator=( ScavTrap const & rhs );
    ~ScavTrap();

    void attack(const std::string &target);
    void guardGate();
};

#endif