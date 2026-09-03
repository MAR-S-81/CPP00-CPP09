/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:11:13 by mchesnea          #+#    #+#             */
/*   Updated: 2026/09/02 17:48:51 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0), _nb(){
}

Span::Span(unsigned int N) : _N(N), _nb() {
}

Span::Span( Span const &src ) : _N(src._N), _nb(src._nb) {
}

Span &Span::operator=( Span const &rhs ) {
    if (this != &rhs) {
        this->_N = rhs._N;
        this->_nb = rhs._nb;
    }
    return *this;
}

Span::~Span(){
}


void Span::addNumber(int n) {
    if (_nb.size() + 1 > _N)
        throw Span::SpanFullException();
    _nb.push_back(n);
}

int Span::shortestSpan() const {
    if (_nb.size() <= 1)
        throw Span::NoSpanException();
    std::vector<int> temp = _nb;
    std::sort(temp.begin(), temp.end());
    int ret = temp[1] - temp[0];
    for (size_t i = 2; i < temp.size(); i++) {
        if (temp[i] - temp[i - 1] < ret)
            ret = temp[i] - temp[i - 1];
    }
    return ret;
}

int Span::longestSpan() const {
    if (_nb.size() <= 1)
        throw Span::NoSpanException();
    int max = *std::max_element(_nb.begin(), _nb.end());
    int min = *std::min_element(_nb.begin(), _nb.end());
    return (max - min);
}

const char* Span::SpanFullException::what() const throw() {
	return "Span is full !";
}

const char* Span::NoSpanException::what() const throw() {
	return "Span doesn't exist !";
}