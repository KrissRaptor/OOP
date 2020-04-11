#include <iostream>
#include <windows.h> // ��� SetCursorPos
#include<conio.h> // ��� getch()

using namespace std;

class speedometer // 2 �������
{
public:

	speedometer() : speedometer(0, 2500, 1, 0) {}//������. �� ���������
	
	speedometer(int minimum_range, int maximum_range) : speedometer(minimum_range,maximum_range,1,0){}//������. � �����. ���. ����

	speedometer(int speed) : speedometer(0, 2500, 1, speed) {}//������. � ����� ��������

	speedometer(int minimum_range, int maximum_range ,int increment_of_growth ,int speed)//������. �� ���� �����������
	{
		this->maximum_range = maximum_range;
		this->minimum_range = minimum_range;
		this->increment_of_growth = increment_of_growth;
		this->speed = speed;
	}

	int get_current_speed()
	{
		return speed;
	}
	void set_min_value_speedometr()
	{
		min_value_speedometr();
	}
	void set_max_value_speedometr()
	{
		max_value_speedometr();
	}
	void set_counter_increase_by_1()
	{
		counter_increase_by_1();
	}
	void set_counter_increase_by_user()
	{
		counter_increase_by_user();
	}

	void play_game()
	{
		the_game_speedometr();
	}

private:

	int maximum_range;//����

	int minimum_range;//���

	int increment_of_growth;//��� ��������

	int speed;// �����. �������� ����������

	void min_value_speedometr()
	{
		int answer;
		cout << "Enter a min value of speedometr : ";
		
		do // �������� ������������ �����
		{
		  cin >> answer;
		} while (answer < 0 );
		if (answer >= 0)
		{
			minimum_range = answer;
		}

	}
	
	void max_value_speedometr()
	{
		int answer;
		cout << "Enter a max value of speedometr : ";

		do // �������� ������������ �����
		{
			cin >> answer;
		} while (answer < 0);
		if (answer >= 0)
		{
			maximum_range = answer;
		}
	}

	void counter_increase_by_1() //���������� �������� �� 1
	{
		speed++;
		reset();
	}

	void counter_increase_by_user()
	{
		int growth;
		cout << "enter counter increment : ";cin >> growth;
		speed += growth;
		reset();
	}

	void the_game_speedometr()
	{
		int answer;
		cout << "Enter how much you want to increase the value :";
		cin >> answer;
		cout << "Press space to increase speed" << endl;

		while (true)
		{
			char key = _getch();
			if (key == 32) //������� �������
			{
				speed += answer;
				cout << "Your current speed : " << speed << "\n";

				if (speed <= 100)
				{
					cout << "\t\t\tYou gain speed keep going " << "\n";
				}
				else if (speed > 100 && speed <= 200)
				{
					cout << "\t\t\tOk faster " << "\n" << "\t\t\tSee that the police do not stop!" << "\n";
				}
				else if (speed > 410 && speed <= 550)
				{
					cout << "\t\t\tYou are already faster than Bugatti Veyron " << "\n";
				}
				else if (speed > 550 && speed <= 750)
				{
					cout << "\t\t\tYou are already faster than helicopters " << "\n";
				}
				else if (speed > 750 && speed <= 1000)
				{
					cout << "\t\t\tYou gain the speed of the plane, watch the temperature of the engine" << "\n";
				}
				else if (speed > 1100 && speed <= 1200)
				{
					cout << "\t\t\tYou are faster then airbus A380 " << "\n";
				}
				else if (speed > 2100 && speed <= 2200)
				{
					cout << "\t\t\tYou are faster then F-22" << "\n" << "\t\t\tyou think smoke is coming from the hood" << "\n";
				}
				else if (speed > 2200 && speed < 2300)
				{
					cout << "\t\t\tWhy try?You gonna die" << "\n";
				}
				else if (speed == 2500 || speed > 2500)
				{
					cout << "\t\t\tThe car stopped because the engine is on" << "\n" << "\t\t\tyou should go if you want to live" << "\n";
					break;
				}
				reset();
				//Sleep(400);
			}
		}
	}

	void reset() //����� �������� ��� ������������
	{
		if (speed == maximum_range || speed <= minimum_range)
		{
			speed = 0;
		}
	}

};  // ������ �������

class point // 1 �������
{
public:

	point() : point(0, 0) {} // ����������� �� �����.
    
	point(int coord_X1, int coord_Y1 = 5) //����������� � ��������.
	{
		coord_X = coord_X1;
		coord_Y = coord_Y1;
	}

	void set_coord_X(int X)//������
	{
		coord_X = X;
	}
	void set_coord_Y(int Y)//������
	{
		coord_Y = Y;
	}

	int get_coord_X() //������
	{
		return coord_X;
	}
	int get_coord_Y() //������
	{
		return coord_Y;
	}
	void set_move_to_the_left(int X) //�������� �� ����
	{
		move_to_the_left(X);
	}
	void set_move_to_the_right(int X)//�������� �� �����
	{
		move_to_the_right(X);
	}
	void set_move_to_the_button(int Y)//�������� �� ���
	{
		move_to_the_button(Y);
	}
	void set_move_to_the_top(int Y)//�������� �� �����
	{
		move_to_the_top(Y);
	}
	void see_drawing()
	{
		draw_point();
	}

private:

	/*int coordinate_offset()
	{
		int coord;
		cout << "enter how much you want to shift the point : "; cin >> coord;
		return coord;
	}*/

	void move_to_the_left(int X)
	{
		coord_X -= X;
	}
	void move_to_the_right(int X)
	{
		coord_X += X;
	}
	void move_to_the_button(int Y) // ���
	{
		coord_Y += Y;
	}
	void move_to_the_top(int Y) //����
	{
		coord_Y -= Y;
	}
	void draw_point()
	{
		//system("cls");
		set_cursor(coord_X, coord_Y);
		cout << "*"; // �����
	}
	
	void set_cursor(int coord_X, int coord_Y)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD position; //������� x � y
		position.X = coord_X;
		position.Y = coord_Y;
		SetConsoleCursorPosition(hConsole, position);
	}
	
	int coord_X ;
	int coord_Y ;
}; // 1 �������

int main()
{
	speedometer car; //2 ������� 
	car.play_game();
	
	//////////////////////////////////////////////
	system("cls");
	point p; // 1 �������
	p.set_move_to_the_right(25);
	p.set_move_to_the_button(15);
	p.see_drawing();
	return 0;
}