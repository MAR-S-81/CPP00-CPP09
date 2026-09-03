/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:04:44 by mchesnea          #+#    #+#             */
/*   Updated: 2026/09/03 14:39:05 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>

int main()
{
    std::srand(std::time(NULL));
    
    std::vector<int> Vector;
    Vector.reserve(200);
    for (unsigned int i = 0; i < 200; ++i) {
        Vector.push_back(std::rand());
    }
    Vector.push_back(55);
	try { 
        std::vector<int>::iterator it =easyfind(Vector, 55);
        std::cout << *it << std::endl;;
    }
    catch (std::exception & e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }


    std::list<int> List;
    for (unsigned int i = 0; i < 200; ++i) {
        List.push_back(std::rand());
    }
	try {
        std::list<int>::iterator it =easyfind(List, -1);
        std::cout << *it << std::endl;;
    }
    catch (std::exception & e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }

	return 0;
}
