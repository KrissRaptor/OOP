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
	//перепроверить все 4
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
	int numerator;//числитель
	int denominator;//знаменатель
	int integer_value;//цел знач

	void Reduction(int& numerator, int& denominator); //сокращение

	int Denominator_selection(int& denominator1, int& denominator2); // подборка ближайшего знаменател€

	int Convers_wrong_fraction(int& integer_value, int& numerator, int& denominator);//преобразовует из целого числа и дроби в неправ. дробь

	void Multiplier_search(int& numerator1, int& numerator2, int& denominator1, int& denominator2, int& denominator_tmp);//нужен дл€ метода +- ,чтоб домуножиь знаменатель  

	void Multiplication_by_zero_check(Fraction& other);

	void Division_zero_check(Fraction& other);


};


