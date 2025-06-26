#include <iostream>  // input/output
//#include <fstream>   // external files support
#include <string>   // string variable support
#include <vector>    // vector
//#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "Database.h"

void Database::add(Book* in_Book)
{
	//cout << "Added" << endl; // test
	Books.push_back(in_Book);
}

void Database::getAll()
{
	cout << "Library Database" << endl;
	cout << endl << "Available books:" << endl;
	for (auto B : Books)
	{
		if (B->getState() == 1)
		{
			B->getAll();
		}
	}
	cout << endl << "Borrowed books:" << endl;
	for (auto B : Books)
	{
		if (B->getState() == 0)
		{
			B->getAll();
		}
	}
};

void Database::borrowBook_B(string in_code)
{
	for (auto B : Books)
	{
		if (B->getCode() == in_code)
		{
			B->updateState("does not matter");
		}
	}
};

void Database::updateState(string in_code)
{
	for (auto B : Books)
	{
		if (B->getCode() == in_code)
		{
			cout << "For the book " << in_code << ", the ";
			B->updateState(in_code);
		}
	}
};