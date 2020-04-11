#include <iostream>
#include <string.h>

using namespace std;

class MyException : public std::exception  //пример
{
public:
	MyException(const char* str, int data_state) : exception(str)
	{
		this->data_state = data_state;
	}
	int Get_data_state()
	{
		return data_state;
	};

private:
	int data_state;//номер ошибки ,чтоб выкидывать 
	//и далее можно будет в документации задекларивать ошибки 
};


void Foo(int value)
{
	if (value < 0)
	{
		throw MyException("меньше нуля", value);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian"); // перевод на русский 

	try
	{
		Foo(-3234);
	}
	catch (MyException& ex)
	{
		cout << ex.what() << endl;
		cout << ex.Get_data_state() << endl;
	}
}