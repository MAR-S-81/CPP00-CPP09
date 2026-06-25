/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:43:16 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/25 16:31:25 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	int i = std::rand() % 3;
	if (i == 0) {
		return new A();
	}
	if (i == 1) {
		return new B();
	}
	else {
		return new C();
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "C" << std::endl;
	}
}

void identify(Base &p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (const std::exception& e) {
	}
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (const std::exception& e) {
	}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (const std::exception& e) {
	}
}

int main () {
	
	std::srand(time(NULL));
	
	Base* ptr = generate();
	identify(ptr);
	identify(*ptr);

	delete ptr;

	return 0;
}