#include <iostream>
#include <string>
#include <locale>
#include <fstream> // Для файлового вывода
#include <ctime> // Для функции clock
#include "Addition.h"

using namespace std;

int main()
{
	int n = 1200; 
	unsigned long start, end, tb, ti;  // Переменные для работы со временем
	ifstream f;//для файла
	f.open("8data.txt"); //проверка на открытие
	if (!f.is_open())
	{
		cout << "File can'be opened" << endl;
		return 0;
	}
	Passenger *p = new Passenger[n]; // выделение памяти на массив пассажиров
	Passenger *ph = new Passenger[n]; 
	int i = 0; // Счетчик элементов
	while ((i < n) && (!f.eof())) // цикл по считыванию в массив
	{
		f >> p[i].num_flight;
		f >> p[i].date.day;
		f >> p[i].date.month;
		f >> p[i].date.year;
		f >> p[i].fio.fam;
		f >> p[i].fio.name;
		f >> p[i].fio.otch;
		f >> p[i].num_seat;
		f.get(); // пропускаем символ перехода на новую строку
		i++;
	}
	if (f.eof()) // проверка на пустой файл
	{
		cout << "File is empty\n";
		f.close(); 
		return 0;
	}
	f.close(); // Закрываем файл

	//cout << "Array:\n";
	//print(p, n); // выводм исходный массив
	//cout << "\n";

	for (int i = 0; i < n; i++) // копируем заполненный исходный массив p в ph
		ph[i] = p[i];
	start = clock(); // засекаем время начала
	p = bubble_sort(p, n); // сортировка пузырьком
	end = clock(); // засекаем время конца
	tb = end - start; // время работы сортировки
	start = clock();
	ph = input_sort(ph, n); // сортировка простыми вставками
	end = clock();
	ti = end - start;
	cout << "Time of bubble sort: " << tb << "\nTime of insert sort: " << ti << endl;
	//cout << "\nSorted array:\n";
	//print(p, n); // выводим отсортированный массив
	delete[] p; // очистка памяти
	delete[] ph;
	return 0;
}
