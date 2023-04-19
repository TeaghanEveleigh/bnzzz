#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include "transaction.h"
#ifndef USER_H
#define USER_H

class User {
public:
    User() : userName(""), password(""), balance(0) {}
    User(const std::string& userName, const std::string& password, double balance)
        : userName(userName), password(password), balance(balance) {}

    std::string getUserName() const { return userName; }
    void setUserName(const std::string& userName) { this->userName = userName; }

    std::string getPassword() const { return password; }
    void setPassword(const std::string& password) { this->password = password; }

    double getBalance() const { return balance; }
    void setBalance(double balance) { this->balance = balance; }
    void addTransaction(const transaction& t) { transactionHistory.push_back(t); }
    std::vector<transaction> getTransactions() const { return transactionHistory; }
    void setTransactionHistory(const std::vector<transaction>& transactions){
        this->transactionHistory = transactions;
    }

    // Add new methods for quickPayFriends
    void addQuickPayFriend(const std::string& userName, const std::string& alias) {
        quickPayFriends[alias] = userName;
    }


    const std::unordered_map<std::string, std::string>& getQuickPayFriends() const {
    return quickPayFriends;
}

    void setQuickPayFriends(const std::unordered_map<std::string, std::string>& newQuickPayFriends) {
        quickPayFriends = newQuickPayFriends;
    }
    bool isInQuickPay(const std::string& alias) const {
        return quickPayFriends.find(alias) != quickPayFriends.end();
    }
private:
    std::string userName;
    std::string password;
    double balance;
    std::vector<transaction> transactionHistory;
    std::unordered_map<std::string, std::string> quickPayFriends;
};

#endif