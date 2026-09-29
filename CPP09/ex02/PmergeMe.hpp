/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:06:59 by mchesnea          #+#    #+#             */
/*   Updated: 2026/09/29 13:09:12 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <cstdlib>
#include <cerrno>
#include <algorithm>

class PmergeMe
{
private:
    std::vector<int> _vector;
    std::deque<int> _deque;
    double _time_vector;
    double _time_deque;

    int _parsing(int ac, char *av[]);
    void _sort_vector();
    void _sort_deque();
    void _print(std::string txt);
public:
    PmergeMe();
    PmergeMe( PmergeMe const &src );
    PmergeMe &operator=( PmergeMe const & rhs );
    ~PmergeMe();

    void processSorting(int ac, char *av[]);
};


#endif