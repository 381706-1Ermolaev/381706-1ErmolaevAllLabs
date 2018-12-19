#pragma once
#include"Queue.h"
#include<iostream>

using namespace std;

class TString {
	int size;
	char* mas;
public:
	TString() { size = 0; mas = 0; }
	TString(int _size,char* _mas) { 
		size = _size;
		mas = new char[size];
		for (int i = 0; i < size; i++)
			mas[i] = _mas[i];
	}
	TString(TString& other) {
		size = other.size;
		mas = new char[size];
		for (int i = 0; i < size; i++)
			mas[i] = other.mas[i];
	}
	char& operator[](int i) {return mas[i];}
	void print() 
	{
		for (int i = 0; i < size; i++)
			cout << mas[i];

		cout << endl;
	}


	int getSize() { return size; }

};

int Getprior(const char a)
{
	switch (a)
	{
	case '(':
		return 0;
	case ')':
		return 1;
	case '+':
		return 2;
	case '-':
		return 2;
	case '*':
		return 3;
	case '/':
		return 3;
	default:
		return -1;
	}
}

bool IsOperation(char a)
{
	return (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')');
}

TQueue<char> One(TString s)
{
	TQueue<char> res(3*s.getSize());
	TStack<char> st(3*s.getSize());
	for (int i = 0; i < s.getSize(); i++)
	{
		if (i == 0)
			if (s[0] == '-') {
				res.Put('[');
				res.Put('0');
				res.Put(']');
				
			}
			
				if (!IsOperation(s[i]))
				{
					res.Put('[');

					while ((i + 1 != s.getSize()) && !IsOperation(s[i + 1])) {
						res.Put(s[i]);
						i++;
					}

					res.Put(s[i]);
					res.Put(']');
				}
				else
				{
					if (s[i] == ')')
					{
						while (st.GetW() != '(')
							res.Put(st.Get());
						st.Get();
					}
					else
					{
						if (s[i] == '(')
							st.Put(s[i]);
						else
							if (st.IsEmpty())
								st.Put(s[i]);
							else
								if (Getprior(s[i]) > Getprior(st.GetW()))
									st.Put(s[i]);
								else
								{
									while ((!st.IsEmpty())&&(Getprior(s[i]) <= Getprior(st.GetW())))
										res.Put(st.Get());

									st.Put(s[i]);
								}
					}
				}


			}
	
	while (!st.IsEmpty())
		res.Put(st.Get());

	return res;
}

int num(char A) {
	return A - '0';
}

double f(TQueue<char> q)
{
	double res;
	TStack<double> st2(q.GetSize());
	while (!q.IsEmpty())
	{
		char A = q.Get();
		if (!IsOperation(A)) 
		{
			double tmp;
			A = q.Get();
			
			tmp = num(A);
			
			while ((q.GetW() != ']') && (!q.IsEmpty())) 
			{
				A = q.Get();
				
				tmp = tmp*10 + num(A);
				
			}
			q.Get();
			st2.Put(tmp);
		}
		else
		{
			double y = st2.Get();
			double x = st2.Get();
			double z = 0;
			if (A == '+') z = x + y;
			if (A == '-') z = x - y;
			if (A == '*') z = x * y;
			if (A == '/') z = x / y;
			st2.Put(z);
		}
	}
	res = st2.Get();
	return res;
}


