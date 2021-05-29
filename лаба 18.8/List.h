#pragma once
#include <iostream>
#include <typeinfo>
using namespace std;

template <class T>
class List
{
protected:
	T* _arr;
	int _size;

public:
	List(int size = 0)
	{
		_size = size;
		_arr = new T[_size];
		/*
		if (typeid(T) == typeid(int) || typeid(T) == typeid(float) || typeid(T) == typeid(double))
			for (int i = 0; i < _size; i++)
				_arr[i] = rand() % 100;
				*/
	}

	List(const List& list)
	{
		_size = list._size;
		_arr = list._arr;
	}

	int Size()
	{
		return _size;
	}

	void Insert(T element, int position)
	{
		T* oldArr = _arr;
		_arr = new T[_size + 1];

		// copy first part
		for (int i = 0; i < position; i++)
			_arr[i] = oldArr[i];
		// insert element
		_arr[position] = element;
		_size++;
		// copy second part
		for (int i = position + 1; i < _size; i++)
			_arr[i] = oldArr[i - 1];
	}

	void Erase(int position)
	{
		if (_size == 0 || _arr == nullptr) return;
		if (position < 0 || position >= _size) return;

		T* oldArr = _arr;
		//delete _arr;
		_arr = new T[_size - 1];

		// copy first part
		for (int i = 0; i < position; i++)
			_arr[i] = oldArr[i];
		// skip element and copy second part
		_size--;
		for (int i = position; i < _size; i++)
			_arr[i] = oldArr[i + 1];
	}

	T operator[](int ind)
	{
		if (ind < 0 || ind >= _size) throw "Index out of range";

		return _arr[ind];
	}

	List<T> operator*(List& secondOperand)
	{
		int min = _size < secondOperand._size ? _size : secondOperand._size;
		List res(min);

		for (int i = 0; i < min; i++)
		{
			res._arr[i] = _arr[i] * secondOperand._arr[i];
		}

		return res;
	}

	template<typename T> friend ostream& operator<<(ostream& stream, List<T>& list);
};

template<typename T>
ostream& operator<<(ostream& stream, List<T>& list)
{
	for (int i = 0; i < list._size; i++)
	{
		stream << list._arr[i] << " ";
	}
	return stream;
}
