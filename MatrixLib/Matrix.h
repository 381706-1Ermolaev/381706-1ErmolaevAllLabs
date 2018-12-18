#pragma once

#include <iostream>
#include "Vector.h"
#include "ME.h"

using namespace std;

template <class T>
class TMatrix : public TVector<TVector<T> >{
public:
	TMatrix(int _N);
	TMatrix(const TMatrix &A);                    
	TMatrix(const TVector<TVector<T> > &A);		
	virtual ~TMatrix<T>();
     
	TMatrix& operator= (const TMatrix &A);       
	TMatrix  operator+ (const TMatrix &A);       
	TMatrix  operator- (const TMatrix &A);        
	bool operator==(const TMatrix &A);

	template <class T> friend istream& operator>>(istream &in, TMatrix<T> &A)
	{
		for (int i = 0; i < A.N; i++)
			in >> A.V[i];
		return in;
	}
	
	template <class T>  friend ostream & operator<<(ostream &out, const TMatrix<T> &A)
	{
		for (int i = 0; i < A.N; i++) {
			for (int j = 1; j <= i; j++)
				out << "\t";
			out << A.V[i] << endl;
		}
		return out;
	}
};


template <class T>
TMatrix<T>::TMatrix(int _N) : TVector<TVector<T> >(_N)
{
	if (_N < 0)
		throw 1;
	else
		for (int i = 0; i < _N; i++)
			this->V[i] = TVector <T>(_N-i);
}


template <class T> 
TMatrix<T>::TMatrix(const TMatrix<T> &A) : TVector<TVector<T> >(A) {}


template <class T> 
TMatrix<T>::TMatrix(const TVector<TVector<T> > &A) : TVector<TVector<T> >(A) {}


template <class T>
TMatrix<T>::~TMatrix() {
	
}


template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &A) 
{
	return TVector<TVector<T> >::operator==(A); 
}





template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &A)
{
	TVector<TVector<T> >::operator=(A); 
	return *this;
}


template <class T> 
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &A)
{
	if (this->N != A.N)
		throw 1;
	else
		return TVector <TVector<T> > :: operator+(A);
}

template <class T> 
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &A)
{
	if (this->N != A.N)
		throw 1;
	else
		return TVector <TVector<T> > :: operator-(A);
}