#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
//создание класса матриц
class Matrix
{
protected:
	vector<vector<double>> Mtrx;
	int m, n;
	//создание матрицы
	void Create();
public:
	Matrix() : m(2), n(2)
	{
		Create();
	}
	Matrix(int i) : m(i), n(i)
	{
		Create();
	}
	Matrix(int i, int j) : m(i), n(j)
	{
		Create();
	}
	//очищение
	~Matrix()
	{
		Mtrx.clear();
	}
	//перегрузка оператора сложения
	void operator+(Matrix &B);
	//перегрузка оператора вычитания
	void operator-(Matrix &B);
	//перегрузка оператора умножения на число
	void operator*(double mul);
	//перегрузка оператора умножения матриц
	Matrix operator*(Matrix &B);
	//заполнение матрицы цифрами
	double &Fill(int i, int j);
	//вывод матриц на экран
	void Out(int signal);
	//произведение Адамара
	Matrix Adamar(Matrix& B);
	//нахождение следа матрицы
	double Trace();
	//нахождение определителя матрицы методом Гаусса
	double Determinate();
	//скалярное умножение векторов
	double MultScal(Matrix& B);
	//векторное умножение векторов
	Matrix MultOut(Matrix& B);
	//Евклидова норма
	double EvNorm();
	//максимальная норма
	double MaxNorm();
	//норма матрицы
	double FrobNorm();
};
//подкласс единичных матриц
class Elementary : public Matrix
{
public:
	Elementary(int i) : Matrix(i, i)
	{
		for (int j = 0; j < i; j++)
		{
			Mtrx.at(j).at(j) = 1;
		}
	}
};
//подкласс диагональных матриц
class Diagonal : public Elementary
{
public:
	Diagonal(int i) : Elementary(i) {}
};
//подкласс верхнетреугольных матриц
class UpperTriang : public Matrix
{
public:
	UpperTriang(int i) : Matrix(i, i) {}
};
//подкласс нижнетреугольных матриц
class DownTriang : public Matrix
{
public:
	DownTriang(int i) : Matrix(i, i) {}
};
//подкласс симметричных матриц
class Simmetric : public Matrix
{
public:
	Simmetric(int i) : Matrix(i, i) {}
}
