#include <iostream>
#include "Dialog.h"
#include "Magazine.h"
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));

	cout << "m [size] создать список" << endl;
	cout << "+ добавить элемент" << endl;
	cout << "- удалить элемент из группы" << endl;
	cout << "s вывести информацию об элементах" << endl;
	cout << "z вывести информацию о названиях всех элементов" << endl;
	cout << "q конец работы" << endl;

	Dialog<Magazine> D;
	D.Execute();
}