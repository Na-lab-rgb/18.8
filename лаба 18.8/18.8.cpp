#include <iostream>
#include "Dialog.h"
#include "Magazine.h"
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));

	cout << "m [size] ������� ������" << endl;
	cout << "+ �������� �������" << endl;
	cout << "- ������� ������� �� ������" << endl;
	cout << "s ������� ���������� �� ���������" << endl;
	cout << "z ������� ���������� � ��������� ���� ���������" << endl;
	cout << "q ����� ������" << endl;

	Dialog<Magazine> D;
	D.Execute();
}