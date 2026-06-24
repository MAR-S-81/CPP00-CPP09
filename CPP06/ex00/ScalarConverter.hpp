/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:57:17 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/24 15:12:48 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <string>
#include <climits>
#include <cctype>
#include <cstdlib>

class ScalarConverter
{
private:
	ScalarConverter();
    ScalarConverter( ScalarConverter const &src );
    ScalarConverter &operator=( ScalarConverter const & rhs );
    ~ScalarConverter();

public:
	static void convert(std::string str);
};

#endif