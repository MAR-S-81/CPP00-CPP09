/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:04:44 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/24 14:09:36 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    
	std::srand(time(NULL));

	try 
    {
        Bureaucrat stagiaire("Stagiaire", 150);
        ShrubberyCreationForm arbre("Jardin");
        
        stagiaire.signForm(arbre);
        stagiaire.executeForm(arbre);
    } 
    catch (std::exception &e) 
    {
        std::cout << "Main a attrapé une exception : " << e.what() << std::endl;
    }


	try 
    {
        Bureaucrat patron("Patron", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        
        patron.executeForm(pardon);
    } 
    catch (std::exception &e) 
    {
        std::cout << "Main a attrapé une exception : " << e.what() << std::endl;
    }
	

	try 
    {
        Bureaucrat patron("Patron", 1);
        ShrubberyCreationForm arbre("Maison");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        patron.signForm(arbre);
        patron.signForm(robot);
        patron.signForm(pardon);

        patron.executeForm(arbre);

        patron.executeForm(robot);
        patron.executeForm(robot);
        patron.executeForm(robot);

        patron.executeForm(pardon);
    } 
    catch (std::exception &e) 
    {
        std::cout << "Main a attrapé une exception : " << e.what() << std::endl;
    }

	return (0);
}