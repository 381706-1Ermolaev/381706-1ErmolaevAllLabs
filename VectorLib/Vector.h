#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include<cmath>
#include "ME.h"

using namespace std;

template<class T>
class Vector{
	int N;
	T *V;
public:
	Vector():N(0),V(NULL){}
	Vector(int size);
	Vector(int size,T* X);
	Vector(const Vector &O);
	int getSize();
	T& operator[](int i);//0-based
	T& operator()(int i);//1-based
	Vector& operator=(const Vector& O);
	Vector operator+()const;
	Vector operator+(Vector O);
	Vector operator-()const;
	Vector operator-(Vector O);
	double operator*(const Vector& O);
	Vector operator*(T K);
	Vector operator++();
	Vector operator++(int);
	Vector operator--();
	Vector operator--(int);
	double calcNorm(int p=2);
	bool operator==(const Vector &O);
	friend ostream& operator<<(ostream& os,const Vector& O){
		cout<<"Vector:"<<endl;
		for(int i=0;i<O.N;i++)
			os<<"["<<i<<"]="<<O.V[i]<<endl;
		os<<endl;
		return os;
	}

	friend istream& operator>>(istream& is,Vector& O){
		for(int i=0;i<O.N;i++)
			is>>O.V[i];

		return is;
	}

	~Vector(){delete []V;N=0;}
};


template<class T>
Vector<T>::Vector(int size,T* X){
	N=size;
	V=new T[N];
	for(int i=0;i<N;i++)
		V[i]=X[i];
}

template<class T>
Vector<T>::Vector(int size):N(size){
	V=new T[N];
	for(int i=0;i<N;i++)
		V[i]=0;
}

template<class T>
Vector<T>::Vector(const Vector<T> &O){
	N=O.N;
	V=new T[N];
	for(int i=0;i<N;i++)
		V[i]=O.V[i];	
}

template<class T>
int Vector<T>::getSize(){return N;}

template<class T> 
T& Vector<T>::operator[](int i){
	if(i<0||i>=N)
	{
		ME osh(-1,"Not exist\n");
		throw osh;
	}
	return V[i];
}

template<class T>
T& Vector<T>::operator()(int i){
	if(i<=0||i>N)
	{
		ME osh(-1,"Not exist\n");
		throw osh;
	}
	return V[i-1];
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T> &O){
	if(this==&O)
	{
		ME osh(5,"");
		throw osh;
		abort();
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
Vector<T> Vector<T>::operator+()const{return *this;}

template<class T>
Vector<T> Vector<T>::operator++(){
	for(int i=0;i<N;i++)
		V[i]++;

	return *this;
}

template<class T>
Vector<T> Vector<T>::operator++(int){
	Vector<T> temp(*this);
	for(int i=0;i<N;i++)
		++V[i];

	return temp;
}

template<class T>
Vector<T> Vector<T>::operator-()const{
	Vector<T> a(*this);
	for(int i=0;i<N;i++)
		a.V[i]=-V[i];
	return a;
}

template<class T>
Vector<T> Vector<T>::operator--(){
	for(int i=0;i<N;i++)
		V[i]--;
	return *this;
}

template<class T>
Vector<T> Vector<T>::operator--(int){
	Vector<T> temp(*this);
	for(int i=0;i<N;i++)
		--V[i];
	return temp;
}

template<class T>
Vector<T> Vector<T>::operator+(Vector<T> O){
	if(N!=O.N)
	{
		ME osh(0,"dimV1 != dimV2");
		throw osh;
	}
	Vector<T> a(N);
	for(int i=0;i<N;i++)
		a.V[i]=V[i]+O.V[i];
	return a;
}

template<class T>
Vector<T> Vector<T>::operator-(Vector<T> O){
	if(N!=O.N)
	{
		ME osh(0,"dimV1 != dimV2");
		throw osh;
	}
	Vector<T> a(N);
	for(int i=0;i<N;i++)
		a.V[i]=V[i]-O.V[i];
	return a;
}

template<class T>
double Vector<T>::operator*(const Vector<T> &O){
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
Vector<T> Vector<T>::operator*(T K){
	Vector<T> a(N);
	for(int i=0;i<N;i++)
		a.V[i]=K*V[i];
	return a;
}

template<class T>
double Vector<T>::calcNorm(int p){
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
bool Vector<T>::operator==(const Vector<T> &O){
	if(N!=O.N)
			return 0;

		for(int i=0;i<N;i++)
			if(V[i]!=O.V[i])
				return 0;

		return 1;
}
#endif