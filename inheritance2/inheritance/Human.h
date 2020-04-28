#pragma once
#include"stdinlucde.h"
#include <string> //для работы со строками

using std::string;
using std::cin;

class Human //уменьшаем копипаст,так как используется в разных классах
{
public:
	Human();
	~Human();
protected:
	string name;
	string second_name;
	string patronymic;//отчество
	string сitizenship;//гражданство 
	string gender; //пол
	short age;
};