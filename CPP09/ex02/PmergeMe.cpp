/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:43:43 by mchesnea          #+#    #+#             */
/*   Updated: 2026/09/29 14:03:19 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vector(), _deque(), _time_vector(0), _time_deque(0) {
}

PmergeMe::PmergeMe(PmergeMe const &src) : _vector(src._vector), _deque(src._deque), _time_vector(src._time_vector), _time_deque(src._time_deque) {
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
    if (this != &rhs) {
        this->_vector = rhs._vector;
        this->_deque = rhs._deque;
        this->_time_vector = rhs._time_vector;
        this->_time_deque = rhs._time_deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {
}

int PmergeMe::_parsing(int ac, char *av[]){
    for (int i = 1; i < ac; i++) {
        for (int j = 0; av[i][j]; j++) {
            if (!std::isdigit(av[i][j]) && !(av[i][j] == '+' && j == 0)) {
                std::cerr << "Error" << std::endl;
		        return 1;
            }
        }
        char *end_ptr;
        long value = strtol(av[i], &end_ptr, 10);
        if (errno == ERANGE || end_ptr == av[i] || value > 2147483647) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }
    return 0;
}

void PmergeMe::_sort_vector() {
    std::vector< std::pair<int, int> > Vector_Pair;
    int odd = -1;
    int j = 0;
    if (_vector.size() % 2 != 0)
        odd = _vector.back();
    for (int i = 0; i+1 < (int)_vector.size(); i+=2){
        if (_vector[i] > _vector[i + 1])
           Vector_Pair.push_back(std::make_pair(_vector[i], _vector[i+1]));
        else
            Vector_Pair.push_back(std::make_pair(_vector[i+1], _vector[i]));
    }
    for (int i = 1; i < (int)Vector_Pair.size(); i++) {
        std::pair<int, int> temp = Vector_Pair[i];
        for (j = i-1; j >= 0 && Vector_Pair[j].first > temp.first ;j--)
            Vector_Pair[j + 1] = Vector_Pair[j];
        Vector_Pair[j + 1] = temp;
    }
    std::vector<int> main_chain;
    std::vector<int> pend;
    if (Vector_Pair.empty()){
        if (odd != -1)
            main_chain.push_back(odd);
    }
    else {
        main_chain.push_back(Vector_Pair[0].second);
        main_chain.push_back(Vector_Pair[0].first);
        for (int i = 1; i < (int)Vector_Pair.size(); i++){
            pend.push_back(Vector_Pair[i].second);
            main_chain.push_back(Vector_Pair[i].first);
        }
        if (odd != -1) {
            pend.push_back(odd);
        }
    }
    int prev_jacob = 1;
    int curr_jacob = 3;
    int next_jacob;
    while (prev_jacob - 1 < (int)pend.size()){
        int target = curr_jacob - 1;
        if (target > (int)pend.size())
            target = pend.size();
        for (int i = target - 1; i >= prev_jacob - 1; i--) {
            std::vector<int>::iterator temp = std::lower_bound(main_chain.begin(),main_chain.end(),pend[i]);
            main_chain.insert(temp, pend[i]);
        }
        next_jacob = curr_jacob + 2*prev_jacob;
        prev_jacob = curr_jacob;
        curr_jacob = next_jacob;
    }
    _vector = main_chain;
}

void PmergeMe::_sort_deque() {
    std::deque< std::pair<int, int> > Deque_Pair;
    int odd = -1;
    int j = 0;
    if (_deque.size() % 2 != 0)
        odd = _deque.back();
    for (int i = 0; i+1 < (int)_deque.size(); i+=2){
        if (_deque[i] > _deque[i + 1])
           Deque_Pair.push_back(std::make_pair(_deque[i], _deque[i+1]));
        else
            Deque_Pair.push_back(std::make_pair(_deque[i+1], _deque[i]));
    }
    for (int i = 1; i < (int)Deque_Pair.size(); i++) {
        std::pair<int, int> temp = Deque_Pair[i];
        for (j = i-1; j >= 0 && Deque_Pair[j].first > temp.first ;j--)
            Deque_Pair[j + 1] = Deque_Pair[j];
        Deque_Pair[j + 1] = temp;
    }
    std::deque<int> main_chain;
    std::deque<int> pend;
    if (Deque_Pair.empty()){
        if (odd != -1)
            main_chain.push_back(odd);
    }
    else {
        main_chain.push_back(Deque_Pair[0].second);
        main_chain.push_back(Deque_Pair[0].first);
        for (int i = 1; i < (int)Deque_Pair.size(); i++){
            pend.push_back(Deque_Pair[i].second);
            main_chain.push_back(Deque_Pair[i].first);
        }
        if (odd != -1) {
            pend.push_back(odd);
        }
    }
    int prev_jacob = 1;
    int curr_jacob = 3;
    int next_jacob;
    while (prev_jacob - 1 < (int)pend.size()){
        int target = curr_jacob - 1;
        if (target > (int)pend.size())
            target = pend.size();
        for (int i = target - 1; i >= prev_jacob - 1; i--) {
            std::deque<int>::iterator temp = std::lower_bound(main_chain.begin(),main_chain.end(),pend[i]);
            main_chain.insert(temp, pend[i]);
        }
        next_jacob = curr_jacob + 2*prev_jacob;
        prev_jacob = curr_jacob;
        curr_jacob = next_jacob;
    }
    _deque = main_chain;
}

void PmergeMe::_print(std::string txt){
    std::cout << txt;
    for (int i = 0; i < (int)_deque.size(); i++) {
        if (i > 9){
            std::cout << " " << "[...]";
            break;
        }
        std::cout << " " << _deque[i];
    }
    std::cout << std::endl;
}

void PmergeMe::processSorting(int ac, char *av[]){
    if (_parsing(ac, av) == 1)
        return;
    struct timeval s_vector, e_vector;
    struct timeval s_deque, e_deque;
    std::cout << "Before:";
    for (int i = 1; i < ac; i++) {
        if (i > 10) {
            std::cout << " [...]";
            break;
        }
        std::cout << " " << av[i];
    }
    std::cout << std::endl;
    gettimeofday(&s_vector, NULL);
    char *end_ptr;
    for (int i = 1; i < ac; i++) {
        long value = strtol(av[i], &end_ptr, 10);
        if (errno == ERANGE || end_ptr == av[i] || value > 2147483647) {
            std::cerr << "Error" << std::endl;
		    return;
        }
        _vector.push_back(value);
    }
    _sort_vector();
    gettimeofday(&e_vector, NULL);
    gettimeofday(&s_deque, NULL);
    char *end_ptr2;
    for (int i = 1; i < ac; i++) {
        long value = strtol(av[i], &end_ptr2, 10);
        if (errno == ERANGE || end_ptr2 == av[i] || value > 2147483647) {
            std::cerr << "Error" << std::endl;
		    return;
        }
        _deque.push_back(value);
    }
    _sort_deque();
    gettimeofday(&e_deque, NULL);
    _print("After:");
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << ((e_vector.tv_sec - s_vector.tv_sec) * 1000000) + (e_vector.tv_usec - s_vector.tv_usec) << " us" << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << ((e_deque.tv_sec - s_deque.tv_sec) * 1000000) + (e_deque.tv_usec - s_deque.tv_usec) << " us" << std::endl;
}