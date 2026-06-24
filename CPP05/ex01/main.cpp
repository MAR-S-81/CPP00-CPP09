/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:04:44 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/24 18:17:00 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    
	try 
    {
        Bureaucrat alice("Alice", 10);
        Form tax("Tax Return 28B", 15, 50);
        
        std::cout << alice << std::endl;
        std::cout << tax << std::endl;
        
        alice.signForm(tax);
        
        std::cout << tax << std::endl;
    }
    catch (std::exception & e) 
    {
        std::cerr << "Erreur inattendue : " << e.what() << std::endl;
    }


	try 
    {
        Bureaucrat bob("Bob", 50);
        Form topSecret("Top Secret Clearance", 10, 10);
        
        std::cout << bob << std::endl;
        std::cout << topSecret << std::endl;
        
        bob.signForm(topSecret); 
        
        std::cout << topSecret << std::endl;
    }
    catch (std::exception & e) 
    {
        std::cerr << "Erreur inattendue : " << e.what() << std::endl;
    }
    return (0);
}