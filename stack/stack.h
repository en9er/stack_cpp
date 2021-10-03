#pragma once
#include<iostream>
#define STEP 10
template<typename T>
class Stack
{
public:
	void push(const T);
	T pop();
	T peek() const;
	T top() const;
	bool empty() const;
	int size() const;
	
	Stack();
	~Stack();

private:
	T* arr;
	int capacity;
	int _size;
	void resize();
};

template<typename T>
Stack<T>::Stack()
{
	capacity = STEP;
	_size = 0;
	resize();
}

template<typename T>
Stack<T>::~Stack()
{
	delete arr;
}


template<typename T>
void Stack<T>::resize()
{
	T* new_arr = new T[capacity];
	for (int i = 0; i < _size; i++)
	{
		new_arr[i] = arr[i];
	}
	arr = new_arr;
}

template<typename T>
void Stack<T>::push(const T unit)
{
	if (_size >= capacity)
	{
		capacity += STEP;
		resize();
	}
	arr[_size] = unit;
	_size++;
}

template<typename T>
int Stack<T>::size() const
{
	return _size;
}

template<typename T>
T Stack<T>::pop()
{
	T top = arr[_size];
	if (capacity - _size >= STEP)
	{
		capacity -= STEP;
		resize();
	}
	_size--;
	return top;
}

template<typename T>
T Stack<T>::top() const
{
	return arr[_size - 1];
}

template<typename T>
T Stack<T>::peek() const
{
	return arr[_size - 1];
}

template<typename T>
bool Stack<T>::empty() const
{
	return !bool(_size);
}
 

