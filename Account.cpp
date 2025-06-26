#include <iostream>  // input/output
//#include <fstream>   // external files support
#include <string>   // string variable support
//#include <vector>    // vector
//#include <map>       // map
using namespace std; // saves the "std::" clutter

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