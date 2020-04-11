#pragma once

#include"stdinlucde.h"
#include"Human.h"

class Student : public Human
{

public:
	Student();

	Student(string name, string second_name, string adress, string telephone_number, short age);

	~Student();

	void Student_registration();

	void Student_information();

	
	string Get_name();

	void Set_name();

	
	string Get_second_name();
	
	void Set_second_name();


	string Get_adress();

	void Set_adress();


	string Get_telephone_number();

	void Set_telephone_number();


	short Get_age();

	void Set_age();

protected:
	void Registration();//для испольвон в наследниках

	string telephone_number;
	string adress;
};

class Aspirant : public Student
{
public:
	Aspirant();

	Aspirant(string name, string second_name, string adress, string telephone_number, short age, string theme_of_candidate_work);

	~Aspirant();

	void Write_a_candidate_work();

	void Show_a_candidate_work();

protected:
	string theme_of_candidate_work;
	string text_of_candidate_work;
};

