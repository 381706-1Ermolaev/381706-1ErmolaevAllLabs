#include <iostream>
#include <locale.h>
#include "Poland.h"
using namespace std;

int  main ()
{
	TString A(3,"9-3");
	A.print();

	TQueue<char> B(One(A));
	cout << f(B)<<endl;


	return 0;
}