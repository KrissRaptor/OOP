#pragma once
#include <iostream>
#include <conio.h> //дл€ _getch()
#include <windows.h> // дл€ sleep()

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

	//меню 
	void Menu_client();

	void Menu_banker();

	void Password_banker();

	/////////////////////////////////////////////////////////

	//просмотр иноформации о банке
	void See_branch_balance();

	void See_bank_balance();

	void See_number_of_branches();

	/////////////////////////////////////////////////////////

	//проверка значений функций ,антикопипаст
	void Check_value(long double& variable);//проверка на отриц и нулевые числа

	void —heck_months(int& variable);

	void —heck_years(int& variable);

	void —alculation_of_the_percentage_of_deposit(int& months);

	void Exit();

	/////////////////////////////////////////////////////////

	//выдать кредит
	void Regular_loan();//обычный кредит

	void Car_loan();// кредит на машину

	void Housing_loan(); // кредит на жильЄ

	void Give_out_a_loan();//выдать кредит

	/////////////////////////////////////////////////////////

	//заплатить за кредит
	void Pay_regular_loan();

	void Pay_car_loan();

	void Pay_housing_loan();

	void Pay_a_loan();

	/////////////////////////////////////////////////////////

	//депозит
	void Issue_a_deposit(); //выдать

	void Pick_up_deposit();//забрать

	/////////////////////////////////////////////////////////

	//пол€
	static long double general_bank_account; //баланс всех банков
	long double branch_balance; //баланс филиала
	static int password;

	int years;//перемен.которые вводит пользователь
	long double sum;//перемен.которые вводит пользователь
	int months;//кол. мес€цев

	int months_regular_loan;//кол. мес€цев
	long double monthly_payment_amount_regular_loan;//мес€чна€ оплата
	long double balance_owed_regular_loan;//остаток долга

	int months_car_loan;//кол. мес€цев
	long double monthly_payment_amount_car_loan;//мес€чна€ оплата
	long double balance_owed_car_loan;//остаток долга

	int years_housing_loan;//кол. мес€цев
	long double monthly_payment_housing_loan;//мес€чна€ оплата
	long double balance_owed_housing_loan;//остаток долга

	double summ_percent; //сумма процента
	double interest_rate; //процентна€ ставка
	static int number_of_branches; //количество филиалов

	///////////////////////////////////////////////////////////

	long double deposit_summ_percent; // cумма процента от депозита
	long double deposit_summ; // обща€ сумма депозита
	int deposit_month; // количество мес€цев депозита

	long double supposed_deposit_summ;//предположительно полна€ сумма депозита с процентами
	long double estimated_income;  //предположительный доход от депозита
};





