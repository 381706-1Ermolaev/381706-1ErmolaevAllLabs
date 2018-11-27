#pragma once
#include <iostream>

using namespace std;

template <class T>
class TStack{
protected:
	int size;
	T* mas;
	int top;
public:
	TStack();
	TStack(int _Size);
	TStack(TStack &A);
	~TStack();
	void Put(T A);
	T Get();
	bool IsFull();
	bool IsEmpty();
};

template <class T>
TStack<T>::TStack(){
	size = 0;
	mas = 0;
	top = 0;
}

template <class T>
TStack<T>::TStack(int _size){
	if (_size < 0)
		throw "Negative size";
	else 
		if (_size == 0){
		size = 0;
		mas = 0;
		top = 0;
	}
	else{
		mas = new T[_size];
		size = _size;
		top = 0;
	}
}

template <class T>
TStack<T>::TStack(TStack<T> &A){
	size = A.size;
	top = A.top;
	if (size == 0)
		mas = 0;
	else{
		mas = new T[size];
		for (int i = 0; i < size; i++)
			mas[i] = A.mas[i];
	}
}
template <class T>
TStack<T> :: ~TStack(){
	if (mas != 0)
		delete[] mas;

	top = 0;
	size = 0;
}


template <class T>
void TStack<T>::Put(T A){
	if (IsFull())
		throw "Full";
	else{
		mas[top] = A;
		top++;
	}
}

template <class T>
T TStack<T>::Get(){
	if (IsEmpty())
		throw "Empty";
	else{
		top--;
		return mas[top++];
	}
}
template <class T>
bool TStack<T>::IsEmpty(){
	if (top == 0)
		return true;
	else
		return false;
}

template <class T>
bool TStack<T>::IsFull(){
	if (top >= size)
		return true;
	else
		return false;
}