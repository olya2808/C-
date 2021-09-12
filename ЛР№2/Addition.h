#pragma once
#include <string>
using namespace std;

typedef struct {//структура даты
	int day;
	int month;
	int year;
} DATE;
typedef struct {//структура ФИО
	string fam;
	string name;
	string otch;
} FIO;
class Passenger {//класс пассажира
public:
	int num_flight; // номер рейса
	DATE date;
	FIO fio;
	int num_seat; // номер сиденья

	// перегрузка операторов
	bool operator >= (const Passenger&) const;
	bool operator > (const Passenger&) const;
	bool operator < (const Passenger&) const;
	bool operator <= (const Passenger&) const;
	bool operator != (const Passenger&) const;
	bool operator == (const Passenger&) const;
};
Passenger *bubble_sort(Passenger *pas, int n); //прототип сортировки пузырьком
Passenger *input_sort(Passenger *pas, int n);//прототип сортировки вставками
void print(Passenger *pas, int n); //печать массива пассажиров
