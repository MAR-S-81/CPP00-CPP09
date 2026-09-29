/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:06:59 by mchesnea          #+#    #+#             */
/*   Updated: 2026/09/24 14:57:46 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
private:
    std::stack<int> _stack;
    int _exec(char sign);
public:
    RPN();
    RPN( RPN const &src );
    RPN &operator=( RPN const & rhs );
    ~RPN();
    
    void processExpression(std::string arg);

    class DivisionBy0 : public std::exception {
        public:
            virtual const char* what() const throw();
        };
};

#endif