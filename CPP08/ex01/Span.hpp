/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:11:20 by mchesnea          #+#    #+#             */
/*   Updated: 2026/09/02 17:34:05 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _nb;
    public:
        Span();
        Span(unsigned int N);
        Span( Span const &src );
        Span &operator=( Span const & rhs );
        ~Span();

        void addNumber(int n);
        int shortestSpan() const;
        int longestSpan() const;

        class SpanFullException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
	    class NoSpanException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        template <typename InputIterator>
        void addRange(InputIterator begin, InputIterator end) {
            if (static_cast<unsigned int>(std::distance(begin, end)) + _nb.size() > _N)
                throw SpanFullException();
            _nb.insert(_nb.end(), begin, end);
        }
};

#endif