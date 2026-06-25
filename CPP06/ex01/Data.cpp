/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:43:05 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/25 12:54:59 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _id(0),  _name("Default")  {
}

Data::Data(int id, std::string name) : _id(id),  _name(name) {
}

Data::Data( Data const &src ) : _id(src._id), _name(src._name) {
}

Data &Data::operator=( Data const &rhs ) {
    if (this != &rhs) {
        this->_id = rhs._id;
		this->_name = rhs._name;
    }
    return *this;
}

Data::~Data(){
}

std::string Data::getName() const{
	return (this->_name);
}

int Data::getId() const{
	return (this->_id);
}