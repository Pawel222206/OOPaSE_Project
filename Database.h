#pragma once

#include <iostream>		// input/output
#include <string>		// string variable support
#include <vector>		// vector support
#include <Windows.h>	// acceses Windows API
#include <cstdlib>		// several general purpose functions
using namespace std;	// removes the requairement for "std::" clutter

#include "Book.h"

class Database : public Book	// Composite Pattern
{
private:
	vector<Book*> Books;

public:
	void add(Book* in_Book);

	void getAll() override;

	void updateState(string in_code) override;

	void borrowBook_B(string in_code);

	~Database()	// Should be in .cpp but for some reason just doesn't want to connect :)
	{
		for (auto B : Books)
		{
			delete B;
		}
	}
};