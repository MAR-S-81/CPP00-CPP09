/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:30:55 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/29 12:47:36 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T &min(const T & a, const T & b) {
	if (a < b)
		return a;
	else 
		return b;
}

template <typename T>
const T &max(const T & a, const T & b) {
	if (a > b)
		return a;
	else 
		return b;
}

#endif