#include "Human.h"

Human::Human()
{
	name = "none";
	second_name = "none";
	age = 0;
	country = "none";
	city = "none";
	hotel_name = "none";
	month_of_departure = "none";
	day_of_departure = 0;
}

void Human::Filling_out_the_questionnaire()
{
	cout << "Enter a name : ";
	getline(cin, name);
	cout << "Enter a second name : ";
	getline(cin, second_name);
	cout << "Enter age : ";
	cin >> age;
	cin.ignore(32767, '\n');
	cout << "Enter your country : ";
	getline(cin, country);
	cout << "Enter your city : ";
	getline(cin, city);
}

void Human::Show_the_questionnaire() // анктета
{
	cout << name << " " << second_name << "\n";;
	cout << "Age : " << age << "\n";
	cout << "Country : " << country << "\n";
	cout << "City : " << city << "\n";
}

void Human::Set_name(string& name)
{
	this->name = name;
}

string Human::Get_name()
{
	return name;
}

void Human::Set_second_name(string& second_name)
{
	this->second_name = second_name;
}

string Human::Get_second_name()
{
	return second_name;
}

void Human::Set_age(short& age)
{
	this->age = age;
}

short Human::Get_age()
{
	return age;
}

void Human::Set_country_of_departure(string& country_of_departure)
{
	this->country_of_departure = country_of_departure;
}

string Human::Get_country_of_departure()
{
	return country_of_departure;
}

void Human::Set_city_of_departure(string& city_of_departure)
{
	this->city_of_departure = city_of_departure;
}

string Human::Get_city_of_departure()
{
	return city_of_departure;
}

void Human::Set_hotel_name(string& hotel_name)
{
	this->hotel_name = hotel_name;
}

string Human::Get_hotel_name()
{
	return hotel_name;
}

void Human::Set_month_of_departure(string& month_of_departure)
{
	this->month_of_departure = month_of_departure;
}

string Human::Get_month_of_departure()
{
	return month_of_departure;
}

void Human::Set_day_of_departure(int& day_of_departure)
{
	this->day_of_departure = day_of_departure;
}

int Human::Get_day_of_departure()
{
	return day_of_departure;
}
