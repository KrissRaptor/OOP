#include "fraction.h"

Fraction::Fraction()
{
	numerator = 0;//числитель
	denominator = 0;//знаменатель
	integer_value = 0;//цел знач
}

Fraction::Fraction(int integer_value, int numerator, int denominator)
{
	this->integer_value = integer_value;
	this->numerator = numerator;
	this->denominator = denominator;
}

Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
	integer_value = 0;
}

Fraction Fraction::operator+(Fraction& other)
{
	Fraction temp;

	if (this->denominator == other.denominator)//если знамен. равны  
	{
		temp.numerator = this->numerator + other.numerator;
		temp.denominator = this->denominator;
		temp.integer_value = this->integer_value + other.integer_value;
	}
	else if (this->denominator != other.denominator)//тут сложно
	{
		//вроде как нормально
		temp.denominator = Denominator_selection(this->denominator, other.denominator);

		Multiplier_search(this->numerator, other.numerator, this->denominator, other.denominator, temp.denominator);
		temp.numerator = this->numerator + other.numerator;

		temp.integer_value = this->integer_value + other.integer_value;
	}

	Reduction(temp.numerator, temp.denominator);

	//cout << temp.numerator << "\n--\n" << temp.denominator << std::endl;
	return temp;
}

Fraction Fraction::operator*(Fraction& other)
{
	Fraction temp;

	if (this->integer_value == 0 && other.integer_value == 0) //елси  цел.числа нету у обоих
	{
		if (this->numerator == 0 || other.numerator == 0)
		{
			throw std::exception("cannot be multiplied by zero");
		}
		if (this->denominator == 0 || other.denominator == 0)
		{
			throw std::exception("cannot be multiplied by zero");
		}

		temp.numerator = this->numerator * other.numerator;
		temp.denominator = this->denominator * other.denominator;
	}
	else if (this->integer_value > 0 && other.integer_value == 0)//если нету целоч. числа у правого
	{
		Multiplication_by_zero_check(other);
		temp.numerator = this->numerator * this->integer_value * other.numerator;
		temp.denominator = this->denominator * other.denominator;
	}
	else if (this->integer_value == 0 && other.integer_value > 0)//если нету целоч. числа у левого
	{
		Multiplication_by_zero_check(other);
		temp.numerator = this->numerator * other.numerator * other.integer_value;
		temp.denominator = this->denominator * other.denominator;
	}
	else//если есть левый и правый цел. число
	{
		Multiplication_by_zero_check(other);
		temp.numerator = this->numerator * other.numerator * this->integer_value * other.integer_value  ;
		temp.denominator = this->denominator * other.denominator;
	}

	Reduction(temp.numerator, temp.denominator);
	//cout << temp.numerator << "\n--\n" << temp.denominator << std::endl;
	return temp;
}

Fraction Fraction::operator-(Fraction& other)
{
	Fraction temp;																					 //  D1     D2
																										 //
	if (this->denominator == other.denominator)//если знамен. равны  
	{
		temp.numerator = this->numerator - other.numerator;
		temp.denominator = this->denominator;
		temp.integer_value = this->integer_value - other.integer_value;
	}
	else if (this->denominator != other.denominator)
	{
		//вроде как нормально
		temp.denominator = Denominator_selection(this->denominator, other.denominator);

		Multiplier_search(this->numerator, other.numerator, this->denominator, other.denominator, temp.denominator);
		temp.numerator = this->numerator - other.numerator;

		temp.integer_value = this->integer_value - other.integer_value;
	}
	Reduction(temp.numerator, temp.denominator);
	return temp;
}

Fraction Fraction::operator/(Fraction& other)
{
	Fraction temp;																					//  N1     N2  

																										//I1--   I2--

	if (this->integer_value == 0 && other.integer_value == 0) //елси  цел.числа нету у обоих		//  D1     D2
	{																								//
		if (this->numerator == 0 || other.numerator == 0)
		{
			throw std::exception("cannot be multiplied by zero");
		}
		if (this->denominator == 0 || other.denominator == 0)
		{
			throw std::exception("cannot be multiplied by zero");
		}

		temp.numerator = this->numerator * other.denominator;//N1 * D2								//
		temp.denominator = this->denominator * other.numerator;//D1 * N2														   //
	}
	else if (this->integer_value > 0 && other.integer_value == 0)//если нету целоч. числа у правого
	{
		Division_zero_check(other);
		temp.numerator = Convers_wrong_fraction(this->integer_value, this->numerator, this->denominator) * other.denominator;
		temp.denominator = this->denominator * other.numerator;
		temp.integer_value = this->integer_value;

	}
	else if (this->integer_value == 0 && other.integer_value > 0)//если нету целоч. числа у левого
	{
		Division_zero_check(other);
		temp.numerator = Convers_wrong_fraction(other.integer_value, other.numerator, other.denominator) * this->denominator;
		temp.denominator = this->denominator * other.numerator;
		temp.integer_value = 0;
	}
	else
	{
		Division_zero_check(other);
		temp.numerator = Convers_wrong_fraction(other.integer_value, other.numerator, other.denominator) * Convers_wrong_fraction(this->integer_value, this->numerator, this->denominator);
		temp.denominator = this->denominator * other.numerator;
		temp.integer_value = 0;
	}

	Reduction(temp.numerator, temp.denominator);
	return temp;
}

Fraction& Fraction::operator = (Fraction& other)
{
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	this->integer_value = other.integer_value;

	return *this;
}

bool Fraction::operator == (const Fraction& other)
{
	return this->denominator == other.denominator && this->numerator == other.numerator && this->integer_value && other.integer_value;
}

bool Fraction::operator != (const Fraction& other)
{
	return !(this->denominator == other.denominator && this->numerator == other.numerator && this->integer_value && other.integer_value);
}

Fraction& Fraction::operator ++ ()
{
	this->integer_value++;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction temp = *this;
	this->integer_value++;
	return temp;
}

Fraction& Fraction::operator --()
{
	this->integer_value--;
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction temp = *this;

	this->integer_value--;

	return temp;
}

bool Fraction::operator < (Fraction& other)//+
{
	if (this->denominator == other.denominator)
	{
		return this->numerator < other.numerator&& this->integer_value < other.integer_value;
	}
	else if (this->denominator != other.denominator)
	{

		int temp_denominator = 0;

		temp_denominator = Denominator_selection(other.denominator, this->denominator);

		return (this->numerator * temp_denominator) < (other.numerator * temp_denominator) && (this->integer_value < other.integer_value);
	}
}

bool Fraction::operator > (Fraction& other)//+
{
	if (this->denominator == other.denominator)
	{
		return this->numerator > other.numerator && this->integer_value > other.integer_value;

	}
	else if (this->denominator != other.denominator)
	{

		int temp_denominator = 0;

		temp_denominator = Denominator_selection(other.denominator, this->denominator);

		return (this->numerator * temp_denominator) > (other.numerator * temp_denominator) && (this->integer_value > other.integer_value);
	}
}

bool Fraction::operator <= (Fraction& other)
{
	if (this->denominator == other.denominator)
	{
		return this->numerator <= other.numerator && this->integer_value <= other.integer_value;
	}
	else if (this->denominator != other.denominator)
	{

		int temp_denominator = 0;

		temp_denominator = Denominator_selection(other.denominator, this->denominator);

		return (this->numerator * temp_denominator) <= (other.numerator * temp_denominator) && (this->integer_value <= other.integer_value);
	}
}

bool Fraction::operator >= (Fraction& other)//+
{
	if (this->denominator == other.denominator)
	{
		return this->numerator >= other.numerator && this->integer_value >= other.integer_value;
	}
	else if (this->denominator != other.denominator)
	{

		int temp_denominator = 0;

		temp_denominator = Denominator_selection(other.denominator, this->denominator);

		return (this->numerator * temp_denominator) >= (other.numerator * temp_denominator) && (this->integer_value >= other.integer_value);
	}
}

void Fraction::Reduction(int& numerator, int& denominator) //сокращение
{
	while (true)
	{
		if (numerator % 100 == 0 && denominator % 100 == 0)
		{
			numerator = numerator / 100;
			denominator = denominator / 100;
		}
		else if (numerator % 10 == 0 && denominator % 10 == 0)
		{
			numerator = numerator / 10;
			denominator = denominator / 10;
		}
		else if (numerator % 2 == 0 && denominator % 2 == 0)
		{
			numerator = numerator / 2;
			denominator = denominator / 2;
		}
		else if (numerator % 3 == 0 && denominator % 3 == 0)
		{
			numerator = numerator / 3;
			denominator = denominator / 3;
		}
		else if (numerator % 5 == 0 && denominator % 5 == 0)
		{
			numerator = numerator / 5;
			denominator = denominator / 5;
		}
		else if(denominator / numerator == denominator)
		{
			return;
		}
		else if(numerator / denominator == numerator)
		{
			return;
		}
		else if (denominator % numerator == 0)//уберечь от деления на 1
		{
			if (denominator / numerator != denominator)
			{	
			    numerator = numerator / numerator;
				denominator = denominator / numerator;
			}
		}
		else if (numerator % denominator == 0)//уберечь от деления на 1
		{
			if (numerator / denominator != numerator)
			{
			    numerator = numerator / denominator;
				denominator = denominator / denominator;
			}
		}
		else
		{
			return;
		}
	}
}

int Fraction::Denominator_selection(int& denominator1, int& denominator2) // подборка ближайшего знаменателя
{
	int number1 = 1;
	int number2 = 1;
	int number3 = 0;

	while (true)
	{
		if (number1 % denominator1 != 0)
		{
			number1++;
		}
		if (number2 % denominator2 != 0)
		{
			number2++;
		}

		number3 = number1 * number2;
		if (number3 % denominator1 == 0)
		{
			if (number2 % denominator2 == 0)
			{
				break;
			}
		}

	}
	return number3;
}

int Fraction::Convers_wrong_fraction(int& integer_value, int& numerator, int& denominator)//преобразовует из целого числа и дроби в неправ. дробь
{
	int temp_numerator = 0;
	temp_numerator = (integer_value * denominator + numerator);                  // (I1 * D1 + N1)						                                //  ------------------
	return temp_numerator;
}

void Fraction::Multiplier_search(int& numerator1, int& numerator2, int& denominator1, int& denominator2, int& denominator_tmp)
{
	int denominator_multiplier1 = 0;
	int denominator_multiplier2 = 0;

	denominator_multiplier1 = denominator_tmp / denominator1;
	denominator_multiplier2 = denominator_tmp / denominator2;

	numerator1 *= denominator_multiplier1;
	numerator2 *= denominator_multiplier2;
}

void Fraction::Multiplication_by_zero_check(Fraction &other)
{
	if (this->integer_value == 0 && other.integer_value == 0)
	{
		throw std::exception("cannot be multiplied by zero");
	}
	if (this->numerator == 0 || other.numerator == 0)
	{
		throw std::exception("cannot be multiplied by zero");
	}
	if (this->denominator == 0 || other.denominator == 0)
	{
		throw std::exception("cannot be multiplied by zero");
	}
}

void Fraction::Division_zero_check(Fraction& other)
{
	if (this->integer_value == 0 && other.integer_value == 0)
	{
		throw std::exception("cannot be divided by zero");
	}
	if (this->numerator == 0 || other.numerator == 0)
	{
		throw std::exception("cannot be divided by zero");
	}
	if (this->denominator == 0 || other.denominator == 0)
	{
		throw std::exception("cannot be divided by zero");
	}
}

void Fraction::Draw()
{
	cout << "   " << numerator << "\n";
	cout << integer_value << " ---" << "\n";
	cout << "   " << denominator << "\n";
}

std::ostream& operator<<(std::ostream& out, const Fraction& other)
{
	out << "   " << other.numerator << "\n";
	out << other.integer_value << " ---" << "\n";
	out << "   " << other.denominator << "\n";
	return out;
}
