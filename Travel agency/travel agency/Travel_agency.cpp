#include "Travel_agency.h"

void Travel_agency:: Fill_vector_countries()
{
	countries.resize(6);

	countries[0] = "U.S.A.";
	countries[1] = "Turkey";
	countries[2] = "Egypt";
	countries[3] = "Indonesia";
	countries[4] = "Spain";
}

void Travel_agency :: Fill_vector_cities()
{
	cities.resize(15);

	//USA
	cities[0] = "Los Angeles";
	cities[1] = "New York";
	cities[2] = "Seattle";
	//Turkey
	cities[3] = "Antalya";
	cities[4] = "Belek";
	cities[5] = "Side";
	cities[6] = "Marmaris";
	//Egypt
	cities[7] = "Sharm El Sheikh";
	cities[8] = "Sahl Hasheesh";
	cities[9] = "Safaga";
	//Indonesia
	cities[10] = "Bali";
	//Spain
	cities[11] = "Ibiza";
	cities[12] = "Costa del Sol Read";
	cities[13] = "Costa Brava";
}

void Travel_agency:: Fill_departure_days()
{
	departure_days.resize(25);

	//Январь
	departure_days[0] = 5;
	departure_days[1] = 17;
	departure_days[2] = 26;
	//Февраль
	departure_days[3] = 3;
	departure_days[4] = 18;
	departure_days[5] = 24;
	//Март
	departure_days[6] = 3;
	departure_days[7] = 17;
	departure_days[8] = 19;
	//Июнь
	departure_days[9] = 10;
	departure_days[10] = 12;
	departure_days[11] = 25;
	//Июль
	departure_days[12] = 5;
	departure_days[13] = 15;
	departure_days[14] = 25;
	//Август
	departure_days[15] = 1;
	departure_days[16] = 11;
	departure_days[17] = 23;
    //Октябрь
	departure_days[18] = 2;
	departure_days[19] = 12;
	departure_days[20] = 22;
	//Декабрь
	departure_days[21] = 5;
	departure_days[22] = 16;
	departure_days[23] = 27;
}

void Travel_agency :: Fill_months_of_departure()//8 месяцев
{
	months_of_departure.resize(9);

	months_of_departure[0] = 6; //Июнь
	months_of_departure[1] = 7; //Июль
	months_of_departure[2] = 8; //Август

	months_of_departure[3] = 1; //Январь
	months_of_departure[4] = 2; //Февраль
	months_of_departure[5] = 12; //Декабрь

	months_of_departure[6] = 3;//Март

	months_of_departure[7] = 10;//Октябрь
}

void Travel_agency :: Fill_hotel_name()
{
	hotels_name.resize(16);
	//USA
	hotels_name[0] = "Hotel NH Collection A Coruna Finisterre";
	hotels_name[1] = "Freehand Los Angeles";
	hotels_name[2] = "The New Yorker, A Wyndham Hotel";
	//Turkey
	hotels_name[3] = "Alaiye Kleopatra Hotel & Apart";
	hotels_name[4] = "Taskonak Hotel";
	hotels_name[5] = "Angora Hotel";
	//Egypt
	hotels_name[6] = "Hurghada Marriott Beach Resort";
	hotels_name[7] = "Pyramids Plaza Hotel";
	hotels_name[8] = "Hilton Sharm Waterfalls Resort";
	//Indonesia
	hotels_name[9] = "Hanging Gardens Of Bali";
	hotels_name[10] = "Nandini Jungle Resort and Spa Bali";
	hotels_name[11] = "Senetan Villas & Spa Resort";
	//Spain
	hotels_name[12] = "Hotel NH Collection A Coruna Finisterre";
	hotels_name[13] = "Melia Alicante";
	hotels_name[14] = "Melia Costa del Sol";
}

void Travel_agency::Fill_city_​​popularity_counter()
{
	city_​​popularity_counter.resize(15, 0);

	//city_​​popularity_counter[0];"Los Angeles";
	//city_​​popularity_counter[1];"New York";
	//city_​​popularity_counter[2];"Seattle";
	
	//city_​​popularity_counter[3];"Antalya";
	//city_​​popularity_counter[4];"Belek";
	//city_​​popularity_counter[5];"Side";
	//city_​​popularity_counter[6];"Marmaris";
	
	//city_​​popularity_counter[7];"Sharm El Sheikh";
	//city_​​popularity_counter[8];"Sahl Hasheesh";
	//city_​​popularity_counter[9];"Safaga";
	
	//city_​​popularity_counter[10] "Bali";;
	
	//city_​​popularity_counter[11] "Ibiza";;
	//city_​​popularity_counter[12] "Costa del Sol Read";;
	//city_​​popularity_counter[13] "Costa Brava";;
}

void Travel_agency::Fill_countries_popularity_counter()
{
	countries_popularity_counter.resize(6, 0);

	//countries_popularity_counter[0];"U.S.A.";
	//countries_popularity_counter[1];"Turkey";
	//countries_popularity_counter[2];"Egypt";
	//countries_popularity_counter[3];"Indonesia";
	//countries_popularity_counter[4];"Spain";
}

Travel_agency::Travel_agency()
{    
     Fill_vector_countries();
     Fill_vector_cities();
     Fill_city_​​popularity_counter();
     Fill_countries_popularity_counter();
     Fill_departure_days();
     Fill_months_of_departure();
     Fill_hotel_name();
}

void Travel_agency::Menu()
{
	while (true)
	{
		system("cls");

		cout << "\t\t\tWelcome to ALLY tourist agency!!\n";
		cout << "\t\t\t\tPress keys 1-13\n";

		cout << "\t\t1.See countries \n";
		cout << "\t\t2.See popular country \n";
		cout << "\t\t3.Countries search \n";
		cout << "\t\t4.See cities \n";
		cout << "\t\t5.See the popular city \n";
		cout << "\t\t6.City search\n";
		cout << "\t\t7.Hotel_search \n";
		cout << "\t\t8.Date Search \n";
		cout << "\t\t9.See departure date \n";
		cout << "\t\t10.Search by last name \n";
		cout << "\t\t11.Get a ticket \n";//оформить путёвку
		cout << "\t\t12.Voucher information \n";//информация о путёвке
		cout << "\t\t13.Exit \n";

		int key;
		while (true)//проверка
		{
			cin >> key;
			if (key >= 14 || key <= 0)
			{
				//continue;
				cout << "Error ,press keys 1-13! ";
			}
			else
			{
				break;
			}
		}

		switch (key)
		{
		case 1://работает
			system("cls");
			Show(countries);
			Exit();
			break;
		case 2:
			system("cls");
			Show_popularity_input("country");//работает
			Exit();
			break;
		case 3:
			system("cls");
			cin.ignore(32767, '\n');
			Country_search();//работает
			Exit();
			break;
		case 4:
			system("cls");//работает
			Show(cities);
			Exit();
			break;
		case 5:
			system("cls");
			cin.ignore(32767, '\n');
			Show_popularity_input("city");//работает
			Exit();
			break;
		case 6:
			system("cls");
			cin.ignore(32767, '\n');
			City_​​search();//работает
			Exit();
			break;
		case 7:
			system("cls");
			Hotel_search();//работает
			Exit();
			break;
		case 8:
			system("cls");
			Date_Search();//работает
			Exit();
			break;
		case 9:
			system("cls");//работает
			Show_months_of_departure();
			Exit();
			break;
		case 10:
			system("cls");
			cin.ignore(32767, '\n');
			Serch_by_last_name();//работает
			Exit();
			break;
		case 11:
			system("cls");
			cin.ignore(32767, '\n');
			Get_a_ticket();//работает
			Exit();
			break;
		case 12:
			system("cls");
			cin.ignore(32767, '\n');
			Voucher_information();//работает
			Exit();
			break;
		case 13:
			return;
		default:
			break;
		}
	}
}

void Travel_agency::Hotel_search()
{	
	Show(countries);

	cout << "Enter the name of the country you want to travel : ";
	
	string key;
	
	std::cin.ignore(32767, '\n');
	getline(cin, key);

	country = *(Object_search_output(countries, key, "country"));

	if (country == "U.S.A.")
	{
		Enter_hotel_by_index(0, 3);
	}
	else if (country == "Turkey")
	{
		Enter_hotel_by_index(3, 6);
	}
	else if (country == "Egypt")
	{
		Enter_hotel_by_index(6, 9);
	}
	else if (country == "Indonesia")
	{
		Enter_hotel_by_index(9, 11);
	}
	else if (country == "Spain")
	{
		Enter_hotel_by_index(12, 15);
	}
}

void Travel_agency::City_​​search()
{
	//Object_search(cities, "city");

	Show(countries);

	cout << "Enter the name of the country you want to travel : ";
	
	string key;
	
	//std::cin.ignore(32767, '\n');
	getline(cin, key);

	country = *(Object_search_output(countries, key, "country"));

	if (country == "U.S.A.")
	{
		Enter_city_by_index(0, 3);
	}
	else if (country == "Turkey")
	{
		Enter_city_by_index(3, 7);
	}
	else if (country == "Egypt")
	{
		Enter_city_by_index(7, 10);
	}
	else if (country == "Indonesia")
	{
		Enter_city_by_index(10, 11);
	}
	else if (country == "Spain")
	{
		Enter_city_by_index(11, 14);
	}


}

void Travel_agency::Exit()
{
	int answer;
	cout << "Press 5 to exit " << std::endl;
	while (true) 
	{
		cin >> answer;

		if (answer == 5)
		{
			return;
		}
		else
		{
			continue;
		}
	}

}

void Travel_agency::Show_with_index(std::vector<string>& other, int& index_begin, int& index_end)
{
	for (int i = index_begin; i < index_end; i++)
	{
		cout << other[i] << std::endl;
	}
}

void Travel_agency::Enter_city_by_index(int index_begin, int index_end)
{
	cout << "Cities to which there is a trip: \n";
	Show_with_index(cities, index_begin, index_end);
	cout << "Enter the name of the city : ";

	string key;
	getline(cin, key);

	city = *(Object_search_output(cities, key, "city"));

	Add_popularity(cities, city, city_​​popularity_counter);
}

void Travel_agency::Enter_hotel_by_index(int index_begin, int index_end)
{
	cout << "Hotel chain in the selected country: \n\n";
	Show_with_index(hotels_name, index_begin, index_end);
	cout << "\nEnter the name of the hotel : ";
	//Object_search(countries, "country");

	string key;
	getline(cin, key);

	hotel_name = *(Object_search_output(hotels_name, key, "hotel"));
}

void Travel_agency::Country_search()
{

	Show(countries);
	Object_search_input(countries, "country");
	Add_popularity(countries, country,countries_popularity_counter);
}


void Travel_agency::Serch_by_last_name()
{

	string key;

	cout << "Enter your last name to see the ticket : ";

	bool object_availability = false;//для того чтоб выводить ошибку если имя не найдено
	while (object_availability == false)
	{
		//cin.ignore(32767, '\n');  //что-то тут не так ,или засталяет по 2 пробела ,или что-то ещё
		
		getline(cin, key);//FGFGG
		if (key == "Y" || key == "y")
		{
			return;
		}


		for (int i = 0; i < tourists.size(); ++i)
		{
			if (key == tourists[i].Get_second_name())
			{
				cout << tourists[i].Get_second_name();
				object_availability = true;
				break;
			}
		}
		if (object_availability == false)
		{
			cout << "Error,not found such last name.Enter correct key or press Y to exit ";
		}
	}
}
void Travel_agency::Show_months_of_departure()
{
	cout << "January : " << departure_days.at(0) << " " << departure_days.at(1) << " " << departure_days.at(2) << "\n";
	cout << "February : " << departure_days.at(3) << " " << departure_days.at(4) << " " << departure_days.at(5) << "\n";
	cout << "March : " << departure_days.at(6) << " " << departure_days.at(7) << " " << departure_days.at(8) << "\n";
	cout << "June : " << departure_days.at(9) << " " << departure_days.at(10) << " " << departure_days.at(11) << "\n";
	cout << "July : " << departure_days.at(12) << " " << departure_days.at(13) << " " << departure_days.at(14) << "\n";
	cout << "August : " << departure_days.at(15) << " " << departure_days.at(16) << " " << departure_days.at(17) << "\n";
	cout << "October : " << departure_days.at(18) << " " << departure_days.at(19) << " " << departure_days.at(20) << "\n";
	cout << "December : " << departure_days.at(21) << " " << departure_days.at(22) << " " << departure_days.at(23) << "\n";
}




void Travel_agency::Voucher_information()
{
	string key;

	cout << "Enter your last name to see the ticket : ";

	bool object_availability = false;//для того чтоб выводить ошибку если имя не найдено
	while (object_availability == false)
	{
		//cin.ignore(32767, '\n');
		getline(cin, key);

		if (key == "Y" || key == "y")
		{
			return;
		}

		for (int i = 0; i < tourists.size(); ++i)
		{
			if (key == tourists[i].Get_second_name())
			{
				tourists[i].Show_the_questionnaire();
				
				cout << "Country of departure : " << tourists[i].Get_country_of_departure() << "\n";
				cout << "City of departure : " << tourists[i].Get_city_of_departure() << "\n";
				cout << "Hotel name : " << tourists[i].Get_hotel_name() << "\n";
				cout << "Date of departure : " << tourists[i].Get_month_of_departure() << " " << tourists[i].Get_day_of_departure() << "\n";

				object_availability = true;
				break;
			}
		}
		if(object_availability == false)
		{
			cout << "Error,not found such last name.Enter again or press Y to exit ";
		}
	}
}

void Travel_agency::Date_Search2()
{
	Show_months_of_departure();

	//поиск по месяцам //даже лучше оформление даты поездки

	cout << "Enter the month in which you want to go : ";

	string tmp_month;//ввод нужного нам месяца
	int tmp_departure_day = 0; //ввод нужного нам дня отправки

	//cin >> tmp_month;
	while (true)//цикл для проверки на правильность ввода
	{
		cin >> tmp_month;

		if (tmp_month == "January")
		{
			month_of_departure = "January";
			break;
		}
		else if (tmp_month == "February")
		{
			month_of_departure = "February";
			break;
		}
		else if (tmp_month == "March")
		{
			month_of_departure = "March";
			break;
		}
		else if (tmp_month == "June")
		{
			month_of_departure = "June";
			break;
		}
		else if (tmp_month == "July")
		{
			month_of_departure = "July";
			break;
		}
		else if (tmp_month == "August")
		{
			month_of_departure = "August";
			break;
		}
		else if (tmp_month == "October")
		{
			month_of_departure = "October";
			break;
		}
		else if (tmp_month == "December")
		{
			month_of_departure = "December";
			break;
		}
		else
		{
			cout << "Error , we have no trips this month.Try again pls! \n";
		}
	}

	cout << "Enter the day of the trip : ";
	cin >> tmp_departure_day;

	//проверка на ввод дня отправки ,в случае ввода дня отправки ,которого нет в месяце то будет ошибка
	while (true) 
	{   
		if (month_of_departure == "January")
		{
			if (tmp_departure_day == departure_days.at(0) || tmp_departure_day == departure_days.at(1) || tmp_departure_day == departure_days.at(2))
			{
				day_of_departure = tmp_departure_day;
				break;
			}
			else
			{
				cout << "Error! no such departure date.Enter again please : \n";
			}
		}
		else if (month_of_departure == "February")
		{
			if (tmp_departure_day == departure_days.at(3) || tmp_departure_day == departure_days.at(4) || tmp_departure_day == departure_days.at(5))
			{
				day_of_departure = tmp_departure_day;
				break;
			}
			else
			{
				cout << "Error! no such departure date.Enter again please : \n";
			}
		}
		else if (month_of_departure == "March")
		{
			if (tmp_departure_day == departure_days.at(6) || tmp_departure_day == departure_days.at(7) || tmp_departure_day == departure_days.at(8))
			{
				day_of_departure = tmp_departure_day;
				break;
			}
			else
			{
				cout << "Error! no such departure date.Enter again please : \n";
			}
		}
		else if (month_of_departure == "June")
		{
			if (tmp_departure_day == departure_days.at(9) || tmp_departure_day == departure_days.at(10) || tmp_departure_day == departure_days.at(11))
			{
				day_of_departure = tmp_departure_day;
				break;
			}
			else
			{
				cout << "Error! no such departure date.Enter again please : \n";
			}
		}
		else if (month_of_departure == "July")
		{
			if (tmp_departure_day == departure_days.at(12) || tmp_departure_day == departure_days.at(13) || tmp_departure_day == departure_days.at(14))
			{
				day_of_departure = tmp_departure_day;
				break;
			}
			else
			{
				cout << "Error! no such departure date.Enter again please : \n";
			}
		}
		else if (month_of_departure == "August")
		{
			if (tmp_departure_day == departure_days.at(15) || tmp_departure_day == departure_days.at(16) || tmp_departure_day == departure_days.at(17))
			{
				day_of_departure = tmp_departure_day;
				break;
			}
			else
			{
				cout << "Error! no such departure date.Enter again please : \n";
			}
		}
		else if (month_of_departure == "October")
		{
			if (tmp_departure_day == departure_days.at(18) || tmp_departure_day == departure_days.at(19) || tmp_departure_day == departure_days.at(20))
			{
				day_of_departure = tmp_departure_day;
				break;
			}
			else
			{
				cout << "Error! no such departure date.Enter again please : \n";
			}
		}
		else if (month_of_departure == "December")
		{
			if (tmp_departure_day == departure_days.at(21) || tmp_departure_day == departure_days.at(22) || tmp_departure_day == departure_days.at(23))
			{
				day_of_departure = tmp_departure_day;
				break;
			}
			else
			{
				cout << "Error! no such departure date.Enter again please : \n";
			}
		}
	}

}


void Travel_agency::Get_a_ticket()
{
	cout << "Fill out a form about you\n";

	Human tourist;//каждый раз создаем нового туриста

	tourist.Filling_out_the_questionnaire();

	cout << "\n";
	//tourists.push_back(tourist);

	City_​​search();
	cout << "\n";
	Date_Search2();
	cout << "\n";
	Hotel_search();
    
	tourist.Set_country_of_departure(country);
	tourist.Set_city_of_departure(city);
	tourist.Set_hotel_name(hotel_name);

	tourist.Set_month_of_departure(month_of_departure);
	tourist.Set_day_of_departure(day_of_departure);

	tourists.push_back(tourist);
	
	cout << "Thank you for choosing our travel agency. Have a nice vacation!\n";
}

void Travel_agency::Date_Search()//бесполезный надо удалить
{
	
	//поиск по месяцам //даже лучше оформление даты поездки

	cout << "January \n";//вывод
	cout << "February \n";
	cout << "March \n";
	cout << "June \n"; 
	cout << "July \n";
	cout << "August \n"; 
	cout << "October \n";
	cout << "December \n";
	
	cout << "Enter the month in which you want to go : ";
	
	//int tmp_month =0;
	string answer;//ввод нужного нам месяца

	//cin >> tmp_month;
	while (true)
	{
		cin >> answer;

		if (answer == "January")
		{
			month_of_departure = "January";
			break;
		}
		else if (answer == "February")
		{
			month_of_departure = "February";
			break;
		}
		else if (answer == "March")
		{
			month_of_departure = "March";
			break;
		}
		else if (answer == "June")
		{
			month_of_departure = "June";
			break;
		}
		else if (answer == "July")
		{
			month_of_departure = "July";
			break;
		}
		else if (answer == "August")
		{
			month_of_departure = "August";
			break;
		}
		else if (answer == "October")
		{
			month_of_departure = "October";
			break;
		}
		else if (answer == "December")
		{
			month_of_departure = "December";
			break;
		}
		else
		{
			cout << "Error , we have no trips this month.Try again pls! \n";
		}
	}
}

void Travel_agency::Add_popularity(std::vector<string>& other, string& object, std::vector<int>& object_popularity_counter)
{
	int index = 0;

	for (int i = 0; i < other.size(); ++i)
	{
		if (object == other.at(i))
		{
			index = i;
			break;
		}
	}

	object_popularity_counter.at(index) += 1;//увеличение счётчика на 1
}

void Travel_agency::Show_popularity_output(std::vector<int>& object_popularity_counter,const string name_of_object)
{
	int number_of_trips = 0;
	int index = 0;

	int nubmer_of_object=0;//для того чтоб Search_index понимал ,он ищет страну или город

	for (int i = 0; i < object_popularity_counter.size(); ++i)
	{
		if (object_popularity_counter.at(i) > number_of_trips)
		{
			number_of_trips = object_popularity_counter.at(i);
			index = i;
		}
	}

	if (name_of_object == "country")
	{
		nubmer_of_object = 2;
	}
	else if (name_of_object == "city")
	{
		nubmer_of_object = 1;
	}


	cout << "The most popular " << name_of_object << " is " << Search_index(index,nubmer_of_object)<< " with the number of trips " << number_of_trips << "\n";
}

//часть метода Show_popularity_output
string Travel_agency::Search_index(int &index,int &nubmer_of_object)
{
	if (nubmer_of_object == 1) //поиск города
	{
		if (index == 0)
		{
			return "Los Angeles";
		}
		else if (index == 1)
		{
			return "New York";
		}
		else if (index == 2)
		{
			return "Seattle";
		}
		else if (index == 3)
		{
			return  "Antalya";
		}
		else if (index == 4)
		{
			return  "Belek";
		}
		else if (index == 5)
		{
			return "Side";
		}
		else if (index == 6)
		{
			return "Marmaris";
		}
		else if (index == 7)
		{
			return "Sharm El Sheikh";
		}
		else if (index == 8)
		{
			return "Sahl Hasheesh";
		}
		else if (index == 9)
		{
			return  "Safaga";
		}
		else if (index == 10)
		{
			return  "Bali";
		}
		else if (index == 11)
		{
			return  "Ibiza";
		}
		else if (index == 12)
		{
			return  "Costa del Sol Read";
		}
		else if (index == 13)
		{
			return  "Costa Brava";
		}
		else
		{
			return 0;
		}
	}
	else if (nubmer_of_object == 2)//поиск стран
	{
		if (index == 0)
		{
			return "U.S.A.";
		}
		else if (index == 1)
		{
			return "Turkey";
		}
		else if (index == 2)
		{
			return "Egypt";
		}
		else if (index == 3)
		{
			return "Indonesia";
		}
		else if (index == 4)
		{
			return "Spain";
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

void Travel_agency::Show_popularity_input(string name)
{	
    if (name == "city")
    {
    	Show_popularity_output(city_​​popularity_counter, "city");
    }
    else if (name == "country")
    {
    	Show_popularity_output(countries_popularity_counter, "country");
    }
}

