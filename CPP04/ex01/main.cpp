/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:25:48 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/09 14:31:50 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	Animal *tab[4];

	for (int i = 0; i < 4; i++) {
		if (i < 4 / 2)
			tab[i] = new Dog();
		else
			tab[i] = new Cat();
	}
	Dog* originalDog = new Dog();
	Dog* copyDog = new Dog(*originalDog);

	delete originalDog;
    delete copyDog;

	for (int i = 0; i < 4; i++) {
        delete tab[i];
    }

	return 0;
}