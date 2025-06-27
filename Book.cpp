#include <iostream>		// input/output
#include <string>		// string variable support
#include <vector>		// vector support
#include <Windows.h>	// acceses Windows API
#include <cstdlib>		// several general purpose functions
using namespace std;	// removes the requairement for "std::" clutter

#include "book.h"

void Book::updateState(string in_code)
{
    if (state == 0)
    {
        state = 1;
        cout << "state was changed from 0 to 1." << endl;
    }
    else
    {
        state = 0;
        cout << "state was changed from 1 to 0." << endl;
    }
}

Book::~Book()
{
    cout << "Deleting Book" << endl;
}