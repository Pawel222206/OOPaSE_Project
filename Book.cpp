#include <iostream>  // input/output
//#include <fstream>   // external files support
#include <string>   // string variable support
//#include <vector>    // vector
//#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "book.h"

void Book::updateState(int in_state)
{
    cout << code << " book's state updated from: " << state;
    state = in_state;
    cout << ", to: " << state << endl;
}

Book::~Book()
{
    cout << "Deleting Book" << endl;
}