/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:04:44 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/23 13:50:56 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    
	try {
        Bureaucrat hercule("Hercule", 2);
        std::cout << hercule << std::endl;
        ++hercule;
        std::cout << hercule << std::endl;
        --hercule;
        std::cout << hercule << std::endl;
    }
    catch (std::exception & e) {
        std::cerr << "Erreur inattendue : " << e.what() << std::endl;
    }

	
    try {
        Bureaucrat boss("Le Boss", 0);
        std::cout << boss << std::endl;
    }
    catch (std::exception & e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }
	
	
    try {
        Bureaucrat dieu("Hermès", 150);
        std::cout << dieu << std::endl;
        --dieu;
    }
    catch (std::exception & e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }
    return (0);
}