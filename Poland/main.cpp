#include <iostream>
#include <locale.h>
#include "Poland.h"
using namespace std;

int  main ()
{
	TString A(15,"((33-22)*33-10)");
	A.print();

	TQueue<char> B(One(A));

	cout << f(B)<<endl;

	return 0;
}