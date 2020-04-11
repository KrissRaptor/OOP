#pragma once

#include"Human.h"


template <typename T>
void Show(std::vector<T>& other);//показывает элементы вектора

template <typename T>
void Object_search_input(std::vector<T>& other, const string type_of_object);//делает ввод данных для поиска объекта

template <typename T>
typename std::vector<T>::iterator Object_search_output(std::vector<T>& other, string& key, const string type_of_object);//делает поиск итератора


class Travel_agency
{
public:

	Travel_agency();

	void Menu();

private:

	std::vector<string>cities;//вектор стран
	std::vector<string>countries;//вектор городов
	std::vector<string>hotels_name;//вектор отелей стран

	std::vector<int>departure_days;//вектор дней отправления
	std::vector<int>months_of_departure;//вектор месяцев отправления
	
	std::vector<int>city_​​popularity_counter;
	std::vector<int>countries_popularity_counter;

	std::vector<Human>tourists; //массив для хранения туристов

	string country;
	string city;
	string hotel_name;

	string month_of_departure;
	int day_of_departure;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//заполение всех векторов по умолчанию
	void Fill_vector_countries();

	void Fill_vector_cities();

	void Fill_departure_days();

	void Fill_months_of_departure();//8 месяцев

	void Fill_hotel_name();

	void Fill_city_​​popularity_counter();
	
	void Fill_countries_popularity_counter();
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void Exit();

	void Show_with_index(std::vector<string>& other, int& index_begin, int& index_end);//показ стран,городов по индексу

	void Enter_city_by_index(int index_begin, int index_end);//показ городов в зависимости от выбранной страны

	void Enter_hotel_by_index(int index_begin, int index_end);//показ отелей в зависимости от выбранной страны
	
	void Add_popularity(std::vector<string>& other, string& object, std::vector<int>& object_popularity_counter);//добавление популярности 

	void Show_popularity_output(std::vector<int>& object_popularity_counter, const string name_of_object);//вывод популярных стран,городов ,отелей

	string Search_index(int& index, int& number);//часть метода Show_popularity ,делает поиск и вывод города,страны по индексу

	template <typename T>
	friend void Show(std::vector<T>& other);//показывает элементы вектора

	template <typename T>//делает ввод данных для поиска объекта
	friend void Object_search_input(std::vector<T>& other, const string type_of_object);

	template <typename T>//делает поиск итератора
	friend typename std::vector<T>::iterator Object_search_output(std::vector<T>& other, string& key, const string type_of_object);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void Hotel_search();

	void City_​​search();

	void Country_search();

	void Serch_by_last_name();

	void Date_Search();

	void Date_Search2();

	void Show_popularity_input(string name);//ввод информации для показа популярных стран,городов ,отелей

	void Show_months_of_departure();

	void Voucher_information();

	void Get_a_ticket();
};




template <typename T>
void Show(std::vector<T>& other)
{
	for (typename std::vector<T>::iterator it = other.begin(); it != other.end(); ++it)
	{
		cout << *it << std::endl;
	}
}


template <typename T>
void Object_search_input(std::vector<T>& other, const string type_of_object)//уменьшаем копипаст
{

	string key;
	cout << "Enter name of " << type_of_object << " : ";
	getline(cin, key);

	cout << *(Object_search_output(other, key, type_of_object)) << std::endl;
}


template <typename T>
typename std::vector<T>::iterator Object_search_output(std::vector<T>& other, string& key, const string type_of_object)//уменьшаем копипаст
{
	while (true)//цикл поиска
	{
		bool obj_existence = false;

		for (typename std::vector<T>::iterator it = other.begin(); it != other.end(); ++it)//поиск элемента
		{
			if (*it == key)
			{
				obj_existence = true;
				return it;
			}
		}
		if (obj_existence == false) //проверка на наличие найденного элемента
		{
			cout << "Error, this " << type_of_object << " is not listed.Enter a " << type_of_object << " from the list : ";
			getline(cin, key);
		}
	}
}