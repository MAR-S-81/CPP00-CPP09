/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:06:59 by mchesnea          #+#    #+#             */
/*   Updated: 2026/09/03 14:28:02 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>


class NoFoundException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Exception Not Found !";
        }
};

template <typename T> 
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator temp = std::find(container.begin(), container.end(), value);
    if (temp == container.end())
        throw NoFoundException();
    return temp;
}

#endif