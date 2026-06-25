/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:43:14 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/25 11:51:44 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>

class Data
{
private:
	int _id;
	std::string _name;
public:
	Data();
	Data(int id, std::string name);
    Data( Data const &src );
    Data &operator=( Data const & rhs );
    ~Data();

	int getId() const;
	std::string getName() const;
};

#endif