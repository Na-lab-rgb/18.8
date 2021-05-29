#pragma once
#include <string>
using namespace std;

class Print
{
private:
	string _author, _name;
public:
	Print(string author, string name);

	Print();

	string GetAuthor();

	string GetName();

	void SetAuthor(string author);

	void SetName(string name);

	friend ostream& operator<<(ostream& stream, Print element);
}; 
