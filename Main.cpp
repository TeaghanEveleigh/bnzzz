#include <iostream>
int main(){
    system("cls");
    bool optionscreen=false;
    int option;
    std::cout << "**************************************" << std::endl;
        std::cout << "*                                    *" << std::endl;
        std::cout << "*     Welcome to the BNZZ Bank!      *" << std::endl;
        std::cout << "*                                    *" << std::endl;
        std::cout << "**************************************" << std::endl;
        std::cout<<"Would you like to login or create an account"<<std::endl;
        std::cout<<"Please select"<<std::endl;
        std::cout<<"1)Login"<<std::endl;
        std::cout<<"2)create an account"<<std::endl;
    while(optionscreen==false){
        std::cin>>option;
        //try catch for invalid input if option is not 1 or two if it isnt then throw the exception of invalid option and ask for input again by continuing the loop else if it is 1 or 2 then break the loop
        if(option==1){
            optionscreen=true;
            system("cls");
        }
        else if(option==2){
            optionscreen=true;
            system("cls");
        }
        else{
            std::cout<<"Invalid option"<<std::endl;
d
        }
}
    if(option==1){
        std::cout<<"Login"<<std::endl;
        std::string username;
        std::string password;

        std::cout << "**************************************" << std::endl;
        std::cout << "*                                    *" << std::endl;
        std::cout << "*            Welcome back!           *" << std::endl;
        std::cout << "*                                    *" << std::endl;
        std::cout << "**************************************" << std::endl;
        std::cout << std::endl;

        std::cout << "Please enter your username: ";
        std::getline(std::cin, username);

    std::cout << "Please enter your password: ";
        std::getline(std::cin, password);
    }
    else if(option==2){
    std::cout << "======================================" << std::endl;
    std::cout << "|          CREATE AN ACCOUNT         |" << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "|                                    |" << std::endl;
    std::cout << "|    Thank you for choosing us!      |" << std::endl;
    std::cout << "|                                    |"<<std::endl;
    std::cout << "======================================" << std::endl;
    std::cout<<"please enter your username to continue"<<std::endl;
    std::string username;
    std::cin>>username;
    //to do code that checks if user name exists or not if it does prompt another username
    
    std::cout<<"please enter your password"<<std::endl;
    std::string password;
    std::cin>>password;

    }
   
    std::cout<<" _ _ _       _                       "<<std::endl;
    std::cout<<"| | | | ___ | | ___  ___  _____  ___ "<<std::endl;
    std::cout<<"| | | || -_|| ||  _|| . ||     || -_|"<<std::endl;
    std::cout<<"|_____||___||_||___||___||_|_|_||___|"<<std::endl;
    std::cout<<"====================================="<<std::endl;
    std::cout<<"Welcome to BNZZ Banking. Please select an option:"<<std::endl;
    std::cout<<"        1. View your balance"<<std::endl;
    std::cout<<"        2. View transaction history"<<std::endl;
    std::cout<<"        3. Make a transaction"<<std::endl;
    std::cout<<"        4. See list of commands"<<std::endl;
    std::cout<<"        5. View profile information"<<std::endl;










    return 0;
}