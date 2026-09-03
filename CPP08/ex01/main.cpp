/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:04:44 by mchesnea          #+#    #+#             */
/*   Updated: 2026/09/02 17:57:39 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try {
        Span sp2 = Span(2);
        sp2.addNumber(6);
		sp2.addNumber(3);
		sp2.addNumber(17);
		sp2.addNumber(9);
		sp2.addNumber(11);
    }
    catch (std::exception & e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }

	try {
        Span sp3 = Span(1);
		sp3.longestSpan();
    }
    catch (std::exception & e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }

	try {
        Span sp4 = Span(1);
		sp4.shortestSpan();
    }
    catch (std::exception & e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }

	std::srand(std::time(NULL));
	try
    {
        const unsigned int N = 20000;
        Span sp5(N);
        std::vector<int> bigVector;
        bigVector.reserve(N);
        for (unsigned int i = 0; i < N; ++i)
            bigVector.push_back(std::rand());
        sp5.addRange(bigVector.begin(), bigVector.end());
        std::cout << "Shortest span : " << sp5.shortestSpan() << std::endl;
        std::cout << "Longest span  : " << sp5.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }

	return 0;
}