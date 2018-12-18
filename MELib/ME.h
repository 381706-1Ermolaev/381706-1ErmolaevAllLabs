#ifndef ME_H
#define ME_H

#include<string>

class ME{
public:
	int id;
	std::string type;

	ME(int _id,std::string _type);
	void PRINT();
};

	ME::ME(int _id,std::string _type):id(_id),type(_type){};

	void ME::PRINT(){
		std::cout<<"Error"<<id<<'_'<<type<<"\n";
	}

#endif