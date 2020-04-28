#pragma once

#include"stdinlucde.h"
#include"vector" //��� ������ � vector
#include <windows.h> // ��� SetCursorPos
#include<math.h> // ��� sqrt() ,pow()

#define P 3.1415 //����� P

//�����
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

	std::vector<double>number_of_parties; //���. ������

	double radius;
	double area;
	double perimeter;
};

//�����     ��������
class Point : public Figure // �����
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

	void Set_cursor();// ��� ��������� �����

	void Radius_calculation() override;//��� ��� � ������ ���� ������,�� ����� �������������� ������,���� ������� ������ ������

	void Area_calculation() override;

	void Perimeter_calculation() override;
};  

//�����   ��������
class Straight :public Figure//������
{
public:

	Straight();

	Straight(double lenght);

	void Draw() override;

	void Set_lenght(double lenght);

	double Get_lenght();

private:
	double lenght;

	void Radius_calculation() override;//��� ��� � ������ ���� ������,�� ����� �������������� ������,���� ������� ������ ������

	void Area_calculation() override;

	void Perimeter_calculation() override;
};

namespace My_ellipse //���� �� ���� ��������� � ������� Ellipse �� <windows.h>
{
	//�����  
	class Ellipse :public Figure // �����
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
		double semimajor_axis_a; //������� �������
		double minor_axis_b;//����� �������
	};
}

//�� ����� ������� ��������
class Polygon :public Figure //�������������.
{
public:

	Polygon();

	virtual ~Polygon();

	virtual void Draw() ;

	virtual void Radius_calculation() ;

	virtual void Area_calculation() ;

private :
	
};

//�����   ��������
class Circle :public My_ellipse::Ellipse//����������
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
	double circumference; //����� ����������
};

//�����   ��������
class Triangle :public Polygon// �����������
{
public:
	Triangle();

	Triangle(double a, double b, double c);

	virtual ~Triangle();

	virtual void Draw();

	virtual void Radius_calculation();

	virtual void Area_calculation();
};

//����� �� ���� ����� �������  // ��������
class Quadrangle :public Polygon//���������������
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

//�����    ��������
class Acute_triangle : public  Triangle   //������������������������������� 
{
public:

	Acute_triangle();
	
	Acute_triangle(double a, double b, double c);
	
	void Draw() override;
	//����� ����� ��� ������ �� �������� ������������,�������������� �� ����
};

//�����   ��������
class Isosceles_�ngular_triangle : public  Triangle  //�������������������������������������� 
{
public:
	
	Isosceles_�ngular_triangle();

	Isosceles_�ngular_triangle(double a, double b);

	void Draw() override;

    //����� ����� �� �� ������ � ������������ ,��� ��� ������� ����� �����
};
 
//�����    ��������
class Equilateral_angular_triangle : public  Triangle  //�������������������������������������� 
{
public:
	
	Equilateral_angular_triangle();

	Equilateral_angular_triangle(double a);// ��� ��� ���� �������
	
	void Draw() override;
	//����� ����� �� �� ������ � ������������ ,��� ��� ������� ����� �����
};

//�����     ��������
class Dumb_triangle : public  Triangle  //����� �����������
{
public:

	Dumb_triangle();

	Dumb_triangle(double a, double b, double c);

	void Draw() override;

	//����� ����� �� �� ������ � ������������ ,��� ��� ������� ����� �����
};

//�����      //��������
class Sosceles_obtuse_triangle : public  Triangle //�������������������������������������
{
public:

	Sosceles_obtuse_triangle();

	Sosceles_obtuse_triangle(double a, double b);

	void Draw() override;

	//����� ����� �� �� ������ � ������������ ,��� ��� ������� ����� �����
};             

//�����        ��������
class Right_triangle : public  Triangle     //�������������������������������
{
public:

	Right_triangle();

	Right_triangle(double cathet_a, double cathet_b, double hypotenuse);

	void Draw() override;

	void Radius_calculation() override;

	void Area_calculation() override;
};

//����� �� ���� ����� �������       //��������
class Isosceles_rectangular_triangle : public  Triangle   //�������������� ������������� �����������
{
public:

	Isosceles_rectangular_triangle();

	Isosceles_rectangular_triangle(double cathet_a , double hypotenuse);

	void Draw() override;


	//������ �� ���� �����,������� ����� �� ������������

	void Area_calculation() override;

};

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//�����                  //��������
class Parallelogram : public Quadrangle //��������������
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

//�����           //��������
class Trapezoid : public Quadrangle //��������
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
	double trapezoid_height;//������ ��������
};

//�����           //��������
class Deltoid : public Quadrangle //��������
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

namespace My_rectangle//���� �� ���� ��������� � ������� Rectangle �� <windows.h>
{
	//����� 
	class Rectangle : public Quadrangle //�������������
	{
	public:

		Rectangle();

		Rectangle(double a, double b);

		void Draw() override;

		void Radius_calculation() override;

		void Area_calculation() override;

	};
}

//�����
class Rhombus : public Quadrangle // ����
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

//�����        //��������
class Square : public My_rectangle::Rectangle// �������
{
public:

	Square();

	Square(double a);

	void Draw() override;

	void Radius_calculation() override;

	void Area_calculation() override;
};




