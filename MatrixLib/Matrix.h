#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "Vector.h"
#include "ME.h"

using namespace std;

template <class T>
class TMatrix : public TVector<TVector<T> >{

public:
	TMatrix(int _N);
	TMatrix(const TMatrix<T> &A);
	TMatrix(const TVector<TVector<T> > &A);		
	virtual ~TMatrix<T>();
     
	TMatrix& operator= (const TMatrix<T> &A);       
	TMatrix  operator+ (const TMatrix<T> &A);
	TMatrix  operator- (const TMatrix<T> &A);
	TMatrix  operator* (const TMatrix<T> &A);
	TMatrix  operator/ (const TMatrix<T> &A);
	bool operator==(const TMatrix<T> &A);

	
	friend istream& operator>>(istream &in, TMatrix<T> &A)
	{
		for (int i = 0; i < A.size; i++)
			in >> A.v[i];
		return in;
	}
	
 
	friend ostream & operator<<(ostream &out, const TMatrix<T> &A)
	{
		for (int i = 0; i < A.size; i++) {	
			out << A.v[i] << endl;
		}
		return out;
	}
};


template <class T>
TMatrix<T>::TMatrix(int _n) : TVector<TVector<T> >(_n)
{
	if (_n < 0)
	{
		ME osh(-1, "Negative size");
		throw osh;
	}
	else
		for (int i = 0; i < _n; i++)
			v[i] = TVector <T>(_n-i);
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
	if (this->size != A.size)
	{
		ME osh(0, "dimV1 != dimV2");
		throw osh;
	}
	else
		return TVector <TVector<T> > :: operator+(A);
}

template <class T> 
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &A)
{
	if (this->size != A.size)
	{
		ME osh(0, "dimV1 != dimV2");
		throw osh;
	}
	else
		return TVector <TVector<T> > :: operator-(A);
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T> &A)
{
	if (size != A.size) 
	{
		ME osh(-1, "Negative size");
		throw osh;
	}
		
	TMatrix <T> tmp(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			for (int k = i; k <= j; k++)
				tmp.v[i][j - i] += v[i][k - i] * A.v[k][j - k];
		}
	return tmp;
}

template <class T>
TMatrix<T> TMatrix<T>::operator/(const TMatrix<T> &A)
{
	if (size != A.size) {
		
		ME osh(-1, "Different size");
		throw osh;
	}

	T det = v[0][0];
	for (int i = 1; i < size; i++)
		det = det * v[i][0];

	if (det == 0) {
		
		ME osh(-1, "Det=0");
		throw osh;
		
	}

	TMatrix <T> c1(A);
	TMatrix <T> res(size);
	for (int i = 0; i < size; i++) {
		res[i][0] = 1;
		T k = c1[i][0];
		for (int j = 0; j < size - i; j++)
		{
			c1[i][j] = c1[i][j] / k;
			res[i][j] = res[i][j] / k;
		}
	}

	for (int j = 1; j < size; j++)
	{
		for (int i = 0; i < j; i++)
		{
			T tmp = c1[i][j - i];
			for (int k = j - i, c = 0; k < size - i; k++)
			{
				c1[i][k] = c1[i][k] - c1[j][c] * tmp;
				res[i][k] = res[i][k] - res[j][c++] * tmp;
			}
		}
	}
	return ((*this) * res);
}
#endif