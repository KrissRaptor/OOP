#include"3_task.h"

Figure::Figure()
{
	radius = 0;
	area = 0;
	perimeter = 0;
}

Figure::~Figure()
{}

void Figure::Perimeter_calculation() //универсальный расчёт периметра
{
	for (int i = 0; i < number_of_parties.size(); i++)
	{
		perimeter += number_of_parties.at(i);
	}
	cout << "Perimeter = " << perimeter << endl;
}




Point::Point()
{
	coordX = 0;
	coordY = 0;
}

Point::Point(short coordX, short coordY)
{
	this->coordX = coordX;
	this->coordY = coordX;
}

void Point :: Draw()
{
	Set_cursor();
}

void Point::Set_coords(short coordX, short coordY)
{
	this->coordX = coordX;
	this->coordY = coordY;
}

short Point::Get_coordX()
{
	return coordX;
}

short Point::Get_coordY()
{
	return coordY;
}

void Point::Set_cursor() // для отрисовки точки
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position{ coordX ,coordY }; //позиция x и y
	CONSOLE_CURSOR_INFO cci; // для удаления курсора в консоли
	GetConsoleCursorInfo(hConsole, &cci); //Извлекает информацию о размере и видимости курсора
	cci.bVisible = FALSE;// для удаления курсора в консоли
	SetConsoleCursorInfo(hConsole, &cci); //Задает размер и видимость курсора

	SetConsoleCursorPosition(hConsole, position);
	//SetConsoleTextAttribute(hConsole, 14);
	cout << "*" << endl << endl << endl << endl;
}

void Point::Radius_calculation()
{}

void Point::Area_calculation()
{}

void Point::Perimeter_calculation()
{}




My_ellipse::Ellipse::Ellipse() :Figure()
{
		semimajor_axis_a = 0;
		minor_axis_b = 0;
}

My_ellipse::Ellipse::Ellipse(double semimajor_axis_a, double minor_axis_b)
{
	this->semimajor_axis_a = semimajor_axis_a;
	this->minor_axis_b = minor_axis_b;
}

My_ellipse::Ellipse::~Ellipse()
{}

void My_ellipse::Ellipse::Draw()
{
	cout << "Ellipse " << endl;
}

void My_ellipse::Ellipse::Radius_calculation()
{
	radius = (semimajor_axis_a * semimajor_axis_a) + (minor_axis_b * minor_axis_b);
	radius = std::sqrt(radius);
	cout << "Radious = " << radius << endl;
}

void My_ellipse::Ellipse::Area_calculation()
{
	area = P * semimajor_axis_a * minor_axis_b;
	cout << "Area = " << radius << endl;
}

void My_ellipse::Ellipse::Perimeter_calculation()
{
	perimeter = 4 * (P * semimajor_axis_a * minor_axis_b + (semimajor_axis_a - minor_axis_b)) / (semimajor_axis_a + minor_axis_b);
	cout << "Perimetr = ";
}




Polygon::Polygon()
{}

Polygon::~Polygon()
{}

void Polygon::Draw()
{
	cout << "Polygon " << endl;
}

void Polygon::Radius_calculation()
{
	//не нешёл
}

void Polygon::Area_calculation()
{
	cout << "Area = " << area << endl;
}




Circle::Circle()
{
	circumference = 0;
}

Circle::Circle(double circumference)
{
	this->circumference = circumference;
}

void Circle::Draw()
{
	cout << "Circle " << endl;
}

void Circle::Radius_calculation()
{
	radius = circumference / (P * 2);
	cout << "Radius = "<< radius << endl;
}

void Circle::Area_calculation()
{
	area = P * radius * radius; // чтоб узнать площадь сначала узнать радиус нужно
	cout << "Area = " << area << endl;
}

void Circle::Perimeter_calculation()
{
	perimeter = 2 * P * radius;// чтоб узнать периметр сначала узнать радиус нужно
	cout << "Perimeter = " << perimeter << endl;
}

void Circle::Set_circumference(double circumference)
{
	this->circumference = circumference;
}





Triangle::Triangle(){}

Triangle::Triangle(double a, double b, double c)
{
	number_of_parties.push_back(a);
	number_of_parties.push_back(b);
	number_of_parties.push_back(c);
}

Triangle::~Triangle()
{}

void Triangle::Draw()
{
	cout << "Triangle " << endl;
}

void Triangle::Radius_calculation()//РАДИУС ОПИСАННОЙ ОКРУЖНОСТИ ТРЕУГОЛЬНИКА, ЗНАЯ СТОРОНЫ  //Нужен сначала периметр
{
	double half_perimeter = 0;//надо найти полупериметр сначала
	double denominator = 0; //так как по формуле нужен корень из числа ,поэтому костылём считаем корень из числа
	
	half_perimeter = 0.5 * (number_of_parties.at(0) + number_of_parties.at(1) + number_of_parties.at(2));//
	denominator = (half_perimeter * (half_perimeter - number_of_parties.at(0)) * (half_perimeter - number_of_parties.at(1)) * (half_perimeter - number_of_parties.at(2)));
	denominator = sqrt(denominator);
	radius = ((number_of_parties.at(0) * number_of_parties.at(1) * number_of_parties.at(2)) / (4 * denominator));
	cout << "Radious = " << radius << endl;
}

void Triangle::Area_calculation() //чтоб посчитать нужно найти радиус
{
	area = (number_of_parties.at(0) * number_of_parties.at(1) * number_of_parties.at(2)) / (4 * radius);
	cout << "Area = " << area << endl;
}




Quadrangle::Quadrangle()
{}

Quadrangle::Quadrangle(double a, double b, double c, double d)
{
	number_of_parties.push_back(a);
	number_of_parties.push_back(b);
	number_of_parties.push_back(c);
	number_of_parties.push_back(d);
}

Quadrangle::~Quadrangle()
{}

void Quadrangle::Draw()
{
	cout << "Quadrangle " << endl;
}

void Quadrangle::Radius_calculation() //хз не нашёл формулу
{
	cout << "Radious = " << radius << endl;
}

void Quadrangle::Area_calculation()
{
	//нужен для формулы площади
	
	double half_perimeter = (number_of_parties.at(0) + number_of_parties.at(1) + number_of_parties.at(2) + number_of_parties.at(3)) / 2;

	area = (half_perimeter - number_of_parties.at(0)) * (half_perimeter - number_of_parties.at(1)) * (half_perimeter - number_of_parties.at(2)) * (half_perimeter - number_of_parties.at(3));
	area = sqrt(area);
	cout << "Area = " << area << endl;
}





Acute_triangle::Acute_triangle()
{}

Acute_triangle::Acute_triangle(double a, double b, double c) :Triangle(a,b,c)
{}


void Acute_triangle::Draw()
{
	cout << "Acute triangle " << endl;
}





Isosceles_аngular_triangle::Isosceles_аngular_triangle()
{}

Isosceles_аngular_triangle::Isosceles_аngular_triangle(double a, double b) :Triangle(a, a, b)
{}// так как у  равнобедренного 2-стороны одинаковые

void Isosceles_аngular_triangle::Draw()
{
	cout << "Isosceles аngular triangle " << endl;
}




Equilateral_angular_triangle::Equilateral_angular_triangle()
{}

Equilateral_angular_triangle::Equilateral_angular_triangle(double a) :Triangle(a, a, a)
{}//так как стороны одинаковые

void Equilateral_angular_triangle::Draw()
{
	cout << "Equilateral angular triangle " << endl;
}




Dumb_triangle::Dumb_triangle()
{}

Dumb_triangle::Dumb_triangle(double a, double b, double c) :Triangle(a, b, c)
{}

void Dumb_triangle::Draw()
{
	cout << "Dumb triangle " << endl;
}




Sosceles_obtuse_triangle::Sosceles_obtuse_triangle()
{}

Sosceles_obtuse_triangle::Sosceles_obtuse_triangle(double a, double b) : Triangle(a, a, b)
{}

void Sosceles_obtuse_triangle::Draw()
{
	cout << "Sosceles obtuse triangle " << endl;
}




Right_triangle::Right_triangle()
{}

Right_triangle::Right_triangle(double cathet_a, double cathet_b, double hypotenuse) : Triangle(cathet_a, cathet_b, hypotenuse)
{}

void Right_triangle::Draw()
{
	cout << "Right triangle " << endl;
}

void Right_triangle::Radius_calculation()
{
	radius = 0.5 * ((number_of_parties.at(0) * number_of_parties.at(0)) + (number_of_parties.at(1) * number_of_parties.at(1)));// a^2  + b^2
	radius = sqrt(radius);

	cout << "Radious = " << radius << endl;
}

void Right_triangle::Area_calculation()
{
	area = (0.5 * number_of_parties.at(0) * number_of_parties.at(1)); //так как катет 1 * катет 2 	
	cout << "Area = " << area << endl;
}




Isosceles_rectangular_triangle::Isosceles_rectangular_triangle()
{}

Isosceles_rectangular_triangle::Isosceles_rectangular_triangle(double cathet_a, double hypotenuse) : Triangle(cathet_a, cathet_a, hypotenuse)
{}

void Isosceles_rectangular_triangle::Draw()
{
	cout << "Isosceles_rectangular_triangle " << endl;
}

void Isosceles_rectangular_triangle::Area_calculation()
{
	double half_perimeter = (number_of_parties.at(0) + number_of_parties.at(1) + number_of_parties.at(2)) / 2;
	area = ((half_perimeter * ((half_perimeter - number_of_parties.at(0)) * (half_perimeter - number_of_parties.at(0)))) * (half_perimeter - (number_of_parties.at(0) * 1.414))); //√( p(p-a)^2 * (p-a√2) )
	area = sqrt(area);

	cout << "Area = " << area << endl;
}




Parallelogram::Parallelogram()
{
	angle = 0;
	parallelogram_height = 0;
}

Parallelogram::Parallelogram(double a, double b, double c, double d) : Quadrangle(a, b, c, d)
{
	angle = 0;
	parallelogram_height = 0;
}

Parallelogram::Parallelogram(double a, double b, double c, double d, double parallelogram_height) : Quadrangle(a, b, c, d)
{
	this->parallelogram_height = parallelogram_height;
	angle = 0;
}

void Parallelogram::Set_parallelogram_height(double parallelogram_height)
{
	this->parallelogram_height = parallelogram_height;
}

void Parallelogram::Set_angle(double angle)
{
	this->angle = angle;
}

void Parallelogram::Draw()
{
	cout << "Parallelogram " << endl;
}

void Parallelogram::Radius_calculation() //сначала посчитать периметр
{
	double half_perimetr = perimeter /2;
	radius = area / half_perimetr;
	cout << "Radious = " << radius << endl;
}

void Parallelogram::Area_calculation() //сначала просчитать высоту
{
	area = (number_of_parties.at(0) * parallelogram_height);
	cout << "Area = " << area << endl;
}

void Parallelogram::Height_calculation() // сначала задать угол
{
	parallelogram_height = (number_of_parties.at(1) * sin(angle));
}



 
Trapezoid::Trapezoid()
{
	trapezoid_height = 0;
}

Trapezoid::Trapezoid(double a, double b, double c, double d) : Quadrangle(a, b, c, d)
{
	this->trapezoid_height = 0;
}

Trapezoid::Trapezoid(double a, double b, double trapezoid_height) : Quadrangle(a, b, a, b)
{
	this->trapezoid_height = trapezoid_height;
}

void Trapezoid::Draw()
{
	cout << "Trapezoid " << endl;
}

void Trapezoid::Radius_calculation()
{
	
	cout << "Radious = " << radius << endl;
}

void Trapezoid::Area_calculation()
{
	area = 0.5 * ((number_of_parties.at(0) + number_of_parties.at(1)) / 2 ) * trapezoid_height;
	cout << "Area = " << area << endl;
}

void Trapezoid::Trapezoid_height_calculation()
{
	trapezoid_height = pow(number_of_parties.at(0), 2) - ((pow(number_of_parties.at(3) - number_of_parties.at(1), 2) + pow(number_of_parties.at(0), 2) - pow(number_of_parties.at(2), 2)) / (2 * (number_of_parties.at(3) - number_of_parties.at(1))));
	cout << "Trapezoid height = " << trapezoid_height << endl;;
}

double Trapezoid::Get_trapezoid_height()
{
	return trapezoid_height;
}

void Trapezoid::Set_trapezoid_height()
{
	std::cin >> trapezoid_height;
}




Square::Square()
{}

Square::Square(double a) : Rectangle(a,a)
{}

void Square::Draw()
{
	cout << "Square " << endl;
}

void Square::Radius_calculation()
{
	radius = sqrt((pow(number_of_parties.at(0), 2) + pow(number_of_parties.at(0) ,2)));
	cout << "Radious = " << radius << endl;
}

void Square::Area_calculation()
{
	area = pow(number_of_parties.at(0), 2);
	cout << "Area = " << area << endl;
}




Rhombus::Rhombus()
{
	angle = 0;
}

Rhombus::Rhombus(double side) : Quadrangle(side, side, side, side)
{
	angle = 0;
}

Rhombus::Rhombus(double side, double angle)
{
	number_of_parties.push_back(side);
	this->angle = angle;
}

void Rhombus::Set_angle(double angle)
{
	this->angle = angle;
}

void Rhombus::Draw()
{
	cout << "Rhombus " << endl;
}

void Rhombus::Radius_calculation() //нужно указать угол
{
	radius = (number_of_parties.at(0) * sin(angle) / 2);
	cout << "Radious = " << radius << endl;
}

void Rhombus::Area_calculation()//нужно указать угол
{
	area = (pow(number_of_parties.at(0), 2) * sin(angle));
	cout << "Area = " << area << endl;
}




Deltoid::Deltoid()
{
	angle = 0;
}

Deltoid::Deltoid(double a, double b) : Quadrangle(a,b,a,b)
{
	angle = 0;
}

Deltoid::Deltoid(double a, double b, double angle) : Quadrangle(a, b, a, b)
{
	this->angle = angle;
}

void Deltoid::Draw()
{
	cout << "Deltoid " << endl;
}

void Deltoid::Radius_calculation()
{
	radius = 0.5 * sqrt(pow(number_of_parties.at(0), 2) + pow(number_of_parties.at(1), 2));
	cout << "Radious = " << radius << endl;
}

void Deltoid::Area_calculation()
{
	area = (number_of_parties.at(0) * number_of_parties.at(1)* sin(angle));
	cout << "Area = " << area << endl;
}

void Deltoid::Set_angle(double angle)
{
	this->angle = angle;
}




My_rectangle::Rectangle::Rectangle()
{}

My_rectangle::Rectangle::Rectangle(double a, double b) : Quadrangle(a, b, a, b)
{}

void My_rectangle::Rectangle::Draw()
{
	cout << "Rectangle " << endl;
}

void My_rectangle::Rectangle::Radius_calculation()
{
	radius = (sqrt(((number_of_parties.at(0) + number_of_parties.at(1)) + (number_of_parties.at(0) + number_of_parties.at(1)))) / 2);
	cout << "Radious = " << radius << endl; 
}

void My_rectangle::Rectangle::Area_calculation()
{
	area = (number_of_parties.at(0) * number_of_parties.at(1));
	cout << "Area = " << area << endl;
}




Straight::Straight()
{
	lenght = 0;
}

Straight::Straight(double lenght)
{
	this->lenght = lenght;
}

void Straight::Draw()
{
		cout << "--------------------------" << endl;	
}

void Straight::Set_lenght(double lenght)
{
	this->lenght = lenght;
}

double Straight::Get_lenght()
{
	return lenght;
}

void Straight::Radius_calculation()
{}

void Straight::Area_calculation()
{}

void Straight::Perimeter_calculation()
{}
