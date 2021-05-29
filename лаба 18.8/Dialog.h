#pragma once
#include "List.h"
#include "Event.h"
using namespace std;

template <class T>
class Dialog : public List<T>
{
private:
	int EndState;
public:
	Dialog();
	~Dialog();

	void GetEvent(TEvent& event);
	void Execute();
	void HandleEvent(TEvent& event);
	void ClearEvent(TEvent& event);
};

#include "Dialog.cpp"