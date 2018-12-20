#include <iostream>
#include <locale.h>
#include "MultiStack.h"
using namespace std;

int  main()
{
	cout << "Creating stack" << endl;
	TMStack<int> A(2, 8);
	int tmp = rand() % 10 + 1;
	cout << endl << tmp << " is set to 1 stack" << endl;
	A.Set(1, tmp);
	tmp = rand() % 10 + 1;
	cout << endl << tmp << " is set to 1 stack" << endl;
	A.Set(1, tmp);
	tmp = rand() % 10 + 1;
	cout << endl << tmp << " is set to 1 stack" << endl;
	A.Set(1, tmp);
	tmp = rand() % 10 + 1;
	cout << endl << tmp << " is set to 1 stack" << endl;
	A.Set(1, tmp);
	
	

	tmp = rand() % 10 + 1;
	cout << endl << tmp << " is set to 0 stack" << endl;
	A.Set(0, tmp);
	tmp = rand() % 10 + 1;
	cout << endl << tmp << " is set to 0 stack" << endl;
	A.Set(0, tmp);
	tmp = rand() % 10 + 1;
	cout << endl << tmp << " is set to 0 stack" << endl;
	A.Set(0, tmp);
	

	cout << endl << "All stacks is full!" << endl;
	cout << "Try to repack and set '4' to 1 stack" << endl;
	A.Set(1, 4);
	cout << endl << "Get elements from 1 the stack: " << endl;
	cout << A.Get(1) << endl;
	cout << A.Get(1) << endl;
	cout << A.Get(1) << endl;
	cout << A.Get(1) << endl;
	cout << endl << "Get the elements from 0 the stack: " << endl;
	cout << A.Get(0) << endl;
	cout << A.Get(0) << endl;
	return 0;
}