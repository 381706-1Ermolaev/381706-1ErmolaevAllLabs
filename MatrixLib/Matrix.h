#pragma once
#include "Vector.h"
#include <iostream>

using namespace std;

template <class T>
class TMatrix : public Vector<Vector<T>{
public:
	TMatrix();
	TMatrix(int _n);
	TMatrix(TMatrix<T> &A);
	~TMatrix();
	TVector<T> operator [](int _I);
	TMatrix<T> operator +(TMatrix<T> &A);
	TMatrix<T> operator -(TMatrix<T> &A);
	TMatrix<T>& operator =(const TMatrix<T> &A);
	bool operator ==(const TMatrix &A) const;
	int GetN();

	template <class T1>
	friend istream& operator >>(istream &istr, TMatrix<T1> &A)
	{
		for (int i = 0; i < A.TVector<T1>::Size; i++)
			istr >> A.TVector<T1>::Vector[i];
		return istr;
	}
	
	template <class T1>
	friend ostream& operator <<(ostream &ostr, TMatrix<T1> &A)
	{
		for (int i = 0; i < A.TVector<T1>::Size; i++)
			ostr << A.TVector<T1>::Vector[i] << endl;
		return ostr;
	}
};

template <class T>
TMatrix<T> :: TMatrix() 
{
	TVector<T>::Size = 0;
	N = 0;
	TVector<T>::Vector = 0;
}


template <class T>
TMatrix<T>::TMatrix(int _n) : Vector<Vector<T>>(_n){
	if(_n < 0)
		throw 1;
	else
		for (int i = 0; i < _n; i++)
			this->mas[i] = Vector <T>(_n - i);
}


template <class T>
TMatrix<T> :: TMatrix(TMatrix<T> &A) 
{
	TVector<T>::Size = A.TVector<T>::Size;
	N = A.N;
	TVector<T>::Vector = new T [TVector<T>::Size];
	for (int i = 0; i < TVector<T>::Size; i++)
	{
		TVector<T>::Vector[i] = A.TVector<T>::Vector[i];
	}
}



template <class T>
TMatrix<T> :: ~TMatrix()
{
	N = 0;
}

