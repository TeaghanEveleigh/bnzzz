#include "user.h"
#include "account.h"
#include "SystemWideFunctions.h"
#include <chrono>
#include <iostream>
#include <string>
#include <unordered_map>
#include <conio.h>
void delay(int seconds)
{
    auto start = std::chrono::high_resolution_clock::now();
    while (true)
    {
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
        if (elapsed_seconds >= seconds)
        {
            break;
        }
    }
}


int main()
{
    User existingUser;
    std::string hashFileName = "HashBase";
    std::string userFileName = "UserBase";
    /*


         std::string adminUsername = "admin";
     std::string adminPassword = "admin123";
     double adminBalance = 1000000;*/

     // Create the admin account

    /*

     std::unordered_map<std::string, int> hashbase = retrieveHash(hashFileName);

     // Test creating a new user
     createUser("JohnDeee", "password123", 1000.0, userFileName, hashbase, hashFileName);
     // Test retrieving an existing user
     User existingUser;
     std::string username = "JohnDeee";
     if (usernameExists(username, hashbase)) {
         int position = hashbase[username];
         retrieveUser(existingUser, userFileName, position);
         std::cout << "Username: " << existingUser.getUserName() << ", Password: " << existingUser.getPassword() << ", Balance: " << existingUser.getBalance() << std::endl;
     } else {
         std::cout << "User not found." << std::endl;
     }*/

     //code that prints retrieving hash and waits 2 seconds
    system("cls");
    std::cout << "           _    _    _              _              _           " << std::endl;
    std::cout << " ___  ___ | |_ | |_ |_| ___  ___   | |_  ___  ___ | |_          " << std::endl;
    std::cout << "| . || -_||  _||  _|| ||   || . |  |   || .'||_ -||   | _  _  _ " << std::endl;
    std::cout << "|_  ||___||_|  |_|  |_||_|_||_  |  |_|_||__,||___||_|_||_||_||_|" << std::endl;
    std::cout << "|___|                       |___|                               " << std::endl;
    std::cout << "==================================================================" << std::endl;
    delay(1);
    std::unordered_map<std::string, int> hashbase = retrieveHash(hashFileName);
    //createUser(adminUsername, adminPassword, adminBalance, userFileName, hashbase, hashFileName);

    system("cls");
    bool invalid = false;
    bool optionscreen = false;
    int option;
    std::cout << "                                                                                                __ " << std::endl;
    std::cout << " _ _ _  _____  __     _____  _____  _____  _____    _____  _____    _____  _____  _____  _____ |  |" << std::endl;
    std::cout << "| | | ||   __||  |   |     ||     ||     ||   __|  |_   _||     |  | __  ||   | ||__   ||__   ||  |" << std::endl;
    std::cout << "| | | ||   __||  |__ |   --||  |  || | | ||   __|    | |  |  |  |  | __ -|| | | ||   __||   __||__|" << std::endl;
    std::cout << "|_____||_____||_____||_____||_____||_|_|_||_____|    |_|  |_____|  |_____||_|___||_____||_____||__|" << std::endl;
    std::cout << "=====================================================================================================" << std::endl;
    std::cout << "Would you like to login or create an account" << std::endl;
    std::cout << "Please select" << std::endl;
    std::cout << "1)Login" << std::endl;
    std::cout << "2)create an account" << std::endl;
    while (optionscreen == false)
    {
        if (invalid == true) {
            system("cls");
            std::cout << "                                                                                                __ " << std::endl;
            std::cout << " _ _ _  _____  __     _____  _____  _____  _____    _____  _____    _____  _____  _____  _____ |  |" << std::endl;
            std::cout << "| | | ||   __||  |   |     ||     ||     ||   __|  |_   _||     |  | __  ||   | ||__   ||__   ||  |" << std::endl;
            std::cout << "| | | ||   __||  |__ |   --||  |  || | | ||   __|    | |  |  |  |  | __ -|| | | ||   __||   __||__|" << std::endl;
            std::cout << "|_____||_____||_____||_____||_____||_|_|_||_____|    |_|  |_____|  |_____||_|___||_____||_____||__|" << std::endl;
            std::cout << "=====================================================================================================" << std::endl;
            std::cout << "It seems your option was invalid please try again!" << std::endl;
            std::cout << "Please select(1/2)" << std::endl;
            std::cout << "1)Login" << std::endl;
            std::cout << "2)create an account" << std::endl;
        }
        std::cin >> option;
        // try catch for invalid input if option is not 1 or two if it isnt then throw the exception of invalid option and ask for input again by continuing the loop else if it is 1 or 2 then break the loop
        if (option == 1)
        {
            optionscreen = true;
            system("cls");
        }
        else if (option == 2)
        {
            optionscreen = true;
            system("cls");
        }
        else
        {

            invalid = true;

        }
    }
    if (option == 1)
    {


        std::string username;
        std::string password;
        bool invalidCredentials = true;
        bool firstTme = true;


        while (invalidCredentials == true) {
            system("cls");
            std::cout << "                                                              __ " << std::endl;
            std::cout << " _ _ _       _                          _____            _   |  |" << std::endl;
            std::cout << "| | | | ___ | | ___  ___  _____  ___   | __  | ___  ___ | |_ |  |" << std::endl;
            std::cout << "| | | || -_|| ||  _|| . ||     || -_|  | __ -|| .'||  _|| '_||__|" << std::endl;
            std::cout << "|_____||___||_||___||___||_|_|_||___|  |_____||__,||___||_,_||__|" << std::endl;
            std::cout << "=================================================================" << std::endl;
            if (firstTme == true) {
                std::cout << "Login..." << std::endl;
            }
            else {
                std::cout << "It seems your username or password was incorrect please try again" << std::endl;
            }

            std::cout << "Please enter your username: ";
            std::cin >> username;

            if (usernameExists(username, hashbase)) {
                int position = hashbase[username];
                retrieveUser(existingUser, userFileName, position);
                std::cout << "Username: " << existingUser.getUserName() << ", Password: " << existingUser.getPassword() << ", Balance: " << existingUser.getBalance() << std::endl;

                std::cout << "Please enter your password: ";
                std::cin >> password;

                if (password == existingUser.getPassword()) {
                    invalidCredentials = false;
                    std::cout << "Success!" << std::endl;
                }
                else {
                    invalidCredentials = true;
                }
            }
            else {
                invalidCredentials = true;
            }
            firstTme = false;
        }
    }
    if (option == 2)
    {
        //create a new user
        system("cls");
        User newUser;
        std::cout << "                                                                        __ " << std::endl;
        std::cout << " _____                 _           _____                           _   |  |" << std::endl;
        std::cout << "|     | ___  ___  ___ | |_  ___   |  _  | ___  ___  ___  _ _  ___ | |_ |  |" << std::endl;
        std::cout << "|   --||  _|| -_|| .'||  _|| -_|  |     ||  _||  _|| . || | ||   ||  _||__|" << std::endl;
        std::cout << "|_____||_|  |___||__,||_|  |___|  |__|__||___||___||___||___||_|_||_|  |__|" << std::endl;
        std::cout << "===========================================================================" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Please enter your username to continue" << std::endl;

        std::string username;
        bool validUsername = false;
        while (!validUsername) {
            std::cin >> username;

            if (usernameExists(username, hashbase)) {
                std::cout << "Username already exists. Please choose a different username." << std::endl;
            }
            else {
                validUsername = true;
                std::cout << "Please enter your password" << std::endl;
                // check if the password is valid
                std::string password;
                std::cin >> password;
                createUser(username, password, 0.0, userFileName, hashbase, hashFileName);
                std::cout << "Account created successfully!" << std::endl;
                existingUser = User(username, password, 0.0);
            }
        }

        

        // Create the new user account and add it to the userbase and hashbase

        delay(1);
    }
    bool isRunnin = true;
    while (isRunnin == true) {


        system("cls");
        std::cout << " _ _ _       _                       " << std::endl;
        std::cout << "| | | | ___ | | ___  ___  _____  ___ " << std::endl;
        std::cout << "| | | || -_|| ||  _|| . ||     || -_|" << std::endl;
        std::cout << "|_____||___||_||___||___||_|_|_||___|" << std::endl;
        std::cout << "=================================================" << std::endl;
        std::cout << "Welcome to BNZZ Banking. Please select an option:" << std::endl;
        std::cout << "        1. View your balance" << std::endl;
        std::cout << "        2. View recent transactions" << std::endl;
        std::cout << "        3. Make a transaction" << std::endl;
        std::cout << "        4. View quickpay Accounts" << std::endl;
        std::cout << "        5. View profile information" << std::endl;
        std::cout << "        6. Exit" << std::endl;
        // take input and make an if statement for each option
        int optionMain;
        std::cin >> optionMain;
        if (optionMain == 1)
        {
            std::cout << "Your balance is: " << existingUser.getBalance() << std::endl;
            // shows user balance
            system("pause");
        }
        else if (optionMain == 2)
        {
            system("cls");
            std::cout << " _____                                _    _                " << std::endl;
            std::cout << "|_   _| ___  ___  ___  ___  ___  ___ | |_ |_| ___  ___  ___ " << std::endl;
            std::cout << "  | |  |  _|| .'||   ||_ -|| .'||  _||  _|| || . ||   ||_ -|" << std::endl;
            std::cout << "  |_|  |_|  |__,||_|_||___||__,||___||_|  |_||___||_|_||___|" << std::endl;
            std::cout << "============================================================" << std::endl;
            // shows transaction history of user and if it exceed lets say 10 transactions then it will be shown in a new page
            //print out the transaction history of the user
            const std::vector<transaction> transactions = existingUser.getTransactions();
            for (size_t i = 0; i < transactions.size(); i++) {
                if (existingUser.getUserName() == transactions[i].getSender()) {
                    std::cout << i + 1 << ") " << "You" << " transfered" << " " << transactions[i].getAmount() << " to " << transactions[i].getReceiver() << std::endl;
                }
                else if (existingUser.getUserName() == transactions[i].getReceiver()) {

                    std::cout << i + 1 << ") " << "You" << " received" << " " << transactions[i].getAmount() << " from " << transactions[i].getSender() << std::endl;
                }

                // Retrieve the transaction history of the user

            }
            std::cout << "press any key to go back" << std::endl;
            getch();
        }
        else if (optionMain == 3) {
            bool transactionSuccessful = false;
            system("cls");
            std::cout << "Make a transaction" << std::endl;

            std::string receiverUsername;
            double transactionAmount;

            std::cout << "Please enter the username of the person you would like to transfer to: ";
            std::cin >> receiverUsername;
            if (existingUser.getUserName() == receiverUsername) {
                std::cout << "You cannot transfer to yourself. Please try again." << std::endl;
                delay(3);
            }
            else if (usernameExists(receiverUsername, hashbase) == false) {
                std::cout << "Username does not exist. Please try again." << std::endl;
                delay(3);

            }

            else {
                std::cout << "Please enter the amount you would like to transfer: ";
                std::cin >> transactionAmount;
                if (existingUser.getBalance() < transactionAmount) {
                    std::cout << "You do not have enough money to make this transaction. Please try again." << std::endl;
                    delay(3);

                }
                else {
                    // Perform the transaction
                    transactionSuccessful = makeTransaction(existingUser, receiverUsername, transactionAmount, userFileName, hashbase);
                }
            }

            if (transactionSuccessful) {
                std::cout << "Transaction completed successfully!" << std::endl;

                // Prompt the user if they want to add the receiver to their quick pay list
                char addToQuickPay;
                std::cout << "Do you want to add this user to your quick pay list? (Y/N): ";
                std::cin >> addToQuickPay;

                if (addToQuickPay == 'Y' || addToQuickPay == 'y') {
                    std::string nickname;
                    std::cout << "Enter a nickname for the user: ";
                    std::cin >> nickname;
                    existingUser.addQuickPayFriend(nickname, receiverUsername); // swap the values of nickname and receiverUsername
                    updateUser(existingUser, userFileName, hashbase[existingUser.getUserName()]);
                    std::cout << "User added to your quick pay list successfully!" << std::endl;
                }
            }
            else {
                std::cout << "Transaction failed. Please check the receiver's username and ensure you have sufficient balance." << std::endl;
            }
            delay(3);
        }
        else if (optionMain == 4) {
            system("cls");
            std::cout << "Quick Pay List" << std::endl;
            std::cout << "===============" << std::endl;
            const auto& quickPayList = existingUser.getQuickPayFriends();
            std::vector<std::string> userNames;

            size_t index = 1;
            for (const auto& entry : quickPayList) {
                std::cout << index << ". Nickname: " << entry.second << ", Username: " << entry.first << std::endl;
                userNames.push_back(entry.first);
                index++;
            }

            std::cout << "0. Cancel" << std::endl;
            size_t userSelection;
            std::cout << "Enter the number of the user you want to make a transaction to: ";
            std::cin >> userSelection;

            if (userSelection > 0 && userSelection <= quickPayList.size()) {
                std::string receiverUsername = userNames[userSelection - 1];
                double amount;
                std::cout << "Enter the amount to be transferred: ";
                std::cin >> amount;

                bool transactionSuccessful = makeTransaction(existingUser, receiverUsername, amount, userFileName, hashbase);

                if (transactionSuccessful && usernameExists(receiverUsername, hashbase)) {
                    std::cout << "Transaction successful!" << std::endl;
                }
                else if (!usernameExists(receiverUsername, hashbase)) {
                    std::cout << "Username does not exist. Please try again." << std::endl;
                }
                else {
                    std::cout << "Transaction failed. Please check the amount and try again." << std::endl;
                }
            }
            else {
                std::cout << "Cancelled." << std::endl;
            }

            std::cout << std::endl << "Press any key to continue...";
            std::cin.ignore();
            std::cin.get();
        }
        else if (optionMain == 5)
        {
            std::cout << "Profile information" << std::endl;
            // shows user profile information
            std::cout << "Username: " << existingUser.getUserName() << std::endl;
            std::cout << "Password: " << existingUser.getPassword() << std::endl;
            std::cout << "Balance: " << existingUser.getBalance() << std::endl;
            system("pause");
        }
        else if (optionMain == 6)
        {
            system("cls");
            std::cout << " __     _____  _____  _____  _____  _____  _____    _____  _____  _____ " << std::endl;
            std::cout << "|  |   |     ||   __||   __||     ||   | ||   __|  |     ||  |  ||_   _|" << std::endl;
            std::cout << "|  |__ |  |  ||  |  ||  |  ||-   -|| | | ||  |  |  |  |  ||  |  |  | |  " << std::endl;
            std::cout << "|_____||_____||_____||_____||_____||_|___||_____|  |_____||_____|  |_| " << std::endl;
            std::cout << "=======================================================================" << std::endl;
            // Wait for 3 seconds
            delay(1);
            system("cls");
            // Exit the program
            exit(0);
        }
    }
    return 0;

}