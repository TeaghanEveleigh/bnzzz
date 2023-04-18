#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#ifndef TRANSACTION_H
#define TRANSACTION_H
class transaction
{
private:
    std::string receiver;
    std::string sender;
    double amount;

public:
    transaction() {}
    transaction(std::string r, std::string s, double a) : receiver(r), sender(s), amount(a) {}
    std::string getReceiver() const { return receiver; }
    std::string getSender() const { return sender; }
    double getAmount() const { return amount; }
    // setters
    void setReceiver(std::string r) { receiver = r; }
    void setSender(std::string s) { sender = s; }
    void setAmount(double a) { amount = a; }

    friend std::ifstream &operator>>(std::ifstream &in, transaction &t);

    friend std::ofstream &operator<<(std::ofstream &out, const transaction &t);
};
#endif