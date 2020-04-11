#pragma once
#include <iostream>
#include <conio.h> //��� _getch()
#include <windows.h> // ��� sleep()

using std::cin;
using std::cout;

class Bank
{
public:
	Bank();

	~Bank();

	void Mode();

private:

	/////////////////////////////////////////////////////////

	//���� 
	void Menu_client();

	void Menu_banker();

	void Password_banker();

	/////////////////////////////////////////////////////////

	//�������� ����������� � �����
	void See_branch_balance();

	void See_bank_balance();

	void See_number_of_branches();

	/////////////////////////////////////////////////////////

	//�������� �������� ������� ,������������
	void Check_value(long double& variable);//�������� �� ����� � ������� �����

	void �heck_months(int& variable);

	void �heck_years(int& variable);

	void �alculation_of_the_percentage_of_deposit(int& months);

	void Exit();

	/////////////////////////////////////////////////////////

	//������ ������
	void Regular_loan();//������� ������

	void Car_loan();// ������ �� ������

	void Housing_loan(); // ������ �� �����

	void Give_out_a_loan();//������ ������

	/////////////////////////////////////////////////////////

	//��������� �� ������
	void Pay_regular_loan();

	void Pay_car_loan();

	void Pay_housing_loan();

	void Pay_a_loan();

	/////////////////////////////////////////////////////////

	//�������
	void Issue_a_deposit(); //������

	void Pick_up_deposit();//�������

	/////////////////////////////////////////////////////////

	//����
	static long double general_bank_account; //������ ���� ������
	long double branch_balance; //������ �������
	static int password;

	int years;//�������.������� ������ ������������
	long double sum;//�������.������� ������ ������������
	int months;//���. �������

	int months_regular_loan;//���. �������
	long double monthly_payment_amount_regular_loan;//�������� ������
	long double balance_owed_regular_loan;//������� �����

	int months_car_loan;//���. �������
	long double monthly_payment_amount_car_loan;//�������� ������
	long double balance_owed_car_loan;//������� �����

	int years_housing_loan;//���. �������
	long double monthly_payment_housing_loan;//�������� ������
	long double balance_owed_housing_loan;//������� �����

	double summ_percent; //����� ��������
	double interest_rate; //���������� ������
	static int number_of_branches; //���������� ��������

	///////////////////////////////////////////////////////////

	long double deposit_summ_percent; // c���� �������� �� ��������
	long double deposit_summ; // ����� ����� ��������
	int deposit_month; // ���������� ������� ��������

	long double supposed_deposit_summ;//���������������� ������ ����� �������� � ����������
	long double estimated_income;  //����������������� ����� �� ��������
};





