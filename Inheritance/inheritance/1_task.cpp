#include "1_task.h"


Student::Student()
{
	name = "no name";
	second_name = "no second name";
	adress = "no adress";
	telephone_number = "+000000000000";
	age = 0;
}
Student::Student(string name, string second_name, string adress, string telephone_number, short age)
{
	this->name = name;
	this->second_name = second_name;
	this->adress = adress;
	this->telephone_number = telephone_number;
	this->age = age;
}
Student::~Student() {}

void Student::Student_registration()
{
	cout << "\tWelcome to university\n";
	Registration();
	cout << "Registration successful!\n";
}

void Student::Registration()
{
	cout << "Enter your name : ";
	cin >> name;
	cout << "Enter your second name : ";
	cin >> second_name;
	cout << "Enter your age : ";
	cin >> age;
	cout << "Enter your adress : ";
	std::cin.ignore(32767, '\n');
	std::getline(cin, adress);
	cout << "Enter your telephone number : ";
	cin >> telephone_number;
}

void Student::Student_information()
{
	cout << "Student name : " << name << endl;
	cout << "Student second name : " << second_name << endl;
	cout << "Student age : " << age << endl;
	cout << "Student adress : " << adress << endl;
	cout << "Student telephone number : " << telephone_number << endl;
	cout << "Press 5 to exit : ";

	int answer; //проверка на ввод
	while (true)
	{
		cin >> answer;
		if (answer == 5)
		{
			break;
		}
		else
		{
			continue;
			cout << " ";
		}
	}
}

string Student::Get_name()
{
	return name;
}
void Student::Set_name()
{
	cout << "Enter a name : ";
	cin >> name;
}

string Student::Get_second_name()
{
	return second_name;
}
void Student::Set_second_name()
{
	cout << "Enter your second name : ";
	cin >> second_name;
}

string Student::Get_adress()
{
	return adress;
}
void Student::Set_adress()
{
	cin.ignore(32767, '\n');
	cout << "Enter your adress : ";
	std::getline(cin, adress);
}

string Student::Get_telephone_number()
{
	return telephone_number;
}
void Student::Set_telephone_number()
{
	cout << "Enter your telephone number : ";
	cin >> telephone_number;
}

short Student::Get_age()
{
	return age;
}
void Student::Set_age()
{
	cout << "Enter your age : ";
	cin >> age;
}



Aspirant::Aspirant()
{
	theme_of_candidate_work = "no theme";
}
Aspirant::Aspirant(string name, string second_name, string adress, string telephone_number, short age, string theme_of_candidate_work) : Student(name ,second_name,adress,telephone_number,age) //уменьшаем копипаст через наследование
{
	this->theme_of_candidate_work = theme_of_candidate_work;
}
Aspirant::~Aspirant(){}

void Aspirant::Write_a_candidate_work()
{
	Registration();

	std::cin.ignore(32767, '\n');
	cout << "Enter the subject of the candidate work : ";
	
	std::getline(std::cin, theme_of_candidate_work);
	
	cout << "Enter the text of the candidate work : ";
	std::getline(std::cin, text_of_candidate_work);
}

void Aspirant::Show_a_candidate_work()
{
	cout <<"\t\t\t" << name << second_name << endl;
	cout << "\t\t\tStudent age : " << age << endl;
	cout << "\t\t\tStudent adress : " << adress << endl;
	cout << "\t\t\tStudent telephone number : " << telephone_number << endl;
	cout << "\t\t" << theme_of_candidate_work << endl;
	cout <<text_of_candidate_work << endl;
}
	

