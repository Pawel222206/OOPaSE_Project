#pragma once

#include <iostream>  // input/output
//#include <fstream>   // external files support
#include <string>   // string variable support
//#include <vector>    // vector
//#include <map>       // map
using namespace std; // saves the "std::" clutter

class Book
{
private:    // all members are private
    int state;  // 0 - nope, 1 - available, !switch it to bool later!
    string code, name, author;

public: // all methods are set as private for now
    Book()  // default constructor
    {
        code = "00";
        state = 0;
        name = "Blank book";
        author = "Nobody";
    }
    Book(string in_code, string in_name, string in_author)  // constructor
    {
        code = in_code;
        state = 1;
        name = in_name;
        author = in_author;
    }

    string getCode() { return code; };
    int getState() { return state; };
    string getName() { return name; };
    string getAuthor() { return author; };
    virtual void getAll() { cout << code << "; " << name << "; " << author << ";" << endl; };

    virtual void updateState(string in_code);

    ~Book();
};

