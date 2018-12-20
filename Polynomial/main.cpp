#include <iostream>
#include <locale.h>
#include "Polynom.h"


using namespace std;

int main() {

	int *mas = new int[3];
	mas[0] = 1;
	mas[1] = 2;
	mas[2] = 3;
	TMonom A(3, mas, 3);
	
	//cout << A<<endl;

	TMonom B(A);
	//cout << B<< endl;
	
	TMonom * A1= &A;
	//cout << *A1 << endl;
	TMonom C(A);
	C = A * B;
	//cout << C<<endl;
	
	C.SetNext(A1);
	//cout << *C.GetNext()<<endl;
	TMonom * C1 = &C;
	TPolynom P(3,C1,A1);
	//TPolynom P2(P);
	cout << P << endl;

	return 0;
}