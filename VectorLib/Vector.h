#ifndef Vector_H
#define Vector_H

#include <iostream>
#include<cmath>
#include "ME.h"

using namespace std;

template<class T>
class TVector{
protected:
	int size;
	T *v;
public:
	TVector():size(0),v(NULL){}
	TVector(int size);
	TVector(int size,T* X);
	TVector(const TVector &O);
	int getSize();
	T& operator[](int i);//0-based
	T& operator()(int i);//1-based
	TVector& operator=(const TVector& O);
	TVector operator+()const;
	TVector operator+(TVector O);
	TVector operator-()const;
	TVector operator-(TVector O);
	double operator*(const TVector& O);
	TVector operator*(T K);
	TVector operator++();
	TVector operator++(int);
	TVector operator--();
	TVector operator--(int);
	double calcNorm(int p=2);
	bool operator==(const TVector &O);
	friend ostream& operator<<(ostream& os,const TVector& O){
		for(int i=0;i<O.size;i++)
			os<<"["<<O.v[i]<<"]";

		os<<endl;
		return os;
	}

	friend istream& operator>>(istream& is,TVector& O){
		for(int i=0;i<O.size;i++)
			is>>O.v[i];

		return is;
	}

	~TVector(){delete []v; size =0;}
};


template<class T>
TVector<T>::TVector(int _size,T* X){
	size = _size;
	v = new T[size];
	for(int i=0;i<size;i++)
		v[i]=X[i];
}

template<class T>
TVector<T>::TVector(int _size):size(_size){
	v=new T[size];
	for(int i=0;i<size;i++)
		v[i]=0;
}

template<class T>
TVector<T>::TVector(const TVector<T> &O){
	size =O.size;
	v=new T[size];
	for(int i=0;i<size;i++)
		v[i]=O.v[i];	
}

template<class T>
int TVector<T>::getSize(){return size;}

template<class T> 
T& TVector<T>::operator[](int i){
	if(i<0||i>= size)
	{
		ME osh(-1,"Not exist\n");
		throw osh;
	}
	return v[i];
}

template<class T>
T& TVector<T>::operator()(int i){
	if(i<=0||i>size)
	{
		ME osh(-1,"Not exist\n");
		throw osh;
	}
	return v[i-1];
}

template<class T>
TVector<T>& TVector<T>::operator=(const TVector<T> &O){
	if(this==&O)
	{
		ME osh(5,"");
		throw osh;
	}
	


	if(size !=O.size)
	{
		delete[] v;
		size =O.size;
		v=new T[size];
	}
	for(int i=0;i<size;i++)
		v[i]=O.v[i];
	return *this;
}

template<class T>
TVector<T> TVector<T>::operator+()const{return *this;}

template<class T>
TVector<T> TVector<T>::operator++(){
	for(int i=0;i<size;i++)
		v[i]++;

	return *this;
}

template<class T>
TVector<T> TVector<T>::operator++(int){
	TVector<T> temp(*this);
	for(int i=0;i<size;i++)
		++v[i];

	return temp;
}

template<class T>
TVector<T> TVector<T>::operator-()const{
	TVector<T> a(*this);
	for(int i=0;i<size;i++)
		a.v[i]=-v[i];
	return a;
}

template<class T>
TVector<T> TVector<T>::operator--(){
	for(int i=0;i<size;i++)
		v[i]--;
	return *this;
}

template<class T>
TVector<T> TVector<T>::operator--(int){
	TVector<T> temp(*this);
	for(int i=0;i<size;i++)
		--v[i];
	return temp;
}

template<class T>
TVector<T> TVector<T>::operator+(TVector<T> O){
	if(size !=O.size)
	{
		ME osh(0,"dimV1 != dimV2");
		throw osh;
	}
	TVector<T> a(size);
	for(int i=0;i<size;i++)
		a.v[i]=v[i]+O.v[i];
	return a;
}

template<class T>
TVector<T> TVector<T>::operator-(TVector<T> O){
	if(size !=O.size)
	{
		ME osh(0,"dimV1 != dimV2");
		throw osh;
	}
	TVector<T> a(size);
	for(int i=0;i<size;i++)
		a.v[i]=v[i]-O.v[i];
	return a;
}

template<class T>
double TVector<T>::operator*(const TVector<T> &O){
	if(size !=O.size)
	{
		ME osh(0,"dimV1 != dimV2");
		throw osh;
	}
	double tmp=0;
	for(int i=0;i<size;i++)
		tmp+=v[i]*O.v[i];
	return tmp;
}

template<class T>
TVector<T> TVector<T>::operator*(T K){
	TVector<T> a(size);
	for(int i=0;i<size;i++)
		a.v[i]=K*v[i];
	return a;
}

template<class T>
double TVector<T>::calcNorm(int p){
	if(p!=1 && p!=2)
	{
		ME osh(2," there is no such rule");
		throw osh;
	}
	if(p==1)
	{
		double max=abs(v[0]);
		for(int i=1;i<size;i++)
			if(abs(v[i]>max))
				max=abs(v[i]);
		return max;
	}
	if(p==2)
	{
		double tmp=0;
		for(int i=0;i<size;i++)
			tmp+=v[i]*v[i];
		return sqrt(tmp);
	}
	return 1;
}

template<class T>
bool TVector<T>::operator==(const TVector<T> &O){
	if(size !=O.size)
	{
		
		ME osh(4, "Different size");
		throw osh;
	}

		for(int i=0;i<size;i++)
			if (!(v[i] == O.v[i])) {
				return 0;
			}
		return 1;
}
#endif