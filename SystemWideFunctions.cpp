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



void retrieveUser(User& user, const std::string& fileName, int profileNum) {
    std::ifstream inFile(fileName);
    std::string line;
    int count = 0;
    while (std::getline(inFile, line)) {
        if (count == profileNum) {
            std::stringstream ss(line);
            std::string username, password;
            double balance;
            ss >> username >> password >> balance;
            user.setUserName(username);
            user.setPassword(password);
            user.setBalance(balance);
            break;
        }
        count++;
    }
    inFile.close();
}

void storeUser(const User &user, const std::string &fileName) {
    std::ofstream outFile(fileName, std::ios::app);
    outFile << user.getUserName() << " " << user.getPassword() << " " << user.getBalance() << std::endl;
    outFile.close();
}

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
void createUser(const std::string &username, const std::string &password, double balance, const std::string &userFileName, std::unordered_map<std::string, int> &hashbase, const std::string &hashFileName) {
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
    lines[position] = updatedLine.str();

    // Write the modified lines back to the file
    std::ofstream outFile(userFileName, std::ios::trunc);
    for (const auto& newLine : lines) {
        outFile << newLine << std::endl;
    }
    outFile.close();
}
bool makeTransaction(User &sender, const std::string &receiverUsername, double amount, const std::string &userFileName, std::unordered_map<std::string, int> &hashbase) {
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

    // Update sender and receiver records in the user file
    updateUser(sender, userFileName, hashbase[sender.getUserName()]);
    updateUser(receiver, userFileName, receiverPosition);

    return true;
}

