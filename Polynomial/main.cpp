#include <iostream>
#include <locale.h>
#include "Polynom.h"


using namespace std;

int main() {
	TMonom A(3, 0, 0);
	cin >> A;
	cout << A;
	TMonom B(3, 0, 0);
	cin >> B;
	
	TMonom* B1 = new TMonom(B);
	TPolynom K(3,A,B);
	A.SetNext(B1);
	cout << *A.GetNext();
	cout << K;


	return 0;
}