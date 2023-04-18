/*#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

// todo function that fetches the user from the file

void retrieveUser(user& user, const std::string& fileName, int profileNum) {
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

void storeUser(const user &user, const std::string &fileName) {
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

void storeHashbase(std::unordered_map<std::string, int>& hashbase, const std::string& username, const int& position) {
    hashbase[username] = position;
}
void addUserToHashbase(user& user, std::unordered_map<std::string, int>& hashbase) {
    hashbase[user.getUserName()] = hashbase.size();*/
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