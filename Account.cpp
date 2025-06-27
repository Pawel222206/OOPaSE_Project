#include <iostream>		// input/output
#include <string>		// string variable support
#include <vector>		// vector support
#include <Windows.h>	// acceses Windows API
#include <cstdlib>		// several general purpose functions
using namespace std;	// removes the requairement for "std::" clutter

#include "Account.h"

void Account::updateHistory(string in_borrowCode)
{
    history = history + in_borrowCode + "; ";
    cout << history << endl;
}

Account::~Account()
{
    cout << "After 30 days, your accou... nope, haha, it's gone, bye!" << endl << "Deleting Account" << endl;
}