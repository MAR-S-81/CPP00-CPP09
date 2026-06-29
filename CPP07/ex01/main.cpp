/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:04:44 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/29 13:17:30 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printElement(const T& x) {
    std::cout << x << " . ";
}


int main() {
	
	int tab[5] = {1, 2, 5, 10, 29};
    ::iter(tab, 5, ::printElement<int>);
    std::cout << std::endl;

    std::string tab2[3] = {"Hello", "the", "world"};
    ::iter(tab2, 3, ::printElement<std::string>);
    std::cout << std::endl;
	
	return 0;
}