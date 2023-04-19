#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "user.h"
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
const int maxTransactionsPerLine = 4;


/*
void retrieveUser(User& user, const std::string& fileName, int profileNum) {
    std::ifstream inFile(fileName);
    std::string line;
    int count = 0;
    while (std::getline(inFile, line)) {
        if (count == profileNum * 4) {  // Each user now takes 4 lines in the file
            std::stringstream ss(line);
            std::string username, password;
            double balance;
            ss >> username >> password >> balance;
            user.setUserName(username);
            user.setPassword(password);
            user.setBalance(balance);
        }
        else if (count > profileNum * 4 && count <= profileNum * 4 + 3) {
            // Reading the transaction history lines
            std::stringstream ss(line);
            std::string sender, receiver;
            double amount;
            while (ss >> sender >> receiver >> amount) {
                transaction t(sender, receiver, amount);
                user.addTransaction(t);
            }
        }
        else if (count > profileNum * 4 + 3) {
            break;
        }
        count++;
    }
    inFile.close();
}*/
void retrieveUser(User& user, const std::string& fileName, int profileNum) {
    std::ifstream inFile(fileName);
    std::string line;
    int count = 0;
    while (std::getline(inFile, line)) {
        if (count == profileNum * 5) {
            std::stringstream ss(line);
            std::string username, password;
            double balance;
            ss >> username >> password >> balance;
            user.setUserName(username);
            user.setPassword(password);
            user.setBalance(balance);
        }
        else if (count > profileNum * 5 && count <= profileNum * 5 + 2) {
            std::stringstream ss(line);
            std::string sender, receiver;
            double amount;
            while (ss >> sender >> receiver >> amount) {
                transaction t(sender, receiver, amount);
                user.addTransaction(t);
            }
        }
        else if (count == profileNum * 5 + 4) {
            std::stringstream ss(line);
            std::string alias, friendUserName;
            while (std::getline(ss, alias, ',') && std::getline(ss, friendUserName, ',')) {
                user.addQuickPayFriend(friendUserName, alias);
            }
        }
        else if (count > profileNum * 5 + 4) {
            break;
        }
        count++;
    }
    inFile.close();
}


/*
void storeUser(const User& user, const std::string& fileName) {
    std::ofstream outFile(fileName, std::ios::app);
    outFile << user.getUserName() << " " << user.getPassword() << " " << user.getBalance() << std::endl;

    // Store transaction history
    std::vector<transaction> transactions = user.getTransactions();
    size_t transactionCounter = 0;
    for (int i = 0; i < 3; ++i) {
        std::stringstream transactionLine;
        for (int j = 0; j < maxTransactionsPerLine && transactionCounter < transactions.size(); ++j) {
            transactionLine << transactions[transactionCounter].getSender() << " "
                << transactions[transactionCounter].getReceiver() << " "
                << transactions[transactionCounter].getAmount() << " ";
            transactionCounter++;
        }
        outFile << transactionLine.str() << std::endl;
    }
    outFile.close();
}
*/
std::unordered_map<std::string, int> retrieveHash(const std::string& filename) {
    std::unordered_map<std::string, int> hashbase;
    std::ifstream infile(filename);
    std::string line;
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string username;
        int position;
        ss >> username >> position; // Read both the username and position from the file
        hashbase[username] = position;
    }
    infile.close();
    return hashbase;
}
void storeUser(const User& user, const std::string& fileName) {
    std::ofstream outFile(fileName, std::ios::app);
    outFile << user.getUserName() << " " << user.getPassword() << " ";
    outFile << std::fixed << std::setprecision(2) << user.getBalance() << std::endl;

    // Store transaction history
    std::vector<transaction> transactions = user.getTransactions();
    size_t transactionCounter = 0;
    for (int i = 0; i < 3; ++i) {
        std::stringstream transactionLine;
        for (int j = 0; j < maxTransactionsPerLine && transactionCounter < transactions.size(); ++j) {
            transactionLine << transactions[transactionCounter].getSender() << " "
                << transactions[transactionCounter].getReceiver() << " "
                << transactions[transactionCounter].getAmount() << " ";
            transactionCounter++;
        }
        outFile << transactionLine.str() << std::endl;
    }

    // Store quickPayFriends
    const auto& quickPayFriends = user.getQuickPayFriends();
    std::stringstream quickPayFriendsLine;
    for (const auto& kvp : quickPayFriends) {
        quickPayFriendsLine << kvp.first << "," << kvp.second << ",";
    }
    outFile << quickPayFriendsLine.str() << std::endl;

    outFile.close();
}

void storeHashbase(const std::string& filename, const std::unordered_map<std::string, int>& hashbase) {
    std::ofstream outfile(filename, std::ios::trunc);
    for (const auto& entry : hashbase) {
        outfile << entry.first << ' ' << entry.second << '\n';
    }
    outfile.close();
}

bool usernameExists(const std::string& username, const std::unordered_map<std::string, int>& hashbase) {
    return hashbase.find(username) != hashbase.end();
}
void updateHashbase(std::unordered_map<std::string, int>& hashbase, const std::string& username, const int& position) {
    hashbase[username] = position;
}
void addUserToHashbase(std::unordered_map<std::string, int>& hashbase, const std::string& username, const int& position) {
    hashbase[username] = position;
}
void createUser(const std::string& username, const std::string& password, double balance, const std::string& userFileName, std::unordered_map<std::string, int>& hashbase, const std::string& hashFileName) {
    if (usernameExists(username, hashbase)) {
        std::cout << "Username already exists. Please choose a different username." << std::endl;
        return;
    }
    User newUser(username, password, balance);
    storeUser(newUser, userFileName);
    int newPosition = hashbase.size();
    addUserToHashbase(hashbase, username, newPosition);
    storeHashbase(hashFileName, hashbase);
}


/*void updateUser(const User& user, const std::string& userFileName, int position) {
    std::vector<std::string> lines;
    std::string line;
    std::ifstream userFile(userFileName);

    // Read all the lines from the file and store them in a vector
    while (std::getline(userFile, line)) {
        lines.push_back(line);
    }
    userFile.close();

    // Replace the specific line (position) with the updated user data
    std::stringstream updatedLine;
    updatedLine << user.getUserName() << " " << user.getPassword() << " " << user.getBalance();
    lines[position * 4] = updatedLine.str();

    // Update transaction history lines
    std::vector<transaction> transactions = user.getTransactions();
    size_t transactionCounter = 0;
    for (int i = 0; i < 3; ++i) {
        std::stringstream transactionLine;
        for (int j = 0; j < maxTransactionsPerLine && transactionCounter < transactions.size(); ++j) {
            transactionLine << transactions[transactionCounter].getSender() << " "
                << transactions[transactionCounter].getReceiver() << " "
                << transactions[transactionCounter].getAmount() << " ";
            transactionCounter++;
        }
        lines[position * 4 + 1 + i] = transactionLine.str();
    }

    // Write the modified lines back to the file
    std::ofstream outFile(userFileName, std::ios::trunc);
    for (const auto& newLine : lines) {
        outFile << newLine << std::endl;
    }
    outFile.close();
}*/
void updateUser(const User& user, const std::string& userFileName, int position) {
    std::vector<std::string> lines;
    std::string line;
    std::ifstream userFile(userFileName);

    // Read all the lines from the file and store them in a vector
    while (std::getline(userFile, line)) {
        lines.push_back(line);
    }
    userFile.close();

    // Replace the specific line (position) with the updated user data
    std::stringstream updatedLine;
    updatedLine << user.getUserName() << " " << user.getPassword() << " " << user.getBalance();
    lines[position * 5] = updatedLine.str();

    // Update transaction history lines
    std::vector<transaction> transactions = user.getTransactions();
    size_t transactionCounter = 0;
    for (int i = 0; i < 3; ++i) {
        std::stringstream transactionLine;
        for (int j = 0; j < maxTransactionsPerLine && transactionCounter < transactions.size(); ++j) {
            transactionLine << transactions[transactionCounter].getSender() << " "
                << transactions[transactionCounter].getReceiver() << " "
                << transactions[transactionCounter].getAmount() << " ";
            transactionCounter++;
        }
        lines[position * 5 + 1 + i] = transactionLine.str();
    }

    // Update quick pay friends line
    const auto& quickPayFriends = user.getQuickPayFriends();
    std::stringstream quickPayFriendsLine;
    for (const auto& kvp : quickPayFriends) {
        quickPayFriendsLine << kvp.first << "," << kvp.second << ",";
    }
    lines[position * 5 + 4] = quickPayFriendsLine.str();

    // Write the modified lines back to the file
    std::ofstream outFile(userFileName, std::ios::trunc);
    for (const auto& newLine : lines) {
        outFile << newLine << std::endl;
    }
    outFile.close();
}




bool makeTransaction(User& sender, const std::string& receiverUsername, double amount, const std::string& userFileName, std::unordered_map<std::string, int>& hashbase) {
    if (amount <= 0 || amount > sender.getBalance()) {
        return false;
    }

    if (!usernameExists(receiverUsername, hashbase)) {
        return false;
    }

    int receiverPosition = hashbase[receiverUsername];
    User receiver;
    retrieveUser(receiver, userFileName, receiverPosition);

    // Update sender and receiver balances
    sender.setBalance(sender.getBalance() - amount);
    receiver.setBalance(receiver.getBalance() + amount);

    // Create a transaction and add it to sender's and receiver's transaction history
    transaction t(sender.getUserName(), receiver.getUserName(), amount);
    std::vector<transaction> senderTransactions = sender.getTransactions();
    std::vector<transaction> receiverTransactions = receiver.getTransactions();

    if (senderTransactions.size() >= 10) {
        senderTransactions.erase(senderTransactions.begin());
    }
    senderTransactions.push_back(t);
    sender.setTransactionHistory(senderTransactions);

    if (receiverTransactions.size() >= 10) {
        receiverTransactions.erase(receiverTransactions.begin());
    }
    receiverTransactions.push_back(t);
    receiver.setTransactionHistory(receiverTransactions);

    // Update sender and receiver records in the user file
    updateUser(sender, userFileName, hashbase[sender.getUserName()]);
    updateUser(receiver, userFileName, receiverPosition);

    return true;
}

