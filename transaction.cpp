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
#include "transaction.h"
// create structure transaction that takes in a string receiver string sender and double amount

// overload operator to read in from file
std::ifstream& operator>>(std::ifstream& in, transaction& t)
{
    std::string line;
    std::getline(in, line);
    std::istringstream iss(line);
    std::string r, s;
    double a;
    iss >> r >> s >> a;
    t.setReceiver(r);
    t.setSender(s);
    t.setAmount(a);
    return in;
}
// overload operator to write to file
std::ofstream& operator<<(std::ofstream& out, const transaction& t)
{
    out << t.getReceiver() << " " << t.getSender() << " " << t.getAmount() << std::endl;
    return out;
}
