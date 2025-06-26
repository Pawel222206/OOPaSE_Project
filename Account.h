#pragma once

#include <iostream>  // input/output
//#include <fstream>   // external files support
#include <string>   // string variable support
//#include <vector>    // vector
//#include <map>       // map
using namespace std; // saves the "std::" clutter

class Account
{
private:    // all members are private
    string login, password, history;

public: // all methods are set as private for now
    Account()  // default constructor
    {
        login = "abcd";
        password = "1234";
        history = "This account borrowed: ";
    }
    Account(string in_login, string in_password)  // constructor
    {
        login = in_login;
        password = in_password;
        history = "This account borrowed: ";
    }

    string getLogin() { return login; };
    string getPassword() { return password; };
    string getHistory() { return history; };

    void updateHistory(string in_borrowCode);

    ~Account();
};

