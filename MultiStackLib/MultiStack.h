#pragma once
#include "NewStack.h"
#include <iostream>
#include "ME.h"
using namespace std;
//Спаси и сохрани
template <class T>
class TMStack {

protected:
	int size;
	T* mas;
	int n;
	TNewStack<T>** h;
	int GetFreeMem();
	void Repack(int k);

public:
	TMStack(int _n, int _size);
	int GetSize() { return size; }
	TMStack(TMStack<T> &A); 
	void Set(int _n, T p); 
	T Get(int _n); 
	bool isFull(int _n); 
	bool isEmpty(int _n); 
};

template <class T>
TMStack<T> ::TMStack(int _n, int _size)
{
	if (_n <= 0 || _size <= 0)
	{
		ME osh(-1, "Negative leight\n");
		throw osh;; 
	}

	n = _n; 
	size = _size; 

	h = new TNewStack<T>*[n]; 
	mas = new T[size]; 

	int* p = new int[n];

	p[0] = int(double(size) / n) + (size%n);

	for (int i = 1; i < n; i++)
		p[i] = int(double(size) / n); 

	h[0] = new TNewStack<T>(p[0], &mas[0]); 
	for (int i = 1; i < n; i++)
		h[i] = new TNewStack<T>(p[i], &mas[p[0] + (i - 1)*p[i]]);
}

template <class T>
TMStack<T> ::TMStack(TMStack &A)
{
	int sizeST = 0; 
	size = A.size;
	n = A.n;
	mas = new T[size];
	h = new TNewStack<T>*[n];
	for (int i = 0; i < n; i++) 
		mas[i] = A.mas[i];

	int* p = new int[n]; 
	for (int i = 0; i < n; i++)
		p[i] = A.h[i]->GetSize();
	h[0] = new TNewStack<T>(*A.h[0]);
	for (int i = 1; i < n; i++)
	{
		h[i] = new TNewStack<T>(*A.h[i]);
		h[i]->SetMas(p[i], &mas[-p[0] + sizeST]);
		sizeST += p[i - 1];
	}
}

template<class T>
void TMStack<T>::Set(int _n, T p)
{
	if (_n<0) {
		ME osh(-1, "Negative index");
		throw osh;
	}

	if (isFull(_n))
		Repack(_n);

	h[_n]->Push(p);
}

template<class T>
T TMStack<T>::Get(int _n)
{
	if(_n<0) {
		ME osh(-1, "Negative index");
		throw osh;
	}



	if (isEmpty(_n)) {
		ME osh(0, "Empty\n");
		throw osh;
	}

	return h[_n]->Get();
}

template<class T>
bool TMStack<T>::isFull(int _n)
{
	return (h[_n]->GetFreeMem() <= 0);
}

template<class T>
bool TMStack<T>::isEmpty(int _n)
{
	return (h[_n]->GetFreeMem() == h[_n]->GetSize());
}

template <class T>
int TMStack<T>::GetFreeMem()
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count += h[i]->GetFreeMem();
	}
	return count;
}

template <class T>
void TMStack<T>::Repack(int k)//"НЕ ЛЕЗЬ!ОНА ТЕБЯ СОЖРЕТ!!!!"
{
	cout << "REPACK" << endl;
	int FM = GetFreeMem();

	if (FM == 0)
		throw "OSHIBKa";

	int add_ev = FM / n;
	int add_full = FM % n;
	int* new_size = new int[n];
	T** new_start = new T*[n];
	T** old_start = new T*[n];

	for (int i = 0; i < n; i++)
		new_size[i] = add_ev + h[i]->GetTop();
	new_size[k] += add_full;
	new_start[0] = old_start[0] = mas;

	for (int i = 1; i < n; i++)
	{
		new_start[i] = new_start[i - 1] + new_size[i - 1];
		old_start[i] = old_start[i - 1] + h[i - 1]->GetSize();
	}

	for (int i = 0; i < n; i++)
	{
		if (new_start[i] <= old_start[i])
			for (int j = 0; j < h[i]->GetTop(); j++)
				new_start[i][j] = old_start[i][j];

		else
		{
			int s = i + 1;
			for (s; s < n; s++)
				if (new_start[s] <= old_start[s])
					break;

			for (int j = s - 1; j >= i; j--)
				for (int r = h[j]->GetTop() - 1; r >= 0; r--)
					new_start[j][r] = old_start[j][r];

			i = s - 1;
		}
	}

	for (int i = 0; i < n; i++)
		h[i]->SetMas(new_size[i], new_start[i]);

	delete[] new_size;
	delete[] new_start;
	delete[] old_start;
}