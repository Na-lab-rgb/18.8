#include <iostream>
#include "Print.h"
#include <string>
using namespace std;

Print::Print(string author, string name)
{
	_author = author;
	_name = name;
}

Print::Print()
{
	string authors[] = { "Тургенев", "Пушкин", "Достоевский" };
	_author = authors[rand() % 3];
	_name = "Book " + to_string(rand() % 100);
}

string Print::GetAuthor()
{
	return _author;
}

string Print::GetName()
{
	return _name;
}

void Print::SetAuthor(string author)
{
	_author = author;
}

void Print::SetName(string name)
{
	_name = name;
}

ostream& operator<<(ostream& stream, Print element)
{
	stream << "Имя: " << element.GetName() << endl;
	stream << "Автор: " << element.GetAuthor() << endl;
	return stream;
}