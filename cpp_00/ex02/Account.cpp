#include <ctime>
#include <iostream>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::~Account(void) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void) { return (Account::_nbAccounts); }

int Account::getTotalAmount(void) { return (Account::_totalAmount); }

int Account::getNbDeposits(void) { return (Account::_totalNbDeposits); }
int Account::getNbWithdrawals(void) { return (Account::_totalNbWithdrawals); }

void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::_nbAccounts << ";";
  std::cout << "total:" << Account::_totalAmount << ";";
  std::cout << "deposits:" << Account::_totalNbDeposits << ";";
  std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t now;
  std::tm *tm;
  char buffer[20];

  now = std::time(0);
  tm = std::localtime(&now);
  std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", tm);
  std::cout << "[" << buffer << "] ";

  // to check diff
  // std::cout << "[19920104_091532] ";
}

Account::Account(int initial_deposit) {
  this->_accountIndex = Account::_nbAccounts;
  this->_amount = initial_deposit;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;
  Account::_totalAmount += initial_deposit;
  Account::_nbAccounts++;

  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "created" << std::endl;
}

void Account::displayStatus(void) const {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "deposits:" << this->_nbDeposits << ";";
  std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {

  int p_amount;

  p_amount = this->_amount;
  this->_amount += deposit;
  this->_nbDeposits++;
  Account::_totalAmount += deposit;
  Account::_totalNbDeposits++;

  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << p_amount << ";";
  std::cout << "deposit:" << deposit << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "nb_deposits:" << Account::_nbDeposits << std::endl;
}

int Account::checkAmount(void) const { return (this->_amount); }

bool Account::makeWithdrawal(int withdrawal) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << this->checkAmount() << ";";
  if (this->checkAmount() < withdrawal) {
    std::cout << "withdrawal:"
              << "refused" << std::endl;
    return (false);
  }
  this->_amount -= withdrawal;
  this->_nbWithdrawals++;
  Account::_totalAmount -= withdrawal;
  Account::_totalNbWithdrawals++;
  std::cout << "withdrawal:" << withdrawal << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
  return (true);
}
