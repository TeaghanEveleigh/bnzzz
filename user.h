#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include "transaction.h"

class User {
public:
    User();
    User(const std::string& userName, const std::string& password, double balance);

    std::string getUserName() const;
    void setUserName(const std::string& userName);

    std::string getPassword() const;
    void setPassword(const std::string& password);

    double getBalance() const;
    void setBalance(double balance);

    void addTransaction(const Transaction& t);
    std::vector<Transaction> getTransactions() const;
    void setTransactionHistory(const std::vector<Transaction>& transactions);

    void addQuickPayFriend(const std::string& userName, const std::string& alias);
    const std::unordered_map<std::string, std::string>& getQuickPayFriends() const;
    void setQuickPayFriends(const std::unordered_map<std::string, std::string>& newQuickPayFriends);

private:
    std::string userName;
    std::string password;
    double balance;
    std::vector<Transaction> transactionHistory;
    std::unordered_map<std::string, std::string> quickPayFriends;
};

#endif