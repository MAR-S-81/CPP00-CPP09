/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:36:05 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/06 16:43:11 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap 
{
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap( FragTrap const &src );
    FragTrap &operator=( FragTrap const & rhs );
    ~FragTrap();

    void highFivesGuys(void);
};

#endif