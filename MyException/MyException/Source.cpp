#include <iostream>
#include <string.h>

using namespace std;

class MyException : public std::exception  //������
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
	int data_state;//����� ������ ,���� ���������� 
	//� ����� ����� ����� � ������������ ������������� ������ 
};


void Foo(int value)
{
	if (value < 0)
	{
		throw MyException("������ ����", value);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian"); // ������� �� ������� 

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