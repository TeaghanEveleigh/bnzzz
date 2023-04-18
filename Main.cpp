#include "user.h"
#include "account.h"
#include "SystemWideFunctions.h"
#include <chrono>
#include <iostream>
#include <string>
#include <unordered_map>
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
    std::cout << "Retrieving Hash..." << std::endl;
    delay(1);
    std::unordered_map<std::string, int> hashbase = retrieveHash(hashFileName);
    //createUser(adminUsername, adminPassword, adminBalance, userFileName, hashbase, hashFileName);

    system("cls");
    bool optionscreen = false;
    int option;
    std::cout << "**************************************" << std::endl;
    std::cout << "*                                    *" << std::endl;
    std::cout << "*     Welcome to the BNZZ Bank!      *" << std::endl;
    std::cout << "*                                    *" << std::endl;
    std::cout << "**************************************" << std::endl;
    std::cout << "Would you like to login or create an account" << std::endl;
    std::cout << "Please select" << std::endl;
    std::cout << "1)Login" << std::endl;
    std::cout << "2)create an account" << std::endl;
    while (optionscreen == false)
    {

        system("cls");
        std::cout << "**************************************" << std::endl;
        std::cout << "*                                    *" << std::endl;
        std::cout << "*     Welcome to the BNZZ Bank!      *" << std::endl;
        std::cout << "*                                    *" << std::endl;
        std::cout << "**************************************" << std::endl;
        std::cout << "It seems your option was invalid please try again!" << std::endl;
        std::cout << "Please select(1/2)" << std::endl;
        std::cout << "1)Login" << std::endl;
        std::cout << "2)create an account" << std::endl;
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

            std::cout << "Invalid option. Please try again.\n";
        }
    }
    if (option == 1)
    {


        std::string username;
        std::string password;
        bool invalidusername = false;


        while (invalidusername == false) {
            system("cls");
            std::cout << "**************************************" << std::endl;
            std::cout << "*                                    *" << std::endl;
            std::cout << "*            Welcome back!           *" << std::endl;
            std::cout << "*                                    *" << std::endl;
            std::cout << "**************************************" << std::endl;

            std::cout << "Login..." << std::endl;
            std::cout << "Please enter your username: ";
            std::cin >> username;
            if (usernameExists(username, hashbase)) {
                int position = hashbase[username];
                invalidusername = true;
                retrieveUser(existingUser, userFileName, position);
                std::cout << "Username: " << existingUser.getUserName() << ", Password: " << existingUser.getPassword() << ", Balance: " << existingUser.getBalance() << std::endl;
                bool validpassword = false;
                while (validpassword == false) {
                    std::cout << "Please enter your password: ";
                    std::getline(std::cin, password);
                    if (password == existingUser.getPassword()) {
                        validpassword = true;
                        std::cout << "sucesss" << std::endl;

                    }
                    else {
                        std::cout << "Invalid password please try again" << std::endl;

                    }
                }

            }
            else {
                std::cout << "User not found." << std::endl;
            }


            // to do code that checks if user name exists or not if it does prompt another username and if it doesnt then prompt to create an account
        }
    }
    if (option == 2)
    {
        //create a new user
        system("cls");
        User newUser;
        std::cout << "======================================" << std::endl;
        std::cout << "|          CREATE AN ACCOUNT         |" << std::endl;
        std::cout << "======================================" << std::endl;
        std::cout << "|                                    |" << std::endl;
        std::cout << "|    Thank you for choosing us!      |" << std::endl;
        std::cout << "|                                    |" << std::endl;
        std::cout << "======================================" << std::endl;
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
            }
        }

        std::cout << "Please enter your password" << std::endl;
        // check if the password is valid
        std::string password;
        std::cin >> password;

        // Create the new user account and add it to the userbase and hashbase
        createUser(username, password, 0.0, userFileName, hashbase, hashFileName);
        std::cout << "Account created successfully!" << std::endl;
    }
    bool isRunnin = true;
    while (isRunnin == true) {


        system("cls");
        std::cout << " _ _ _       _                       " << std::endl;
        std::cout << "| | | | ___ | | ___  ___  _____  ___ " << std::endl;
        std::cout << "| | | || -_|| ||  _|| . ||     || -_|" << std::endl;
        std::cout << "|_____||___||_||___||___||_|_|_||___|" << std::endl;
        std::cout << "=====================================" << std::endl;
        std::cout << "Welcome to BNZZ Banking. Please select an option:" << std::endl;
        std::cout << "        1. View your balance" << std::endl;
        std::cout << "        2. View recent transactions" << std::endl;
        std::cout << "        3. Make a transaction" << std::endl;
        std::cout << "        4. Logoff" << std::endl;
        std::cout << "        5. View profile information" << std::endl;
        std::cout << "        6. Exit" << std::endl;
        // take input and make an if statement for each option
        int optionMain;
        std::cin >> optionMain;
        if (optionMain == 1)
        {
            std::cout << "Your balance is: $0.00" << std::endl;
            // shows user balance
            system("pause");
        }
        else if (optionMain == 2)
        {
            system("cls");
            std::cout << "Transaction history" << std::endl;
            // shows transaction history of user and if it exceed lets say 10 transactions then it will be shown in a new page
            //print out the transaction history of the user
            const std::vector<transaction> transactions = existingUser.getTransactions();
            for (size_t i = 0; i < transactions.size(); i++) {
                if (existingUser.getUserName() == transactions[i].getSender()) {
                    std::cout << i + 1 << ") " << "You" << " transfered" << transactions[i].getAmount() << " to " << transactions[i].getReceiver() << std::endl;
                }
                else if (existingUser.getUserName() == transactions[i].getReceiver()) {

                    std::cout << i + 1 << ") " << "You" << " received" << transactions[i].getAmount() << " from " << transactions[i].getSender() << std::endl;
                }
                
                // Retrieve the transaction history of the user

            }
            system("pause");
        }
        else if (optionMain == 3)
        {
            system("cls");
            std::cout << "Make a transaction" << std::endl;

            std::string receiverUsername;
            double transactionAmount;

            std::cout << "Please enter the username of the person you would like to transfer to: ";
            std::cin >> receiverUsername;

            std::cout << "Please enter the amount you would like to transfer: ";
            std::cin >> transactionAmount;

            // Perform the transaction
            bool transactionSuccessful = makeTransaction(existingUser, receiverUsername, transactionAmount, userFileName, hashbase);

            if (transactionSuccessful) {
                std::cout << "Transaction completed successfully!" << std::endl;
            }
            else {
                std::cout << "Transaction failed. Please check the receiver's username and ensure you have sufficient balance." << std::endl;
            }
            delay(3);
        }
        else if (optionMain == 4)
        {
            std::cout << "" << std::endl;
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
            std::cout << "+-----------------------+\n"
                << "|                       |\n"
                << "|    Logging off...     |\n"
                << "|                       |\n"
                << "+-----------------------+\n";

            // Wait for 3 seconds
            delay(1);
            system("cls");
            // Exit the program
            exit(0);
        }
    }
    return 0;

}