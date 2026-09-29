/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:43:43 by mchesnea          #+#    #+#             */
/*   Updated: 2026/09/23 19:26:59 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _bdd() {
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _bdd(src._bdd) {
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
    if (this != &rhs) {
        this->_bdd = rhs._bdd;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

bool BitcoinExchange::_isDateValid(std::string const &str) const {
    if (str.length() != 10 || str[4] != '-' || str[7] != '-') {
        std::cout << "Error: bad input => " << str << std::endl;
        return false;
    }
    for (int i = 0; str[i]; i++) {
        if (!std::isdigit(str[i]) && (i != 4 && i != 7)) {
            std::cout << "Error: bad input => " << str << std::endl;
            return false;
        }
    }
    std::string years = str.substr(0,4);
    std::string month = str.substr(5,2);
    std::string days = str.substr(8,2);
    int y = std::atoi(years.c_str());
    int m = std::atoi(month.c_str());
    int d = std::atoi(days.c_str());
    if ((y < 2009) || (y == 2009 && m == 1 && d < 2)) {
        std::cout << "Error: bad input => " << str << std::endl;
        return false; 
    }
    if (m < 1 || m > 12) {
        std::cout << "Error: bad input => " << str << std::endl;
        return false; 
    }
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
        if (d < 1 || d > 31){
            std::cout << "Error: bad input => " << str << std::endl;
            return false; 
        }
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11){
        if (d < 1 || d > 30){
            std::cout << "Error: bad input => " << str << std::endl;
            return false; 
        } 
    }
    else {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            if (d < 1 || d > 29){
                std::cout << "Error: bad input => " << str << std::endl;
                return false;
            }
        }
        else {
            if (d < 1 || d > 28){
                std::cout << "Error: bad input => " << str << std::endl;
                return false;
            }
        }
    }
    return true;
}


bool BitcoinExchange::_isNbValid(std::string const &nb) const {
    int p = 0;
    int sign = 0;
    if ((nb.length() == 1 && !std::isdigit(nb[0])) || nb.empty()){
        std::cout << "Error: bad input => " << nb << std::endl;
        return false;
    }
    while(std::isspace(nb[sign])) {
        sign++;
    }
    for (int i = sign; nb[i]; i++) {
        if (nb[i] == '.')
            p++;
        if (!(std::isdigit(nb[i]) || nb[i] == '.'|| ((nb[i] == '+' || nb[i] == '-') && i == sign)) || p > 1){
                std::cout << "Error: bad input => " << nb << std::endl;
                return false;
            }
    }
    const char* cnb = nb.c_str();
    char* end = NULL;
    errno = 0;
    double val = std::strtod(cnb, &end);
    if (cnb == end || errno == ERANGE){
        std::cout << "Error: bad input => " << nb << std::endl;
        return false;
    }
    while (*end && std::isspace(static_cast<unsigned char>(*end))) {
        ++end;
    }
    if (*end != '\0') {
        std::cout << "Error: bad input => " << nb << std::endl;
        return false;
    }
    if (val < 0){
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (val > 1000){
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::_loadDB() {
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cout << "Error: could not open file." << std::endl;
        return false;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)){
        size_t found = line.find(',');
        if (found == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            return false;
        }
        std::string date = line.substr(0, found);
        std::string value = line.substr(found + 1);
        const char* cval = value.c_str();
        char* end = NULL;
        errno = 0;
        double val = std::strtod(cval, &end);
        if (cval == end || errno == ERANGE){
            std::cout << "Error: database has problem." << std::endl;
            return false;
        }
        while (*end && std::isspace(static_cast<unsigned char>(*end))) {
            ++end;
        }
        if (*end != '\0') {
            std::cout << "Error: database has problem."<< std::endl;
            return false;
        }
        _bdd[date] = val;
    }
    return true;
}

const char* BitcoinExchange::NoFoundDB::what() const throw() {
	return "DataBase not found !";
}

void BitcoinExchange::processInput(std::string const &name) {
    if (_loadDB() == false)
        throw BitcoinExchange::NoFoundDB();
    std::ifstream file(name.c_str());
    if (!file.is_open()) {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)){
        if (line == "date | value")
            continue;
        size_t found = line.find('|');
        if (found == std::string::npos || found == 0 || line.length() < 14 || line[found - 1] != ' ' || line[found + 1] != ' ' ) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, found - 1);
        std::string value = line.substr(found + 2);
        if (_isDateValid(date) == false || _isNbValid(value) == false)
            continue;
        const char* cval = value.c_str();
        char* end = NULL;
        errno = 0;
        double val = std::strtod(cval, &end);
        if (cval == end || errno == ERANGE){
            std::cout << "Error: bad input or invalid value." << std::endl;
            continue;
        }
        while (*end && std::isspace(static_cast<unsigned char>(*end))) {
            ++end;
        }
        if (*end != '\0') {
            std::cout << "Error: bad input or invalid value." << std::endl;
            continue;
        }
        std::map<std::string, double>::iterator it = _bdd.lower_bound(date);
        if (it == _bdd.end()){
            --it;
            std::cout << date << " => " << val << " = " << val * it->second << std::endl;
        }
        else if (it->first == date)
            std::cout << date << " => " << val << " = " << val * it->second << std::endl;
        else if (it == _bdd.begin())
           std::cout << "Error: date is too early (no lower date found)." << std::endl;
        else{
            --it;
            std::cout << date << " => " << val << " = " << val * it->second << std::endl;
        }
    }
}