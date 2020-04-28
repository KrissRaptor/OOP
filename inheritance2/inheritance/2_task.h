#pragma once
//переделать корни

#include<ctime> // для rand()
#include"stdinlucde.h";
#include"Human.h";

class Passport : public Human
{
public:
	Passport();
	~Passport();

	void Fill_in_passport();

	void Show_passport();

protected:

	void Fill();//чтоб использовать в наследниках

	void Show();//чтоб использовать в наследниках

	short day_of_birth;
	short month_of_birth;
	short year_of_birth;

private:
	int passport_ID;
	string region;
	string city;
};

class Foreign_passport : private Passport
{
public:
	Foreign_passport();

	void Fill_in_foreign_passport();

	void Show_foreign_passport();

	void Change_country_of_Visa();

	void Fill_Visa();

private :
	
	bool presence_of_a_foreigner;//проверка на наличие загран.паспорта
	
	
	class Visa : private Passport
	{
	public:
		Visa();

		void Show_Visa_information();

		void Fill_out_of_visa();

		void Set_country_of_visa();

		/*string Get_country_of_visa();*/


	private:

		int visa_ID;
		string type_of_visa;
		string country_of_visa;

		bool Visa_availability; //проверка на наличие визы
	}visa;
};


