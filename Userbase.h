#pragma once

#include <iostream>  // input/output
//#include <fstream>   // external files support
//#include <string>    // string
#include <vector>	// vector variable support 
//#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "Book.h"
#include "Account.h"

class Userbase : public Account	// Composite Pattern
{
private:
	vector<Account*> Accounts;

public:
	void addAccount(Account* in_Account);

	bool loginAccount(string in_username, string in_password);

	void borrowBook_A(string in_borrowCode, string in_username);

	void getHistory();

	~Userbase()	// should be in .cpp but for some reason just doesn't want to connect :)
	{
		for (auto A : Accounts)
		{
			delete A;
		}
	}
};