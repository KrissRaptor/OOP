#include <iostream>
#include <string.h>

class MyException : public std::exception  //ïðèìåð
{
public:
	MyException(const char* str, int data_state) : std::exception(str)
	{
		this->data_state = data_state;
	}
	int Get_data_state()
	{
		return data_state;
	};

private:
	int data_state;//íîìåð îøèáêè ,÷òîá âûêèäûâàòü 
	//è äàëåå ìîæíî áóäåò â äîêóìåíòàöèè çàäåêëàðèâàòü îøèáêè 
};


void Foo(int value)
{
	if (value < 0)
	{
		throw MyException("ìåíüøå íóëÿ", value);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian"); // ïåðåâîä íà ðóññêèé 

	try
	{
		Foo(-3234);
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << std::endl;
		std::cout << ex.Get_data_state() << std::endl;
	}
}
