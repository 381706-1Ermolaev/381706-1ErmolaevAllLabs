#pragma once
#include <iostream>
#include "Elem.h"

using namespace std;

template <class T>
class TList {
protected:
	TElem<T>* begin;//Указатель на первое звено списка
public:
	TList();//Конст по умолчанию
	TList(TList<T> &A);//Конст копирования
	void PutBegin(T A);//Установить начальное звено
	void PutEnd(T A);//Установить последнее звено
	T GetBegin();//Вытащить начало
	T GetEnd();//Вытащить конец
	/*T GetElem(T* A);
	T* GetInd(T A);*/
	bool IsFull();//Полон
	bool IsEmpty();//Пуст
};

template <class T>
TList<T>::TList(){
	begin = 0;
}

template <class T>
TList<T>::TList(TList<T> &A){
	TElem<T>* temp = A.begin;
	if (A.begin = 0)
		begin = 0;
	else
		begin = new TElem<T> (A.begin);
	temp = begin;
	while (temp->GetNext != 0)
		temp.next = new TElem<T>(*temp->GetNext());
}

template <class T>
void TList<T>::PutBegin(T A){
	if (begin == 0)//Если список пуст
	{
		TElem<T>* temp = new TElem<T>(A, 0);//
		begin = temp;
	}
	else
	{
		TElem<T>* temp = new TElem<T>(A, begin);
		begin = temp;
	}
}

template <class T>
void TList<T>::PutEnd(T A){
	if (IsEmpty()){
		begin = new TElem<T>(A, 0);
	}
	else {
		TElem<T>* temp = begin;
		while (temp->GetNext() != 0)
			temp = temp->GetNext();

		temp->SetNext(new TElem <T>(A, 0));
	}
}

template <class T>
T TList<T>::GetBegin(){
	if (!IsEmpty()) {
		T tempE = begin->Get();
		begin = begin->GetNext();
		return tempE;
	}
	else
		throw "Have not any elem";
}

template <class T>
T TList<T>::GetEnd(){
	if (!IsEmpty()) {
		TElem<T>* temp = begin;
		while ((temp->GetNext())->GetNext() != 0)
			temp = temp->GetNext();

		T tempE = (temp->GetNext())->Get();

		temp->SetNext(0);

		return tempE;
	}
	else
		throw "Have not any elem";

}

//template <class T>
//T TList<T>::GetElem(T* A){
//	
//	
//
//}
//
//template <class T>
//T* TList<T>::GetInd(T A){
//
//}

template <class T>
bool TList<T>::IsFull(){
	try
	{
		TElem<T>* A = new TElem();
		return (A == 0)
	}
	catch ()
		return false;
	return true;

}

template <class T>
bool TList<T>::IsEmpty(){
	return (begin == 0);
}


