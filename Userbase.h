#pragma once

#include <iostream>		// input/output
#include <string>		// string variable support
#include <vector>		// vector support
#include <Windows.h>	// acceses Windows API
#include <cstdlib>		// several general purpose functions
using namespace std;	// removes the requairement for "std::" clutter

#include "Book.h"
#include "Account.h"

class Userbase : public Account
{
private:
	vector<Account*> Accounts;

public:
	void addAccount(Account* in_Account);

	bool loginAccount(string in_username, string in_password);

	void borrowBook_A(string in_borrowCode, string in_username);

	void getHistory();

	~Userbase()
	{
		for (auto A : Accounts)
		{
			delete A;
		}
	}
};