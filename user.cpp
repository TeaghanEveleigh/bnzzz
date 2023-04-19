#include "user.h"


User::User() : userName(""), password(""), balance(0) {}

User::User(const std::string& userName, const std::string& password, double balance)
    : userName(userName), password(password), balance(balance) {}

std::string User::getUserName() const { return userName; }

void User::setUserName(const std::string& userName) { this->userName = userName; }

std::string User::getPassword() const { return password; }

void User::setPassword(const std::string& password) { this->password = password; }

double User::getBalance() const { return balance; }

void User::setBalance(double balance) { this->balance = balance; }

void User::addTransaction(const Transaction& t) { transactionHistory.push_back(t); }

std::vector<Transaction> User::getTransactions() const { return transactionHistory; }

void User::setTransactionHistory(const std::vector<Transaction>& transactions) {
    this->transactionHistory = transactions;
}

void User::addQuickPayFriend(const std::string& userName, const std::string& alias) {
    quickPayFriends[alias] = userName;
}

const std::unordered_map<std::string, std::string>& User::getQuickPayFriends() const {
    return quickPayFriends;
}

void User::setQuickPayFriends(const std::unordered_map<std::string, std::string>& newQuickPayFriends) {
    quickPayFriends = newQuickPayFriends;
}




