#pragma once
#include"stdinlucde.h"
#include <string> //��� ������ �� ��������

using std::string;
using std::cin;

class Human //��������� ��������,��� ��� ������������ � ������ �������
{
public:
	Human();
	~Human();
protected:
	string name;
	string second_name;
	string patronymic;//��������
	string �itizenship;//����������� 
	string gender; //���
	short age;
};