#include <cstdio>
#include <ctime>
#include <locale>
#include <iostream>
#include <string>
#include "Account.hpp"

int	Account::getNbAccounts(void) { return Account::_nbAccounts; }

int	Account::getTotalAmount(void) { return Account::_totalAmount; }

int	Account::getNbDeposits(void) { return Account::_totalNbDeposits; }

int	Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout
	<< "accounts:" << Account::getNbAccounts() << ";"
	<< "total:" << Account::getTotalAmount() << ";"
	<< "deposits:" << Account::getNbDeposits() << ";"
	<< "withdrawals:" << Account::getNbWithdrawals()
	<< std::endl;
}

Account::Account(int initial_deposit) :
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0) {
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex << ";" 
	<< "amount:" << _amount << ";"
	<< "created" << std::endl;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex << ";" 
	<< "amount:" << _amount << ";"
	<< "closed" << std::endl;
}

void	Account::makeDeposit(int deposit) {
	const int	p_amount = this->_amount;

	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout 
	<< "index:" << _accountIndex << ";"
	<< "p_amount:" << p_amount << ";"
	<< "deposit:" << deposit << ";"
	<< "amount:" << _amount << ";"
	<< "nb_deposits:" << _nbDeposits
	<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	const int	p_amount = this->_amount;
	bool		withdrawed = false;

	if (_amount >= withdrawal) {
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		withdrawed = true;
	}
	Account::_displayTimestamp();
	std::cout 
	<< "index:" << _accountIndex << ";"
	<< "p_amount:" << p_amount << ";"
	<< "withdrawal:";
	if (!withdrawed) {
		std::cout << "refused" << std::endl;
		return false;
	} 
	std::cout << withdrawal << ";"
	<< "amount:" << _amount << ";"
	<< "nb_withdrawals:" << _nbWithdrawals
	<< std::endl;
	return withdrawed;
}

int	Account::checkAmount(void) const {
	return this->_amount;
}

void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout 
	<< "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "deposits:" << _nbDeposits << ";"
	<< "withdrawals:" << _nbWithdrawals
	<< std::endl;
}

void	Account::_displayTimestamp(void) {
	const std::time_t	time = std::time(nullptr);
	const std::string	format = "%Y%m%d_%H%M%S";
	char				timestamp[16]; // YYYYmmdd_HHMMSS
	std::strftime(
		timestamp,
		sizeof(timestamp),
		format.c_str(),
		std::localtime(&time));
	std::cout << "[" << timestamp << "] ";
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
