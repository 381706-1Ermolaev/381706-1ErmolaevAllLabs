#ifndef ME_H
#define ME_H

#include<string>

class ME{
	int id;
	std::string type;
public:
	ME(int _id,std::string _type);
	void PRINT();
};

#endif