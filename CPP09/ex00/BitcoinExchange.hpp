/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:06:59 by mchesnea          #+#    #+#             */
/*   Updated: 2026/09/23 19:26:14 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <fstream>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _bdd;
        bool _isDateValid(std::string const &str) const;
        bool _isNbValid(std::string const &nb) const;
        bool _loadDB();
        
    public:
        BitcoinExchange();
        BitcoinExchange( BitcoinExchange const &src );
        BitcoinExchange &operator=( BitcoinExchange const & rhs );
        ~BitcoinExchange();

        void processInput(std::string const &name);

        class NoFoundDB : public std::exception {
        public:
            virtual const char* what() const throw();
        };
};


#endif