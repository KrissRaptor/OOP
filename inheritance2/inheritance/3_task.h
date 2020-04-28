#pragma once

#include"stdinlucde.h"
#include"vector" //для работы с vector
#include <windows.h> // для SetCursorPos
#include<math.h> // для sqrt() ,pow()

#define P 3.1415 //число P

//готов
class Figure abstract 
{
public:

	Figure();

	virtual ~Figure();

	virtual void Draw() = 0;

	virtual void Radius_calculation() = 0;

	virtual void Area_calculation() = 0;

	virtual void Perimeter_calculation();

protected:

	std::vector<double>number_of_parties; //кол. сторон

	double radius;
	double area;
	double perimeter;
};

//готов     работает
class Point : public Figure // точка
{
public:

	Point();

	Point(short coordX, short coordY);

	void Draw() override;

	void Set_coords(short coordX, short coordY);

	short Get_coordX();

	short Get_coordY();;

private:
	short coordX;
	short coordY;

	void Set_cursor();// для отрисовки точки

	void Radius_calculation() override;//так как у фигуры нету формул,но нужно переопределить методы,чтоб создать обьект класса

	void Area_calculation() override;

	void Perimeter_calculation() override;
};  

//готов   работает
class Straight :public Figure//прямая
{
public:

	Straight();

	Straight(double lenght);

	void Draw() override;

	void Set_lenght(double lenght);

	double Get_lenght();

private:
	double lenght;

	void Radius_calculation() override;//так как у фигуры нету формул,но нужно переопределить методы,чтоб создать обьект класса

	void Area_calculation() override;

	void Perimeter_calculation() override;
};

namespace My_ellipse //чтоб не было конфликта с методом Ellipse из <windows.h>
{
	//готов  
	class Ellipse :public Figure // элипс
	{
	public:

		Ellipse();

		Ellipse(double semimajor_axis_a, double minor_axis_b);

		virtual ~Ellipse();

		virtual void Draw();

		virtual void Radius_calculation();

		virtual void Area_calculation();

		virtual void Perimeter_calculation();

	private:
		double semimajor_axis_a; //большая полуось
		double minor_axis_b;//малая полуось
	};
}

//не нашёл формулы работает
class Polygon :public Figure //Многоугольник.
{
public:

	Polygon();

	virtual ~Polygon();

	virtual void Draw() ;

	virtual void Radius_calculation() ;

	virtual void Area_calculation() ;

private :
	
};

//готов   работает
class Circle :public My_ellipse::Ellipse//Окружность
{
public:

	Circle();

	Circle(double circumference);

	void Draw() override;

	void Radius_calculation() override;

	void Area_calculation() override;

	void Perimeter_calculation() override;

	void Set_circumference(double circumference);

private :
	double circumference; //длина окружности
};

//готов   работает
class Triangle :public Polygon// Треугольник
{
public:
	Triangle();

	Triangle(double a, double b, double c);

	virtual ~Triangle();

	virtual void Draw();

	virtual void Radius_calculation();

	virtual void Area_calculation();
};

//почти всё есть кроме радиуса  // работает
class Quadrangle :public Polygon//Четырехугольник
{
public:

	Quadrangle();

	Quadrangle(double a, double b, double c, double d);

	virtual ~Quadrangle();

	virtual void Draw();

	virtual void Radius_calculation();

	virtual void Area_calculation();

};

/////////////////////////////////////////////////////////////////////////////////////////////////

//готов    работает
class Acute_triangle : public  Triangle   //ОбычныйОстроугольныйТреугольник 
{
public:

	Acute_triangle();
	
	Acute_triangle(double a, double b, double c);
	
	void Draw() override;
	//можно взять все методы из обычного треугольника,переопределять не надо
};

//готов   работает
class Isosceles_аngular_triangle : public  Triangle  //РавнобедренныйОстроугольныйТреугольник 
{
public:
	
	Isosceles_аngular_triangle();

	Isosceles_аngular_triangle(double a, double b);

	void Draw() override;

    //можно взять те же методы с треугольника ,так как считать будет также
};
 
//готов    работает
class Equilateral_angular_triangle : public  Triangle  //РавностороннийОстроугольныйТреугольник 
{
public:
	
	Equilateral_angular_triangle();

	Equilateral_angular_triangle(double a);// так как одна сторона
	
	void Draw() override;
	//можно взять те же методы с треугольника ,так как считать будет также
};

//готов     работает
class Dumb_triangle : public  Triangle  //Тупой треугольник
{
public:

	Dumb_triangle();

	Dumb_triangle(double a, double b, double c);

	void Draw() override;

	//можно взять те же методы с треугольника ,так как считать будет также
};

//готов      //работает
class Sosceles_obtuse_triangle : public  Triangle //РавнобедренныйТупоугольныйТреугольник
{
public:

	Sosceles_obtuse_triangle();

	Sosceles_obtuse_triangle(double a, double b);

	void Draw() override;

	//можно взять те же методы с треугольника ,так как считать будет также
};             

//готов        работает
class Right_triangle : public  Triangle     //ОбычныйПрямоугольныйТреугольник
{
public:

	Right_triangle();

	Right_triangle(double cathet_a, double cathet_b, double hypotenuse);

	void Draw() override;

	void Radius_calculation() override;

	void Area_calculation() override;
};

//почти всё есть кроме радиуса       //работает
class Isosceles_rectangular_triangle : public  Triangle   //Равнобедренный прямоугольный треугольник
{
public:

	Isosceles_rectangular_triangle();

	Isosceles_rectangular_triangle(double cathet_a , double hypotenuse);

	void Draw() override;


	//радиус не смог найти,поэтому будет от треугольника

	void Area_calculation() override;

};

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//готов                  //работает
class Parallelogram : public Quadrangle //Параллелограмм
{
public:

	Parallelogram();

	Parallelogram(double a, double b, double c, double d);

	Parallelogram(double a, double b, double c, double d, double parallelogram_height);

	void Set_parallelogram_height(double parallelogram_height);

	void Set_angle(double angle);

	void Draw() override;

	void Radius_calculation() override;

	void Area_calculation() override;

	void Height_calculation();

private:
	double parallelogram_height;
	double angle;
};

//готов           //работает
class Trapezoid : public Quadrangle //Трапеция
{
public:

	Trapezoid();

	Trapezoid(double a, double b, double c, double d);

	Trapezoid(double a, double b, double trapezoid_height);

	void Draw() override;

	void Radius_calculation() override;

	void Area_calculation() override;

	void Trapezoid_height_calculation();

	double Get_trapezoid_height();

	void Set_trapezoid_height();

private:
	double trapezoid_height;//высота трапеции
};

//готов           //работает
class Deltoid : public Quadrangle //Дельтоид
{ 
public:

	Deltoid();

	Deltoid(double a, double b);

	Deltoid(double a, double b, double angle);

	void Draw() override;

	void Radius_calculation() override;

	void Area_calculation() override;

	void Set_angle(double angle);

private:
double angle;
};

namespace My_rectangle//чтоб не было конфликта с методом Rectangle из <windows.h>
{
	//готов 
	class Rectangle : public Quadrangle //Прямоугольник
	{
	public:

		Rectangle();

		Rectangle(double a, double b);

		void Draw() override;

		void Radius_calculation() override;

		void Area_calculation() override;

	};
}

//готов
class Rhombus : public Quadrangle // Ромб
{
public:

	Rhombus();
	
	Rhombus(double side);

	Rhombus(double side, double angle);

	void Set_angle(double angle);
	
	void Draw() override;

	void Radius_calculation() override;

	void Area_calculation() override;

protected :
	double angle;
};

//готов        //работает
class Square : public My_rectangle::Rectangle// квадрат
{
public:

	Square();

	Square(double a);

	void Draw() override;

	void Radius_calculation() override;

	void Area_calculation() override;
};




