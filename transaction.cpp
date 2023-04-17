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
//create structure transaction that takes in a string receiver string sender and double amount
class transaction
{
    private:
    std::string receiver;
    std::string sender;
    double amount;
    public:
    transaction(std::string r, std::string s, double a) : receiver(r), sender(s), amount(a) {}
    std::string getReceiver() const { return receiver; }
    std::string getSender() const { return sender; }
    double getAmount() const { return amount; }
    //setters
    void setReceiver(std::string r) { receiver = r; }
    void setSender(std::string s) { sender = s; }
    void setAmount(double a) { amount = a; }
 
    friend std::ifstream& operator>>(std::ifstream& in, transaction& t);
  
    friend std::ofstream& operator<<(std::ofstream& out, const transaction& t);
  
   
};
//overload operator to read in from file
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
//overload operator to write to file
std::ofstream& operator<<(std::ofstream& out, const transaction& t)
{
    out << t.getReceiver() << " " << t.getSender() << " " << t.getAmount() << std::endl;
    return out;
}



