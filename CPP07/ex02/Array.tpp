/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:29:18 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/29 16:16:15 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _elements(NULL), _n(0) {
}

template <typename T>
Array<T>::Array(unsigned int grade) {
	_n = grade;
	_elements = new T[_n]();
}

template <typename T>
Array<T>::Array(Array<T> const & src) {
	this->_n = src._n;
	this->_elements = new T[src._n]();
	for (unsigned int i = 0; i < this->_n; i++) {
		this->_elements[i] = src._elements[i];
	}
}

template <typename T>
Array<T> & Array<T>::operator=(Array<T> const & rhs) {
	if (this != &rhs) {
		delete[] this->_elements;
		
        this->_n = rhs._n;
		this->_elements = new T[this->_n]();

		for (unsigned int i = 0; i < this->_n; i++) {
            this->_elements[i] = rhs._elements[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] this->_elements;
}

template <typename T>
unsigned int Array<T>::size() const {
    return this->_n;
}

template <typename T>
T & Array<T>::operator[](unsigned int i) {
	if (i >= this->_n) {
		throw std::out_of_range("Index out of bounds");
	}
	return this->_elements[i];
}

template <typename T>
const T & Array<T>::operator[](unsigned int i) const {
	if (i >= this->_n) {
		throw std::out_of_range("Index out of bounds");
	}
	return this->_elements[i];
}
