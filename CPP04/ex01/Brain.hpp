/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:37:59 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/09 13:44:55 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>

class Brain
{
	private :
		std::string ideas[100];
    public:
        Brain();
        Brain( Brain const &src );
        Brain &operator=( Brain const & rhs );
        ~Brain();
        
};

#endif