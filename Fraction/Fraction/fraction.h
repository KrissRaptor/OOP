#pragma once

#include <iostream>

using std::cout;
using std::cin;


class Fraction
{
public:
	Fraction();

	Fraction(int integer_value, int numerator, int denominator);

	Fraction(int numerator, int denominator);

	~Fraction() {}
	//������������� ��� 4
	Fraction operator + (Fraction& other);

	Fraction operator * (Fraction& other);

	Fraction operator - (Fraction& other);                                                

	Fraction operator / (Fraction& other);

	Fraction& operator = (Fraction& other);

	bool operator == (const Fraction& other);

	bool operator != (const Fraction& other);

	Fraction& operator ++ ();
	
	Fraction operator++(int);

	Fraction& operator --();

	Fraction operator--(int);

	bool operator < (Fraction& other);

	bool operator > (Fraction& other);

	bool operator <= (Fraction& other);

	bool operator >= (Fraction& other);

	friend std::ostream& operator<< (std::ostream& out, const Fraction& point);

	void Draw();

private:
	int numerator;//���������
	int denominator;//�����������
	int integer_value;//��� ����

	void Reduction(int& numerator, int& denominator); //����������

	int Denominator_selection(int& denominator1, int& denominator2); // �������� ���������� �����������

	int Convers_wrong_fraction(int& integer_value, int& numerator, int& denominator);//������������� �� ������ ����� � ����� � ������. �����

	void Multiplier_search(int& numerator1, int& numerator2, int& denominator1, int& denominator2, int& denominator_tmp);//����� ��� ������ +- ,���� ��������� �����������  

	void Multiplication_by_zero_check(Fraction& other);

	void Division_zero_check(Fraction& other);


};


