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
	void Create() 
	{
		for (int k = 0; k < m; k++) 
		{
			Mtrx.push_back(vector<double>(n));
		}
	}
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
	void operator+(Matrix &sum)
	{
		if (sum.n != n || sum.m != m)
			throw 2;
		if (Mtrx == sum.Mtrx)
			throw 6;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				Mtrx.at(i).at(j) += sum.Fill(i, j);
	}
	//перегрузка оператора вычитания
	void operator-(Matrix &sub) 
	{
		if (sub.n != n || sub.m != m)
			throw 1;
		if (Mtrx == sub.Mtrx)
			throw 6;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				Mtrx.at(i).at(j) -= sub.Fill(i, j);
	}
	//перегрузка оператора умножения на число
	void operator*(double mul) 
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				Mtrx.at(i).at(j) *= mul;
	}
	//перегрузка оператора умножения матриц
	Matrix operator*(Matrix &mul)
	{
		if (n != mul.m)
			throw 3;
		if (Mtrx == mul.Mtrx)
			throw 6;
		Matrix H(m, mul.n);
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < mul.n; ++j)
				for (int k = 0; k < n; ++k) 
					H.Fill(i, j) += Mtrx[i][k] * mul.Fill(k, j);
		return H;
	}
	//заполнение матрицы цифрами
	double &Fill(int i, int j)
	{
		if (i >= m || j >= n)
			throw 5;
		return Mtrx[i][j];
	}
	//вывод матриц на экран
	void Out(int signal)
	{
		for (int i = 0; i < m; i++) 
		{
			for (int j = 0; j < n; j++)
			{
				if (signal && i == 0 && j == 0)
					cout.width(1);
				else
					cout.width(4);
				cout << Mtrx.at(i).at(j);
			}
			cout << endl;
		}
	}
	//произведение Адамара
	Matrix Adamar(Matrix& B) 
	{
		if (m != B.m || n != B.n)
			throw 4;
		Matrix H(m, n);
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				H.Fill(i, j) = Mtrx[i][j] * B.Fill(i, j);
		return H;
	}
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
};
