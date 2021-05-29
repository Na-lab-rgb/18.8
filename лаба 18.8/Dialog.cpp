#ifndef _DIALOG_CPP
#define _DIALOG_CPP

#include "Dialog.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
Dialog<T>::Dialog() : List<T>()
{
	EndState = 0;
}

template <typename T>
Dialog<T>::~Dialog() {}

template <typename T>
void Dialog<T>::GetEvent(TEvent& event)
{
	string operations = "m+-szq";
	string s;
	getline(cin, s);

	if (operations.find(s[0]) != -1)
	{
		event.what = evMessage;
		switch (s[0]) {
		case 'm': event.command = cmdMake; break;
		case '+': event.command = cmdAdd; break;
		case '-': event.command = cmdDel; break;
		case 's': event.command = cmdShow; break;
		case 'z': event.command = cmdName; break;
		case 'q': event.command = cmdQuit; break;
		}
		if (s.length() > 1)
		{
			string param = s.substr(1, s.length() - 1);
			event.param = stoi(param);
		}
	}
	else
	{
		event.what = evNothing;
	}
}

template <typename T>
void Dialog<T>::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmdMake:
		{
			int size = event.param;
			List<T>::_arr = new T[size];
			List<T>::_size = size;

			for (int i = 0; i < List<T>::_size; i++)
				List<T>::_arr[i] = T();

			ClearEvent(event);
			break;
		}
		case cmdAdd:
		{
			this->Insert(T(), 0);
			ClearEvent(event);
			break;
		}
		case cmdDel:
		{
			this->Erase(event.param);
			ClearEvent(event);
			break;
		}
		case cmdShow:
		{
			for (int i = 0; i < List<T>::_size; i++)
				cout << List<T>::_arr[i];
			cout << endl;
			ClearEvent(event);
			break;
		}
		case cmdQuit:
		{
			EndState = 1;
			ClearEvent(event);
			break;
		}
		case cmdName:
		{
			cout << "Имена:" << endl;
			for (int i = 0; i < List<T>::_size; i++)
				cout << List<T>::_arr[i].GetName() << endl;
			ClearEvent(event);
			break;
		}
		//default: Dialog<T>::HandleEvent(event);
		}
	}
}

template <typename T>
void Dialog<T>::Execute()
{
	TEvent event;
	do
	{
		GetEvent(event);
		HandleEvent(event);
		if (event.what != evNothing)
		{
			ClearEvent(event);
		}
	} while (EndState == 0);
}

template <typename T>
void Dialog<T>::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}

#endif