#pragma once

#include <iostream>  // input/output
//#include <fstream>   // external files support
//#include <string>    // string
#include <vector>	// vector variable support 
//#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "Book.h"

class Database : public Book	// Composite Pattern
{
private:
	vector<Book*> Books;

public:
	void add(Book* in_Book);

	void getAll() override;

	~Database()	// should be in .cpp but for some reason just doesn't want to connect :)
	{
		for (auto B : Books)
		{
			delete B;
		}
	}
};