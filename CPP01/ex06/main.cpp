/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:38:22 by mchesnea          #+#    #+#             */
/*   Updated: 2026/05/28 16:07:28 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char *av[]) {
    if (ac != 2) {
        std::cerr << "Error: Bad number of arguments." << std::endl;
        return 1;
    }
	int index = -1;
    Harl harl;
    std::string level = av[1];
    if (level == "DEBUG")
        index = 0;
    else if (level == "INFO")
        index = 1;
    else if (level == "WARNING")
        index = 2;
    else if (level == "ERROR")
        index = 3;
    switch (index)
    {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("DEBUG");
            std::cout << std::endl;
            /* fallthrough */
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            harl.complain("INFO");
            std::cout << std::endl;
            /* fallthrough */
        case 2:
        std::cout << "[ WARNING ]" << std::endl;
            harl.complain("WARNING");
            std::cout << std::endl; 
            /* fallthrough */
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain("ERROR");
            std::cout << std::endl; 
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return 0;
}
