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

private:
    std::string userName;
    std::string password;
    double balance;
};


#endif
