/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:04:36 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/05 15:28:17 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap
{
private:
    std::string _name;
    unsigned int Hit;
    unsigned int Energy;
    unsigned int Attack;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap( ClapTrap const &src );
    ClapTrap &operator=( ClapTrap const & rhs );
    ~ClapTrap();

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif