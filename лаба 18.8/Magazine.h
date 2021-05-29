#pragma once
#include "Print.h"
#include <string>
using namespace std;

class Magazine : public Print
{
private:
	int _numberOfPages;

public:
	Magazine(string author, string name, int nPages) : Print(author, name)
	{
		_numberOfPages = nPages;
	}

	Magazine() : Print()
	{
		_numberOfPages = rand() % 1000;
	}

	int GetNumberOfPages();

	void SetNumberOfPages(int n);

	friend ostream& operator<<(ostream& stream, Magazine element);
};
