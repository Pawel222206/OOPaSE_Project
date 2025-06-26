#include <iostream>  // input/output
//#include <fstream>   // external files support
#include <string>   // string variable support
#include <vector>    // vector
//#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "Userbase.h"

void Userbase::addAccount(Account* in_Account)
{
	//cout << "Added" << endl; // test
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
				cout << "Password good" << endl;
				return true;
			}
			else
			{
				cout << "Password bad" << endl;
				return false;
			}
		}
		else
		{
			cout << "Login bad" << endl;
			return false;
		}
	}
}

void Userbase::borrowBook_A(string in_borrowCode, string in_username)
{
	for (auto A : Accounts)
	{
		if (A->getLogin() == in_username)
		{
			A->updateHistory(in_borrowCode);
		}
		else
		{
			cout << "Error" << endl;
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