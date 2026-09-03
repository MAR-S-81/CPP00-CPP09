/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:06:59 by mchesnea          #+#    #+#             */
/*   Updated: 2026/09/03 15:42:52 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>


template <typename T>
class MutantStack : public std::stack<T>
{
private:

public:
    MutantStack(){
    }
    MutantStack( MutantStack const &src ): std::stack<T>(src) {
    }
    MutantStack &operator=( MutantStack const & rhs ){
        if (this != &rhs) {
           std::stack<T>::operator=(rhs);
        }
        return *this;
    }
    ~MutantStack() {
    }

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() {
        return this->c.begin();
    }
    iterator end() {
        return this->c.end();
    }
};



#endif