/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:04:44 by mchesnea          #+#    #+#             */
/*   Updated: 2026/09/23 16:12:20 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char *av[])
{
    if (ac != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange bitcoin;
	try {
        bitcoin.processInput(av[1]);
    }
    catch (std::exception & e) {
        std::cerr << "Error : " << e.what() << std::endl;
		return 1;
    }
	return 0;
}
