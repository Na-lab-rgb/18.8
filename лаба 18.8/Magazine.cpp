#include <iostream>
#include "Magazine.h"
using namespace std;

int Magazine::GetNumberOfPages()
{
	return _numberOfPages;
}

void Magazine::SetNumberOfPages(int n)
{
	if (n < 0) throw "Number of pages can't be negative";
	_numberOfPages = n;
}

ostream& operator<<(ostream& stream, Magazine element)
{
	stream << "Имя: " << element.GetName() << endl;
	stream << "Автор: " << element.GetAuthor() << endl;
	stream << "Страниц:hhg " << element.GetNumberOfPages() << endl;
	return stream;
}