#include "user.h"
#include "account.h"
#include "SystemWideFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <map>



int Test(){

    std::string username="test";
    std::string password="test";
    user u(username,password);
    std::cout<<u.getUserName()<<std::endl;
    


    return 0;
}