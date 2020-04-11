#include "Bank.h"

#pragma once
#include <iostream>
#include <conio.h> //для _getch()
#include <windows.h> // для sleep()

using std::cin;
using std::cout;


Bank :: Bank()
{
	branch_balance = 15000000; //баланс филиала

	months = 0;
	sum = 0;
	years = 0;

	balance_owed_regular_loan = 0; //окончательная сумма выплаты
	monthly_payment_amount_regular_loan = 0;
	months_regular_loan = 0;

	balance_owed_car_loan = 0; //окончательная сумма выплаты
	monthly_payment_amount_car_loan = 0;
	months_car_loan = 0;

	balance_owed_housing_loan = 0; //окончательная сумма выплаты
	monthly_payment_housing_loan = 0;
	years_housing_loan = 0;

	interest_rate = 0; //процентная ставка
	summ_percent = 0; //сумма процента
	number_of_branches++; //увеличиваем количество филиалов

	supposed_deposit_summ = 0;
	estimated_income = 0;
	deposit_summ_percent = 0;
	deposit_summ = 0;
	deposit_month = 0;
};
Bank :: ~Bank() {};

void Bank::Mode()
{
	while (true)
	{
		cout << "\t\t\tUniCredit Bank\n";
		cout << "\tWelcome to the UniCredit Bank. Please, select mode:\n";
		cout << "\t1.Client\n";
		cout << "\t2.Banker\n";
		cout << "\t3.Exit\n";

		int answer;
		cin >> answer;
		switch (answer)
		{
		case 1:
			system("cls");
			Menu_client();
			break;
		case 2:
			system("cls");
			Menu_banker();
			break;
		case 3:
			return;
		default:
			system("cls");
		}
	}
}



/////////////////////////////////////////////////////////

//меню 
void Bank::Menu_client()
{
	while (true)
	{
		cout << "\t\t\tUniCredit Bank\n";
		cout << "\t1.Issue a deposit\n";////выдать депозит
		cout << "\t2.Accept loan payments\n";//заплатить за кредит
		cout << "\t3.Exit\n";

		int answer;
		cin >> answer;
		switch (answer)
		{
		case 1:

			system("cls");
			Pick_up_deposit();
			break;
		case 2:
			system("cls");
			Pay_a_loan();
			break;
		case 3:
			system("cls");
			return;
		default:
			system("cls");
		}
	}
}

void Bank::Menu_banker()
{
	Password_banker();
	while (true)
	{
		cout << "\t\t\tUniCredit Bank\n";
		cout << "\t1.Issue a deposit\n";//выдать депоз.
		cout << "\t2.Give out a loan\n";//выдать кред.
		cout << "\t3.See branch balance\n";//посмотреть баланс филиала
		cout << "\t4.See bank balance\n";//посмотреть баланс банка
		cout << "\t5.See the number of bank branches\n";
		cout << "\t6.Exit\n";
		int answer;

		cin >> answer;
		switch (answer)
		{
		case 1:
			system("cls");
			Issue_a_deposit();
			break;
		case 2:
			system("cls");
			Give_out_a_loan();
			break;
		case 3:
			system("cls");
			See_branch_balance();
			break;
		case 4:
			system("cls");
			See_bank_balance();
			break;
		case 5:
			system("cls");
			See_number_of_branches();
			break;
		case 6:
			system("cls");
			return;
		default:
			system("cls");
		}
	}
}

void Bank::Password_banker()
{
	cout << "Enter bank password : ";
	cout << "\nPress 5 to exit \n";
	while (true)
	{
		int answer_password;
		cin >> answer_password;
		if (answer_password == password)
		{
			system("cls");
			break;
		}
		else if (answer_password == 5)
		{
			return;
		}
		else
		{
			cout << "Invalid password! ";

		}
	}
}

/////////////////////////////////////////////////////////

//просмотр иноформации о банке
void Bank::See_branch_balance()
{
	cout << "\tBranch balance : " << branch_balance << " $\n";
	Exit();
}

void Bank::See_bank_balance()
{
	cout << "\tBank balance : " << general_bank_account << " $\n";
	Exit();
}

void Bank::See_number_of_branches()
{
	cout << "\tNumber of branches : " << number_of_branches << "\n";
	Exit();
}
/////////////////////////////////////////////////////////

//проверка значений функций ,антикопипаст
void Bank::Check_value(long double& variable) //проверка на отриц и нулевые числа
{
	while (true)
	{
		cin >> variable;
		if (variable <= 0)
		{
			cout << "Error, you cannot enter 0 and negative numbers!Please ,enter positive numbers : ";
		}
		else
		{
			break;
		}
	}
}

void Bank::Сheck_months(int& variable)
{
	while (true)
	{
		cin >> variable;
		if (variable > 60 || variable < 0)
		{
			cout << "Sorry, we don’t have such a loan for such a long time.Loan terms: from 1 to 60 months ";
			//должен быть вызов метода
		}
		else
		{
			break;
		}
	}
}

void Bank::Сheck_years(int& variable)
{
	while (true)
	{
		cin >> variable;
		if (variable > 30 || variable < 5)
		{
			cout << "Sorry, we don’t have such a loan for such a long time.Loan terms: from 5 to 30 years ";
			//должен быть вызов метода
		}
		else
		{
			break;
		}
	}
}

void Bank::Сalculation_of_the_percentage_of_deposit(int& months)
{
	if (months > 3 && months <= 5)
	{
		interest_rate = 12.25;
	}
	else if (months > 6 && months <= 8)
	{
		interest_rate = 13.25;
	}
	else if (months > 9 && months <= 12)
	{
		interest_rate = 13.75;
	}
	else if (months > 18 && months <= 24)
	{
		interest_rate = 14;
	}
	else if (months > 24 && months <= 30)
	{
		interest_rate = 14.05;
	}
	else if (months > 30 && months <= 36)
	{
		interest_rate = 13.75;
	}
	else if (months > 30 && months <= 36)
	{
		interest_rate = 12;
	}
	else if (months > 36 && months <= 48)
	{
		interest_rate = 11.5;
	}
}

void Bank::Exit()
{
	cout << "\tPress 5 to return to the menu : ";
	int answer;
	while (true)
	{
		cin >> answer;
		if (answer == 5)
		{
			system("cls");
			return;
		}
		else
		{
			cout << "\n\tError,press key 5" << std::endl;
		}
	}
}
/////////////////////////////////////////////////////////

//выдать кредит
void Bank::Regular_loan()//обычный кредит
{
	if (balance_owed_regular_loan > 0)
	{
		cout << "You cannot take a new loan until the old one has been paid!\n";
		Sleep(8000);
		system("cls");
		return;
	}
	else if (balance_owed_regular_loan <= 0)
	{
		cout << "Enter the amount you want to borrow : ";
		Check_value(sum);
		while (true) //диапазон кредитов
		{
			if (sum > 500000)
			{
				cout << "Sorry, we do not issue loans for a large amount.\nPlease enter a value less :";
				Check_value(sum);
			}
			else if (sum <= 500000)
			{
				break;
			}
		}


		cout << "Enter the number of months for which you want to take a loan : ";
		Сheck_months(months);

		months_regular_loan = months;

		if (months <= 3)
		{
			interest_rate = 0.1;
		}
		else if (months > 3 && months <= 6)
		{
			interest_rate = 0.3;
		}
		else if (months > 6 && months <= 9)
		{
			interest_rate = 0.5;
		}
		else if (months > 9 && months <= 12)
		{
			interest_rate = 0.7;
		}
		else if (months > 12 && months <= 24)
		{
			interest_rate = 1.1;
		}
		else if (months > 24 && months <= 36)
		{
			interest_rate = 1.5;
		}
		else if (months > 36 && months <= 48)
		{
			interest_rate = 2.1;
		}
		else if (months > 48 && months <= 60)
		{
			interest_rate = 2.5;
		}
		else if (months == 60)
		{
			interest_rate = 3.1;
		}
		summ_percent = (interest_rate * sum / 100); //расчет  суммы процента

		balance_owed_regular_loan = (summ_percent + sum);//расчет общей суммы с процентом

		monthly_payment_amount_regular_loan += (balance_owed_regular_loan / months_regular_loan);//расчет месячной оплаты

		general_bank_account -= sum;
		branch_balance -= sum;

		cout << "The total amount with interest : " << balance_owed_regular_loan << " $ " << "Interest amount : " << summ_percent << "\n";

		Exit();
		return;
	}
} //обычный кредит

void Bank::Car_loan()// кредит на машину
{
	if (balance_owed_car_loan > 0)
	{
		cout << "You cannot take a new loan until the old one has been paid!\n";
		Sleep(8000);
		system("cls");
		return;
	}
	else if (balance_owed_car_loan <= 0)
	{
		cout << "Enter the amount you want to borrow : ";
		Check_value(sum);

		while (true) //диапазон кредитов
		{
			if (sum > 3000000)
			{
				cout << "Sorry, we do not issue loans for a large amount.\nPlease enter a value less :";
				Check_value(sum);
			}
			else if (sum <= 3000000)
			{
				break;
			}
		}

		cout << "Enter the number of months for which you want to take a loan : ";
		Сheck_months(months);

		months_car_loan = months;

		if (months == 12)
		{
			interest_rate = 0.5;
		}
		else if (months > 12 && months <= 24)
		{
			interest_rate = 1.5;
		}
		else if (months > 24 && months <= 36)
		{
			interest_rate = 2.5;
		}
		else if (months > 36 && months <= 48)
		{
			interest_rate = 3.5;
		}
		else if (months > 48 && months <= 60)
		{
			interest_rate = 4.5;
		}
		else if (months == 60)
		{
			interest_rate = 5.5;
		}

		summ_percent = (interest_rate * sum / 100);

		balance_owed_car_loan = (summ_percent + sum);

		monthly_payment_amount_car_loan += (balance_owed_car_loan / months_car_loan);

		general_bank_account -= sum;
		branch_balance -= sum;

		cout << "The total amount with interest : " << balance_owed_car_loan << " $ " << "Interest amount : " << summ_percent << "\n";

		Exit();
		return;
	}
}

void Bank::Housing_loan()  // кредит на жильё
{
	if (balance_owed_housing_loan > 0)
	{
		cout << "You cannot take a new loan until the old one has been paid!\n";
		Sleep(8000);
		system("cls");
		return;
	}
	else if (balance_owed_housing_loan <= 0)
	{
		cout << "Enter the amount you want to borrow : ";
		Check_value(sum);
		while (true) //диапазон кредитов
		{
			if (sum > 15000000)
			{
				cout << "Sorry, we do not issue loans for a large amount.\nPlease enter a value less :";
				Check_value(sum);
			}
			else if (sum <= 15000000)
			{
				break;
			}
		}

		cout << "Enter the number of years for which you want to take a loan : ";
		Сheck_years(years);

		years_housing_loan = years;


		if (years == 5)
		{
			interest_rate = 1.5;
		}
		else if (years > 5 && years <= 10)
		{
			interest_rate = 2.7;
		}
		else if (years > 10 && years <= 15)
		{
			interest_rate = 4.2;
		}
		else if (years > 15 && years <= 20)
		{
			interest_rate = 5.2;
		}
		else if (years > 20 && years <= 25)
		{
			interest_rate = 6.3;
		}
		else if (years > 25 && years <= 30)
		{
			interest_rate = 7.3;
		}

		summ_percent = (interest_rate * sum / 100);

		balance_owed_housing_loan = (summ_percent + sum);

		monthly_payment_housing_loan = ((balance_owed_housing_loan / years_housing_loan) / 12);

		general_bank_account -= sum;
		branch_balance -= sum;

		cout << "The total amount with interest : " << balance_owed_housing_loan << " $ " << "Interest amount : " << summ_percent << "\n";

		Exit();
		return;
	}
}

void Bank::Give_out_a_loan()//выдать кредит
{
	while (true)
	{
		cout << "Enter which loan you want to take :\n";
		cout << "1.Regular loan\n";
		cout << "2.Car loan\n";
		cout << "3.Housin loan\n";
		cout << "4.Exit\n";

		int answer;
		cin >> answer;
		switch (answer)
		{
		case 1:
			system("cls");
			Regular_loan();
			break;
		case 2:
			system("cls");
			Car_loan();
			break;
		case 3:
			system("cls");
			Housing_loan();
			break;
		case 4:
			system("cls");
			return;
		default:
			system("cls");
		}
	}
}

/////////////////////////////////////////////////////////

//заплатить за кредит
void Bank::Pay_regular_loan()
{
	if (balance_owed_regular_loan <= 0)
	{
		cout << "You do not owe the bank a regular loan, have a nice day :)\n";
		Sleep(8000);
		system("cls");
		return;
	}
	else if (balance_owed_regular_loan > 0)
	{
		cout << "Your loan debt is : " << balance_owed_regular_loan << "$\n";
		cout << "You need to pay per month : " << monthly_payment_amount_regular_loan << "$\n";
		cout << "Please ,press key + to pay a debt for month : \n";
		cout << "Press - to exit \n";

		while (true)
		{
			if (balance_owed_regular_loan <= 0)
			{
				cout << "You have successfully paid the loan.Thank you for choosing our bank! :)\n";
				Sleep(8000); //подождать пока клиент прочитает сообщение
				system("cls");
				break;
			}

			char answer = _getch(); //выход
			if (answer == 45)
			{
				//continue;
				system("cls");
				return;
			}
			else if (answer == 43) //проверка на правильность
			{
				balance_owed_regular_loan -= monthly_payment_amount_regular_loan;
				cout << "Payment accepted successfully, want to pay for the next month ? Yes press + No press -  ";
				cout << "\nYour loan debt is : " << balance_owed_regular_loan << "$\n";

				general_bank_account += monthly_payment_amount_regular_loan;
				branch_balance += monthly_payment_amount_regular_loan;
			}
			else
			{
				cout << "\nError,please press keys + or - \n";
			}
		}
	}
}

void Bank::Pay_car_loan()
{
	if (balance_owed_car_loan <= 0)
	{
		cout << "You do not owe the bank a car loan, have a nice day :)\n";
		Sleep(8000);
		system("cls");
	}
	else if (balance_owed_car_loan > 0)
	{
		cout << "Your loan debt is : " << balance_owed_car_loan << "$\n";
		cout << "You need to pay per month : " << monthly_payment_amount_car_loan << "$\n";
		cout << "Please ,press key + to pay a debt for month : \n";
		while (true)//проверка на правильность ввода
		{
			char key = _getch(); //45
			if (key == 43)
			{
				break;
			}
			else
			{
				cout << "Error ,please press key +\n";
			}
		}


		balance_owed_car_loan -= monthly_payment_amount_car_loan;
		cout << "Payment accepted successfully!Your loan debt is : " << balance_owed_car_loan << "$\nWant to pay for the next month ? Yes press + No press -  ";
		while (true)
		{
			if (balance_owed_car_loan <= 0)
			{
				cout << "\nYou have successfully paid the loan.Thank you for choosing our bank! :)\n";
				Sleep(8000); //подождать пока клиент прочитает сообщение
				system("cls");
				break;
			}

			char answer = _getch(); //выход
			if (answer == 45)
			{
				//continue;
				system("cls");
				return;
			}
			else if (answer == 43) //проверка на правильность
			{
				balance_owed_car_loan -= monthly_payment_amount_car_loan;
				cout << "\nPayment accepted successfully, want to pay for the next month ? Yes press + No press -  ";
				cout << "\nYour loan debt is : " << balance_owed_car_loan << "$\n";
			}
			else
			{
				cout << "\nError,please press keys + or - \n";

				general_bank_account += monthly_payment_amount_car_loan;
				branch_balance += monthly_payment_amount_car_loan;
			}
		}
	}
}

void Bank::Pay_housing_loan()
{
	if (balance_owed_housing_loan <= 0)
	{
		cout << "You do not owe the bank a housing loan, have a nice day :)\n";
		Sleep(8000);
		system("cls");
	}
	else if (balance_owed_housing_loan > 0)
	{
		cout << "Your loan debt is : " << balance_owed_housing_loan << "$\n";
		cout << "You need to pay per month : " << monthly_payment_housing_loan << "$\n";
		cout << "Please ,press key + to pay a debt for month : \n";
		while (true)//проверка на правильность ввода
		{
			char key = _getch(); //45
			if (key == 43)
			{
				break;
			}
			else
			{
				cout << "Error ,please press key +\n";
			}
		}


		balance_owed_housing_loan -= monthly_payment_housing_loan;
		cout << "Payment accepted successfully, want to pay for the next month ? Yes press + No press -  ";
		while (true)
		{
			if (balance_owed_housing_loan <= 0)
			{
				cout << "\nYou have successfully paid the loan.Thank you for choosing our bank! :)\n";
				Sleep(8000); //подождать пока клиент прочитает сообщение
				system("cls");
				break;
			}

			char answer = _getch(); //выход
			if (answer == 45)
			{
				//continue;
				system("cls");
				return;
			}
			else if (answer == 43) //проверка на правильность
			{
				balance_owed_housing_loan -= monthly_payment_housing_loan;
				cout << "\nPayment accepted successfully, want to pay for the next month ? Yes press + No press -  ";
				cout << "\nYour loan debt is : " << balance_owed_housing_loan << "$\n";

				general_bank_account += monthly_payment_housing_loan;
				branch_balance += monthly_payment_housing_loan;
			}
			else
			{
				cout << "\nError,please press keys + or - \n";
			}
		}
	}
}

void Bank::Pay_a_loan()
{
	while (true)
	{
		cout << "Enter which loan do you want to repay?\n";
		cout << "1.Regular loan\n";
		cout << "2.Car loan\n";
		cout << "3.Housing loan\n";
		cout << "4.Exit\n";
		int answer;
		cin >> answer;

		switch (answer)
		{
		case 1:
			system("cls");
			Pay_regular_loan();
			break;
		case 2:
			system("cls");
			Pay_car_loan();
			break;
		case 3:
			system("cls");
			Pay_housing_loan();
			break;
		case 4:
			system("cls");
			return;
		}
	}
}
/////////////////////////////////////////////////////////

//депозит
void Bank::Issue_a_deposit() //выдать
{
	if (deposit_summ > 0)
	{
		cout << "You cannot open another deposit\nIf you want to open a new deposit, please close the old deposit.\n";
		Sleep(8000);
		system("cls");
		return;
	}
	else if (deposit_summ <= 0)
	{
		cout << "Enter deposit amount : ";

		Check_value(deposit_summ);
		while (true) //диапазон кредитов
		{
			if (deposit_summ > 200000000)
			{
				cout << "Sorry, we do not issue loans for a large amount.\nPlease enter a value less :";
				Check_value(sum);
			}
			else if (deposit_summ <= 200000000)
			{
				break;
			}
		}

		cout << "Enter the number of months : ";

		while (true)
		{
			cin >> deposit_month;
			if (deposit_month > 0 && deposit_month <= 48)
			{
				break;
			}
			else
			{
				cout << "\nSorry, we don’t have such a loan for such a long time.Loan terms: from 1 to 48 months\n";
			}
		}

		general_bank_account += deposit_summ; //добавляем депозит к счету банка
		branch_balance += deposit_summ;

		Сalculation_of_the_percentage_of_deposit(deposit_month);

		estimated_income = (interest_rate * deposit_summ / 100);

		supposed_deposit_summ = deposit_summ + estimated_income;

		cout << "Total deposit amount with interest : " << supposed_deposit_summ << " $ " << "Interest amount : " << estimated_income << "\n";

		Exit();
		return;
	}
}

void Bank::Pick_up_deposit() //забрать
{
	if (deposit_summ <= 0)
	{
		cout << "You do not have open deposits\n";
		Sleep(6000);
		system("cls");
		return;
	}
	else if (deposit_summ > 0)
	{
		while (true)
		{
			cout << "If you want to withdraw the deposit amount, click + .Press - to exit";
			char answer = _getch();
			if (answer == 45)
			{
				system("cls");
				return;
			}
			else if (answer == 43) //проверка на правильность
			{
				int months;
				cout << "Enter the number of months your deposit was in the bank";

				while (true)//проверка,если пользователь попробует обмануть ,указав больше месяцев,чем брал.
				{
					cin >> months;
					if (months > deposit_month || months <= 0)
					{
						cout << "Error!You didn’t take deposit for so many months ";
					}
					else
					{
						break;
					}
				}
				Сalculation_of_the_percentage_of_deposit(months);

				deposit_summ_percent = (interest_rate * deposit_summ / 100);

				deposit_summ += deposit_summ_percent;

				general_bank_account -= deposit_summ;//пользователь снимает сумму денег вместе со процентами 
				branch_balance -= deposit_summ;

				cout << "Thank you for choosing our bank for deposit :)";
				cout << "Total deposit amount with interest : " << deposit_summ << " $ " << "Interest amount : " << deposit_summ_percent << "\n";

				Exit();
				return;
			}
			else
			{
				cout << "Error!Please click + or -";
			}
		}
	}
}


//задаём значение по умолчанию
long double Bank::general_bank_account = 100000000; //100 млн
int Bank::number_of_branches = 0;
int Bank::password = 5893;




