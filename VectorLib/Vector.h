#ifndef Vector_H
#define Vector_H

#include <iostream>
#include<cmath>
#include "ME.h"

using namespace std;

template<class T>
class TVector{
protected:
	int N;
	T *V;
public:
	TVector():N(0),V(NULL){}
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
		cout<<"TVector:"<<endl;
		for(int i=0;i<O.N;i++)
			os<<"["<<i<<"]="<<O.V[i]<<endl;
		os<<endl;
		return os;
	}

	friend istream& operator>>(istream& is,TVector& O){
		for(int i=0;i<O.N;i++)
			is>>O.V[i];

		return is;
	}

	~TVector(){delete []V;N=0;}
};


template<class T>
TVector<T>::TVector(int size,T* X){
	N=size;
	V=new T[N];
	for(int i=0;i<N;i++)
		V[i]=X[i];
}

template<class T>
TVector<T>::TVector(int size):N(size){
	V=new T[N];
	for(int i=0;i<N;i++)
		V[i]=0;
}

template<class T>
TVector<T>::TVector(const TVector<T> &O){
	N=O.N;
	V=new T[N];
	for(int i=0;i<N;i++)
		V[i]=O.V[i];	
}

template<class T>
int TVector<T>::getSize(){return N;}

template<class T> 
T& TVector<T>::operator[](int i){
	if(i<0||i>=N)
	{
		ME osh(-1,"Not exist\n");
		throw osh;
	}
	return V[i];
}

template<class T>
T& TVector<T>::operator()(int i){
	if(i<=0||i>N)
	{
		ME osh(-1,"Not exist\n");
		throw osh;
	}
	return V[i-1];
}

template<class T>
TVector<T>& TVector<T>::operator=(const TVector<T> &O){
	if(this==&O)
	{
		ME osh(5,"");
		throw osh;
	}
	


	if(N!=O.N)
	{
		delete[] V;
		N=O.N;
		V=new T[N];
	}
	for(int i=0;i<N;i++)
		V[i]=O.V[i];
	return *this;
}

template<class T>
TVector<T> TVector<T>::operator+()const{return *this;}

template<class T>
TVector<T> TVector<T>::operator++(){
	for(int i=0;i<N;i++)
		V[i]++;

	return *this;
}

template<class T>
TVector<T> TVector<T>::operator++(int){
	TVector<T> temp(*this);
	for(int i=0;i<N;i++)
		++V[i];

	return temp;
}

template<class T>
TVector<T> TVector<T>::operator-()const{
	TVector<T> a(*this);
	for(int i=0;i<N;i++)
		a.V[i]=-V[i];
	return a;
}

template<class T>
TVector<T> TVector<T>::operator--(){
	for(int i=0;i<N;i++)
		V[i]--;
	return *this;
}

template<class T>
TVector<T> TVector<T>::operator--(int){
	TVector<T> temp(*this);
	for(int i=0;i<N;i++)
		--V[i];
	return temp;
}

template<class T>
TVector<T> TVector<T>::operator+(TVector<T> O){
	if(N!=O.N)
	{
		ME osh(0,"dimV1 != dimV2");
		throw osh;
	}
	TVector<T> a(N);
	for(int i=0;i<N;i++)
		a.V[i]=V[i]+O.V[i];
	return a;
}

template<class T>
TVector<T> TVector<T>::operator-(TVector<T> O){
	if(N!=O.N)
	{
		ME osh(0,"dimV1 != dimV2");
		throw osh;
	}
	TVector<T> a(N);
	for(int i=0;i<N;i++)
		a.V[i]=V[i]-O.V[i];
	return a;
}

template<class T>
double TVector<T>::operator*(const TVector<T> &O){
	if(N!=O.N)
	{
		ME osh(0,"dimV1 != dimV2");
		throw osh;
	}
	double tmp=0;
	for(int i=0;i<N;i++)
		tmp+=V[i]*O.V[i];
	return tmp;
}

template<class T>
TVector<T> TVector<T>::operator*(T K){
	TVector<T> a(N);
	for(int i=0;i<N;i++)
		a.V[i]=K*V[i];
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
		double max=abs(V[0]);
		for(int i=1;i<N;i++)
			if(abs(V[i]>max))
				max=abs(V[i]);
		return max;
	}
	if(p==2)
	{
		double tmp=0;
		for(int i=0;i<N;i++)
			tmp+=V[i]*V[i];
		return sqrt(tmp);
	}
	return 1;
}

template<class T>
bool TVector<T>::operator==(const TVector<T> &O){
	if(N!=O.N)
	{
		ME osh(4, "Different size");
		throw osh;
	}

		for(int i=0;i<N;i++)
			if(!(V[i]==O.V[i]))
				return 0;

		return 1;
}
#endif