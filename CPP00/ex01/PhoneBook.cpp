/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:24:44 by mchesnea          #+#    #+#             */
/*   Updated: 2026/05/25 15:18:56 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
{
    i = 0;
}

void PhoneBook::Add()
{
    tab[i].FillContact();
    i++;
    if (i >= 8)
        i = 0;
}

std::string Trunc(std::string str)
{
    if (str.length() >= 10)
        str = str.substr(0, 9) + '.';
    return (str);
}

void PhoneBook::Search()
{
    int nb;

    std::string input;
    for (int j = 0; j < 8; j++)
    {
        if (!tab[j].getFirstName().empty())
        {
            std::cout << std::setw(10) << j << "|";
            std::cout << std::setw(10) << Trunc(tab[j].getFirstName()) << "|";
            std::cout << std::setw(10) << Trunc(tab[j].getLastName()) << "|";
            std::cout << std::setw(10) << Trunc(tab[j].getNickname()) << "|" << std::endl;
        }
    }
    std::getline(std::cin, input);
    if (input[0] >= '0' && input[0] <= '7' && input.length() == 1)
    {
        nb = input[0] - '0';
        if (!tab[nb].getFirstName().empty())
        {
            std::cout << tab[nb].getFirstName() << std::endl;
            std::cout << tab[nb].getLastName() << std::endl;
            std::cout << tab[nb].getNickname() << std::endl;
            std::cout << tab[nb].getPhoneNumber() << std::endl;
            std::cout << tab[nb].getDarkestSecret() << std::endl;
        }
        else
            std::cout << "Error : Contact is clear." << std::endl;
    }
    else
        std::cout << "Error : Invalid index." << std::endl;
}
