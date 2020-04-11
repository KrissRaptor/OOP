#pragma once
#include"Libraries.h"

class Human
{
public:
	
	Human();
	
	void Filling_out_the_questionnaire();
	void Show_the_questionnaire(); // анктета


	void Set_name(string& name);
	string Get_name();
	void Set_second_name(string& second_name);
	string Get_second_name();
	
	void Set_age(short& age);
	short Get_age();
	void Set_country_of_departure(string& country_of_departure);
	string Get_country_of_departure();
	void Set_city_of_departure(string& city_of_departure);
	string Get_city_of_departure();
	void Set_hotel_name(string& hotel_name);
	string Get_hotel_name();
	void Set_month_of_departure(string& month_of_departure);
	string Get_month_of_departure();
	void Set_day_of_departure(int& day_of_departure);
	int Get_day_of_departure();

private:

	string name;
	string second_name;
	short age;
	string country;
	string city;

	string country_of_departure;
	string city_of_departure;

	string hotel_name;
	string month_of_departure;
	int day_of_departure;
};

