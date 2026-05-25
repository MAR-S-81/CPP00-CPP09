/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:22:37 by mchesnea          #+#    #+#             */
/*   Updated: 2026/05/25 15:27:30 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook monRepertoire; 
    std::string command;
    
    while (true)
    {
        std::cout << "Entrez une commande (ADD, SEARCH, EXIT) : ";
        std::getline(std::cin, command);
        if (std::cin.eof())
            break;
        if (command == "ADD")
            monRepertoire.Add(); 
        else if (command == "SEARCH")
            monRepertoire.Search();
        else if (command == "EXIT")
            break;
    }
    return 0;
}