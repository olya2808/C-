#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Addition.h"

using namespace std;

bool Passenger::operator == (const Passenger &pas)const//перегружаем оператор ==
{
	return !(*this != pas);
}
bool Passenger::operator != (const Passenger &pas)const// перегружаем оператор !=
{
	if (fio.fam != pas.fio.fam) 
		return true;
	if (fio.name != pas.fio.name)
		return true;
	if (fio.otch != pas.fio.otch)
		return true;
	if (date.day != pas.date.day)
		return true;
	if (date.month != pas.date.month)
		return true;
	if (date.year != pas.date.year)
		return true;
	if (num_flight != pas.num_flight)
		return true;
	return false;
}
bool Passenger::operator >=(const Passenger &pas)const//перегружаем оператор >=
{
	if (date.year > pas.date.year) // сравниваем дата.год рейса
		return true;
	else if (date.year == pas.date.year)
		if (date.month > pas.date.month) // дата.месяц рейса
			return true;
		else if (date.month == pas.date.month)
			if (date.day > pas.date.day) // дата.день рейса
				return true;
			else if (date.day == pas.date.day)
				if (num_flight > pas.num_flight) // номер рейса
					return true;
				else if (num_flight == pas.num_flight)
					if (fio.fam > pas.fio.fam) // фамилия пассажира
						return true;
					else if (fio.fam == pas.fio.fam)
						if (fio.name > pas.fio.name) // имя пассажира
							return true;
						else if (fio.name == pas.fio.name)
							if (fio.otch > pas.fio.otch) // отчество пассажира
								return true;
	return false;
}
bool Passenger::operator <(const Passenger &pas)const//перегружаем оператор <
{
	return !(*this >= pas); //  !(>=) дает <
}
bool Passenger::operator >(const Passenger &pas)const//перегружаем оператор >
{
	if ((*this >= pas) && (*this != pas)) // >= и != дает >
		return true;
	return false;
}
bool Passenger::operator <=(const Passenger &pas)const//перегружаем оператор <=
{
	if (!(*this >= pas) || *this == pas) // !(>=) или == дает < или ==
		return true;
	return false;
}
Passenger *bubble_sort(Passenger *pas, int n) //сортировка пузырьком
{
	Passenger tmp; 

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (pas[j] > pas[j + 1])
			{
				tmp = pas[j + 1];
				pas[j + 1] = pas[j];
				pas[j] = tmp;
			}
		}
	}
	return pas;
}
Passenger *input_sort(Passenger *pas, int n)//сортировка вставками
{
	Passenger tmp; 
	int	i, j;
	for (int i = 1; i < n; i++)
	{
		tmp = pas[i]; 
		j = i - 1; 
		while (j >= 0 && pas[j] > tmp) 
		{
			pas[j + 1] = pas[j]; 
			pas[j] = tmp;
			j--;
		}
	}
	return pas;
}
void print(Passenger *pas, int n)//вывод массива на экран
{
	cout << "fln" << std::setfill(' ') << std::setw(9) << "dd mm yyyy" << std::setfill(' ') << std::setw(15)
		<< "FIO" << std::setfill(' ') << std::setw(17) << "seatnumber" << "\n";
	cout << "\n";//вывод строки я названиями столбцов
	for (int i = 0; i < n; i++) {//вывод массива
		cout << pas[i].num_flight << " " << pas[i].date.day << " " << pas[i].date.month << " " << pas[i].date.year
			<< " " << pas[i].fio.fam << " " << pas[i].fio.name << " " << pas[i].fio.otch << " " << pas[i].num_seat << endl;
	}
}
