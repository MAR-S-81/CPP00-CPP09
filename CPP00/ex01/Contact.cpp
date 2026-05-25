/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:49:50 by mchesnea          #+#    #+#             */
/*   Updated: 2026/05/25 15:17:20 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::FillContact()
{
	while (FirstName.empty() || LastName.empty() || Nickname.empty()
		|| PhoneNumber.empty() || DarkestSecret.empty())
	{
		if (FirstName.empty())
		{
			std::cout << "Enter The FirstName" << std::endl;
			std::getline(std::cin, FirstName);
			if (std::cin.eof())
				return ;
		}
		if (LastName.empty())
		{
			std::cout << "Enter The LastName" << std::endl;
			std::getline(std::cin, LastName);
			if (std::cin.eof())
				return ;
		}
		if (Nickname.empty())
		{
			std::cout << "Enter The Nickname" << std::endl;
			std::getline(std::cin, Nickname);
			if (std::cin.eof())
				return ;
		}
		if (PhoneNumber.empty())
		{
			std::cout << "Enter The PhoneNumber" << std::endl;
			std::getline(std::cin, PhoneNumber);
			if (std::cin.eof())
				return ;
		}
		if (DarkestSecret.empty())
		{
			std::cout << "Enter The DarkestSecret" << std::endl;
			std::getline(std::cin, DarkestSecret);
			if (std::cin.eof())
				return ;
		}
	}
}

std::string Contact::getFirstName() {
    return (FirstName);
}

std::string Contact::getLastName() {
    return (LastName);
}

std::string Contact::getNickname() {
    return (Nickname);
}

std::string Contact::getPhoneNumber() {
    return (PhoneNumber);
}

std::string Contact::getDarkestSecret() {
    return (DarkestSecret);
}