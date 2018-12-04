#include"ME.h"
#include<string>
#include<iostream>


	ME::ME(int _id,std::string _type):id(_id),type(_type){};

	void ME::PRINT(){
		std::cout<<"Error"<<id<<'_'<<type<<"\n";
	}