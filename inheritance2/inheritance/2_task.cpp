#include"2_task.h"

Passport::Passport()
{
	name = "no name";
	second_name = "no second name";
	//adress = "no adress";
	age = 0;


	day_of_birth = 0;
	month_of_birth = 0;
	year_of_birth = 0;
	passport_ID = 100000000 + rand() % 999999999; // 9 чисел

	city = "no city";
	region = "no region";
}

Passport::~Passport(){}

void Passport::Fill_in_passport()
{
	cout << "\n\tWelcome to the passport office!";
	cout << "\nFill in the following lines to get a passport";

	Fill();
	std::cin.ignore(32767, '\n');

	cout << "Enter your region : ";
	std::getline(cin, region);

	cout << "Enter your city : ";
	std::getline(cin, city);

	cout << "\nRegistration successful!\n";
}

void Passport::Fill()
{
	cout << "\nEnter your name : ";
	cin >> name;
	cout << "Enter your second name : ";
	cin >> second_name;
	cout << "Enter your patronymic : ";
	cin >> patronymic;

	cout << "Enter your age : ";
	cin >> age;

	cout << "Enter your date of birth : ";
	cin >> day_of_birth;

	cout << "Enter your month of birth : ";
	cin >> month_of_birth;

	cout << "Enter your year of birth : ";
	cin >> year_of_birth;
	std::cin.ignore(32767, '\n');

	cout << "Enter your gender : ";
	std::getline(cin, gender);
	
	cout << "Enter your citizenship : ";
	cin >> сitizenship;

}

void Passport::Show_passport()
{
	Show();
	cout <<"Region : "<< region << " City : " << city << endl;
	cout << "Passport ID : " << passport_ID << endl;
}

void Passport::Show()
{
	cout << name << " " << second_name << " " << patronymic << endl;
	cout << "Age : " << age << endl;
	cout << day_of_birth << "/" << month_of_birth << "/" << year_of_birth << endl;
	cout << "Gender : " << gender << endl;
	cout << "Citizenship : " << сitizenship << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Foreign_passport::Foreign_passport() :Passport()
{
	presence_of_a_foreigner = false;
}
void Foreign_passport::Fill_in_foreign_passport()
{
	if (presence_of_a_foreigner == false) //проверка на наличие загран.паспорта
	{
		cout << "\t\tForeign passport registration";
		Fill();
		presence_of_a_foreigner = true;
	}
	else 
	{
		cout << "Error,you already have foreign passport";
	}
}

void Foreign_passport::Show_foreign_passport()
{
	if (presence_of_a_foreigner == true) //проверка на наличие загран.паспорта
	{
		Show();
		cout << "\t\tVISA" << endl;
		visa.Show_Visa_information();
	}
	else
	{
		cout << "Error,you don't have foreign passport";
	}
}

void Foreign_passport::Change_country_of_Visa()
{
	visa.Set_country_of_visa();
}

void Foreign_passport::Fill_Visa()
{
	visa.Fill_out_of_visa();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Foreign_passport::Visa::Visa() :Passport()
{
	type_of_visa = "usual";
	country_of_visa = "No country";
	visa_ID = 100000000 + rand() % 999999999;
	Visa_availability = false;
}

void Foreign_passport::Visa::Show_Visa_information()
{
	if (Visa_availability == true)
	{
		Show();
		cout << "Type of visa : " << type_of_visa << endl;
		cout << "Country of visa : " << country_of_visa << endl;
	}
	else
	{
		cout << "You do not have active Visas!" << endl;
	}
}

void Foreign_passport::Visa::Fill_out_of_visa()
{
	if (Visa_availability != true)
	{
		cout << "\t\tVisa registration\n";
		Fill();
		cout << "Enter type of visa : 1-diplomatic,2-service,3-usual,4-transit,5-temporary resident visa : ";

		while (true)
		{

			int answer;
			cin >> answer;

			if (answer == 1)
			{
				type_of_visa = " diplomatic";
			}
			else if (answer == 2)
			{
				type_of_visa = " service";
			}
			else if (answer == 3)
			{
				type_of_visa = "usual";
			}
			else if (answer == 4)
			{
				type_of_visa = "transit";
			}
			else if (answer == 5)
			{
				type_of_visa = "temporary resident";
			}
			else
			{
				cout << "Error ,please press another key ";
			}
		}
		std::cin.ignore(32767, '\n');
		cout << "Enter country of visa : ";
		std::getline(cin, country_of_visa);

		Visa_availability = true;
	}
	else
	{
		cout << "You do not have active Visas!" << endl;
	}

}

void Foreign_passport::Visa::Set_country_of_visa()
{

	std::cin.ignore(32767, '\n');

	cout << "Enter the country to which you want to apply for a visa?";
	std::getline(cin, country_of_visa);
}
//
//string Foreign_passport::Visa::Get_country_of_visa()
//{
//	return country_of_visa;
//}