#pragma once

#include <iostream>		// input/output
#include <string>		// string variable support
#include <vector>		// vector support
#include <Windows.h>	// acceses Windows API
#include <cstdlib>		// several general purpose functions
using namespace std;	// removes the requairement for "std::" clutter

class Account
{
private:
    string login, password, history;

public:
    Account()
    {
        login = "abcd";
        password = "1234";
        history = " This account borrowed: ";
    }
    Account(string in_login, string in_password)
    {
        login = in_login;
        password = in_password;
        history = " This account borrowed: ";
    }

    string getLogin() { return login; };
    string getPassword() { return password; };
    string getHistory() { return history; };

    void updateHistory(string in_borrowCode);

    ~Account();
};

