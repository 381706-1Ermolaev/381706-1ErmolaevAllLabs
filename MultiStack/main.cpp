#include <iostream>
#include <locale.h>
#include "MultiStack.h"
using namespace std;

int  main ()
{
	TMStack<int> test1(5, 25);
	test1.Set(1, 2);
	test1.Set(1, 2);
	test1.Set(1, 2);
	test1.Set(1, 2);
	test1.Set(1, 2);
	test1.Set(1, 3);
	test1.Set(1, 2);


	//test1.Set(0, 3);


	//cout << test1.Get(2)<<endl;

	return 0;
}