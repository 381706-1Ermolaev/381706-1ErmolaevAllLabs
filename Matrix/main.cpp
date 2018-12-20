#include <iostream>
#include "Matrix.h"
using namespace std;

int main ()
{
	TMatrix<double> A(2);
	TMatrix<double> B(2);
	TMatrix<double> C(2);
	A[0][0] = 1;
	A[1][0] = 1;
	B[0][0] = 0.5;
	B[1][0] = 0.5;
	C[0][0] = 2;
	C[1][0] = 2;
	cout << (A == B) << endl;
	cout << A;
	cout << B;
	cout << A / B;
	cout << C;
	cout<< (C == A / B)<< endl;
}