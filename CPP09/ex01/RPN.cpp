/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:43:43 by mchesnea          #+#    #+#             */
/*   Updated: 2026/09/24 15:48:17 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _stack() {
}

RPN::RPN(RPN const &src) : _stack(src._stack) {
}

RPN &RPN::operator=(RPN const &rhs) {
    if (this != &rhs) {
        this->_stack = rhs._stack;
    }
    return *this;
}

RPN::~RPN() {
}

const char* RPN::DivisionBy0::what() const throw() {
	return "Dividing By 0 Is Impossible !";
}

int RPN::_exec(char sign) {
    int nb1 = _stack.top();
    _stack.pop();
    int nb2 = _stack.top();
    _stack.pop();
    if (sign == '+')
        return nb2 + nb1;
    if (sign == '-')
        return nb2 - nb1;
    if (sign == '*')
        return nb2 * nb1;
    if (sign == '/'){
        if (nb1 == 0)
            throw RPN::DivisionBy0();
        return nb2 / nb1;
    }
    return 0;
}

void RPN::processExpression(std::string arg){
    for (int i = 0; arg[i]; i++) {
        if (std::isspace(arg[i]))
            continue;
        if (std::isdigit(arg[i])){
            if (arg[i + 1] != '\0' && std::isdigit(arg[i + 1])) {
                std::cerr << "Error\n";
                return;
            }
            _stack.push(arg[i] - '0');
            continue;
        }
        if (arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/') {
            if (_stack.size() < 2){
                std::cerr << "Error\n";
                return;
            }
            try {
                _stack.push(_exec(arg[i]));
            }
            catch (std::exception & e) {
                std::cerr << "Error : " << e.what() << std::endl;
		        return;
            }
        }
        else {
            std::cerr << "Error\n";
            return;
        }
    }
    if (_stack.size() != 1) {
        std::cerr << "Error\n";
        return;
    }
    std::cout << _stack.top() << std::endl;
    return;
}