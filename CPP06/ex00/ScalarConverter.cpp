/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:57:27 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/24 18:13:50 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter( ScalarConverter const &src ){
	(void)src;
}

ScalarConverter &ScalarConverter::operator=( ScalarConverter const &rhs ) {
	(void)rhs;
    return *this;
}

ScalarConverter::~ScalarConverter(){
}

bool IsInt(std::string str)
{
	for(int i = 0; str[i]; i++)
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
            continue;
        if (!isdigit(str[i]))
            return false;
	}
	return true;
}

bool IsFloat(std::string str)
{
    if (str.length() < 4 || str[str.length() - 1] != 'f')
        return false;

	int start = 0;
    bool hasDot = false;
    if (str[0] == '+' || str[0] == '-')
		start = 1;

    for (int i = start; i < (int)str.length() - 1; i++) {
        if (str[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (!isdigit(str[i])) {
            return false;
        }
    }
    return hasDot;
}

bool IsDouble(std::string str)
{
    if (str.length() < 3)
        return false;

    bool hasDot = false;
    int start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;

    for (int i = start; i < (int)str.length(); i++) {
        if (str[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (!isdigit(str[i])) {
            return false;
        }
    }
    return hasDot;
}

void ScalarConverter::convert(std::string str) {
	if (str == "nan" || str == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (str == "+inf" || str == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return;
	}
	if (str == "-inf" || str == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}
	char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
	if (str.length() == 1 && !isdigit(str[0])) {
		c = str[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
		std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
		std::cout << "float:  " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0"  <<std::endl;
		return;
	}
	if (IsInt(str) == true) {
		long l = std::strtol(str.c_str(), NULL, 10);
        if (l < INT_MIN || l > INT_MAX) {
            std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
        	std::cout << "float: " << static_cast<float>(l) << ".0f" << std::endl;
        	std::cout << "double: " << static_cast<double>(l) << ".0" << std::endl;
        	return;
        }
		i = static_cast<int>(l);
    	c = static_cast<char>(i);
        f = static_cast<float>(l);
        d = static_cast<double>(l);
		if (!std::isprint(c))
        	std::cout << "char: Non displayable" << std::endl;
    	else
        	std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
		std::cout << "float:  " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
		return;
	}
	if (IsFloat(str) == true) {
        f = static_cast<float>(std::strtod(str.c_str(), NULL));
        d = static_cast<double>(f);
        if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX)) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            return;
        } 
        else {
            int i = static_cast<int>(f);
            char c = static_cast<char>(i);
            if (i < 0 || i > 127)
                std::cout << "char: impossible" << std::endl;
            else if (!std::isprint(c))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << c << "'" << std::endl;

            std::cout << "int: " << i << std::endl;
        }
        if (f == static_cast<int>(f)) {
            std::cout << "float: " << f << ".0f" << std::endl;
            std::cout << "double: " << d << ".0" << std::endl;
        } else {
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        }
        return;
	}
	if (IsDouble(str) == true) {
        d = std::strtod(str.c_str(), NULL);
        f = static_cast<float>(d);
        if (d < INT_MIN || d > INT_MAX) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            return;
        } 
        else {
            int i = static_cast<int>(d);
            char c = static_cast<char>(i);
            if (i < 0 || i > 127)
                std::cout << "char: impossible" << std::endl;
            else if (!std::isprint(c))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << c << "'" << std::endl;

            std::cout << "int: " << i << std::endl;
        }
        
        if (d == static_cast<int>(d)) {
            std::cout << "float: " << f << ".0f" << std::endl;
            std::cout << "double: " << d << ".0" << std::endl;
        } else {
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        }
        return;
    }
	std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}