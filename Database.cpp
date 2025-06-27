#include <iostream>		// input/output
#include <string>		// string variable support
#include <vector>		// vector support
#include <Windows.h>	// acceses Windows API
#include <cstdlib>		// several general purpose functions
using namespace std;	// removes the requairement for "std::" clutter

#include "Book.h"
#include "Database.h"

void Database::add(Book* in_Book)
{
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
	cout << endl << "Books unavailable at the moment:" << endl;
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