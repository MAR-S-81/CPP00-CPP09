/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:38:22 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/02 14:01:12 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include "Point.hpp"

int main( void ) {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    Point inside(2.0f, 2.0f);
    Point outside(10.0f, 10.0f);
    Point edge(5.0f, 5.0f);

    std::cout << "Point a l'interieur (attendu: 1) -> " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Point a l'exterieur (attendu: 0) -> " << bsp(a, b, c, outside) << std::endl;
    std::cout << "Point sur l'arete   (attendu: 0) -> " << bsp(a, b, c, edge) << std::endl;

    return 0;
}