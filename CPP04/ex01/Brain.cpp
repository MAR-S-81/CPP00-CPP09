/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:37:47 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/09 13:48:19 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain( Brain const &src ) {
    std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
        this->ideas[i] = src.ideas[i];
    }
}

Brain &Brain::operator=( Brain const &rhs ) {
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &rhs) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = rhs.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}