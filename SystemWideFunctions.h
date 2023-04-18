#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

void retrieveUser(User& user, const std::string& fileName, int profileNum);
void storeUser(const User &user, const std::string &fileName);
std::unordered_map<std::string, int> retrieveHash(const std::string& filename);
void storeHashbase(const std::string& filename, const std::unordered_map<std::string, int>& hashbase);
bool usernameExists(const std::string& username, const std::unordered_map<std::string, int>& hashbase);
void updateHashbase(std::unordered_map<std::string, int>& hashbase, const std::string& username, const int& position);
void addUserToHashbase(std::unordered_map<std::string, int>& hashbase, const std::string& username, const int& position);
void createUser(const std::string &username, const std::string &password, double balance, const std::string &userFileName, std::unordered_map<std::string, int> &hashbase, const std::string &hashFileName);
void updateUser(const User& user, const std::string& userFileName, int position);
bool makeTransaction(User& sender, const std::string& receiverUsername, double amount, const std::string& userFileName, std::unordered_map<std::string, int>& hashbase);
