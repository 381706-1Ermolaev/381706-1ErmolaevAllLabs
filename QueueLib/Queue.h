#pragma once
#include <iostream>
#include "Stack.h"

using namespace std;

template <class T>
class TQueue : public TStack <T> {//Очередь наследуем от стека
protected:
	int start;//Начало очереди
	int count;//Конец очереди
public:
	TQueue();//Конструктор по умолчанию
	TQueue(int _Size);//Конструктор с параметром-размером очереди
	TQueue(TQueue <T> &A);//Конструктор копирования
	void Put(T A);//Положить в конец очереди
	T Get();//Взять первый элемент
	bool IsFull();//Проверка на полноту
	bool IsEmpty();//Проверка на пустоту
};

template <class T>
TQueue<T>::TQueue() : TStack<T>(){
	start = count = 0;
}

template <class T>
TQueue<T>::TQueue(int _Size) : TStack<T>(_Size) {
	start = count = 0;
}

template <class T>
TQueue<T>::TQueue(TQueue<T> &A) : TStack<T>(A) {
	start = A.start; 
	count = A.count;
}

template <class T>
void TQueue<T>::Put(T A){
	if (IsFull())
		throw "Queue is full";
	else {
		TStack<T>::mas[start] = A;
		start = (start + 1) % TStack<T>::size;
		count++;
	}
}

template <class T>
T TQueue<T>::Get() {
	if (IsEmpty())
		throw "Queue is empty";
	else {
		T tmp = TStack<T>::mas[TStack<T>::top];
		TStack<T>::top = (TStack<T>::top + 1) % TStack<T>::size;
		count--;
		
		return tmp;
	}
}

template <class T>
bool TQueue<T>::IsFull() {
	return (count == TStack<T>::size);
}

template <class T>
bool TQueue<T>::IsEmpty() {
	return (count == 0);
}