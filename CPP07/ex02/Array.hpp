/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:30:55 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/29 16:14:03 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{
private:
	T* _elements;
	unsigned int _n;
public:
	Array();
	Array(unsigned int n);
    Array( Array const &src );
    Array &operator=( Array const & rhs );
    ~Array();

	T &operator[](unsigned int i);
	const T &operator[](unsigned int i) const ;

	unsigned int size() const;
};


#include "Array.tpp"

#endif