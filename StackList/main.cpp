#include <iostream>
#include <locale.h>
#include "Stack.h"

using namespace std;

int  main (){
	TStack<int> A(10);
	cout << "IsEmpty:" << A.IsEmpty() << endl;
	A.Put(43);
	A.Put(42);
	cout <<"IsFull:"<< A.IsFull()<<endl;
	cout <<"Get1:"<< A.Get()<<endl;
	cout << "IsEmpty:" << A.IsEmpty() << endl;
	cout << "Get1:" << A.Get() << endl;
	cout << "IsEmpty:" << A.IsEmpty() << endl;

	return 0;
}