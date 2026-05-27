/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:02:53 by mchesnea          #+#    #+#             */
/*   Updated: 2026/05/27 13:51:04 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::string name = "Léo";
	int	N = 5;
	Zombie *tab = zombieHorde(N,name);
	for (int i = 0; i < N; i++) {
		tab[i].announce();
	}
	delete[] tab;
}