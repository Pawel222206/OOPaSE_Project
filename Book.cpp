#include <iostream>  // input/output
//#include <fstream>   // external files support
#include <string>   // string variable support
//#include <vector>    // vector
//#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "book.h"

void Book::updateState(string in_code)
{
    //cout << code << " book's state updated from: " << state;
    //state = 1;
    ////state = in_state;
    //cout << ", to: " << state << endl;

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