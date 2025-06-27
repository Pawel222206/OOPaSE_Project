#include <iostream>		// input/output
#include <string>		// string variable support
#include <vector>		// vector support
#include <Windows.h>	// acceses Windows API
#include <cstdlib>		// several general purpose functions
using namespace std;	// removes the requairement for "std::" clutter

#include "Userbase.h"

void Userbase::addAccount(Account* in_Account)
{
	Accounts.push_back(in_Account);
}

bool Userbase::loginAccount(string in_username, string in_password)
{
	for (auto A : Accounts)
	{
		if (A->getLogin() == in_username)
		{
			cout << "Login good" << endl;
			if (A->getPassword() == in_password)
			{
				cout << "You have borrowed" << endl;
				return true;
			}
		}
	}
	cout << "Login or password bad" << endl;
	return false;
}

void Userbase::borrowBook_A(string in_borrowCode, string in_username)
{
	for (auto A : Accounts)
	{
		if (A->getLogin() == in_username)
		{
			A->updateHistory(in_borrowCode);
		}
	}
};

void Userbase::getHistory()
{
	cout << "Library Userbase" << endl;
	cout << endl << "Borrowing history:" << endl;
	for (auto A : Accounts)
	{
		cout << A->getLogin() << A->getHistory() << endl;
	}
};