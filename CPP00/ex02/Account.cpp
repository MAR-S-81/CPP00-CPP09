/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:47:54 by mchesnea          #+#    #+#             */
/*   Updated: 2026/05/25 18:41:13 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

Account::Account(int initial_deposit) {
    _accountIndex = getNbAccounts();
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout <<"index:"<< _accountIndex <<";amount:"<< _amount << ";created" << std::endl;
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout <<"index:"<< _accountIndex <<";amount:"<< _amount << ";closed" << std::endl;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout <<"index:"<< _accountIndex <<";amount:"<< _amount << ";deposits:"<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    int prev = _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount+= deposit;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout <<"index:"<< _accountIndex <<";p_amount:"<< prev << ";deposit:"<< deposit << ";amount:"<< _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    if (withdrawal > _amount)
    {
        _displayTimestamp();
        std::cout <<"index:"<< _accountIndex <<";p_amount:"<< _amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    else
    {
        int prev = _amount;
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        _displayTimestamp();
        std::cout <<"index:"<< _accountIndex <<";p_amount:"<< prev << ";withdrawal:"<< withdrawal << ";amount:"<< _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }
}

int Account::checkAmount(void) const {
    return(_amount);
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
     std::cout <<"accounts:"<< _nbAccounts <<";total:"<< _totalAmount << ";deposits:"<< _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buf[20];
    strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", ltm);
    std::cout << "[" << buf << "] ";
}