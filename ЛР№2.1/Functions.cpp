#include "help.h"
//создание матрицы
void Matrix::Create()
{
	for (int k = 0; k < m; k++)
	{
		Mtrx.push_back(vector<double>(n));
	}
}
//перегрузка оператора сложения
void Matrix::operator+(Matrix &B)
{
	if (B.n != n || B.m != m)
	{
		throw 2;
	}
	if (Mtrx == B.Mtrx)
	{
		throw 6;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Mtrx.at(i).at(j) += B.Fill(i, j);
		}
	}
}
//перегрузка оператора вычитания
void Matrix::operator-(Matrix &B)
{
	if (B.n != n || B.m != m)
	{
		throw 1;
	}
	if (Mtrx == B.Mtrx)
	{
		throw 6;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Mtrx.at(i).at(j) -= B.Fill(i, j);
		}
	}
}
//перегрузка оператора умножения на число
void Matrix::operator*(double mul)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Mtrx.at(i).at(j) *= mul;
		}
	}
}
//перегрузка оператора умножения матриц
Matrix Matrix::operator*(Matrix &B)
{
	if (n != B.m)
		throw 3;
	if (Mtrx == B.Mtrx)
		throw 6;
	Matrix H(m, B.n);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < B.n; ++j)
			for (int k = 0; k < n; ++k)
				H.Fill(i, j) += Mtrx[i][k] * B.Fill(k, j);
	return H;
}
//заполнение матрицы цифрами
double &Matrix::Fill(int i, int j)
{
	if (i >= m || j >= n)
		throw 5;
	return Mtrx[i][j];
}
//вывод матриц на экран
void Matrix::Out(int signal)
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
Matrix Matrix::Adamar(Matrix& B)
{
	if (m != B.m || n != B.n)
		throw 4;
	Matrix H(m, n);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			H.Fill(i, j) = Mtrx[i][j] * B.Fill(i, j);
	return H;
}
//нахождение следа матрицы
double Matrix::Trace()
{
	int i, j;
	double trace = 0;
	if (m != n)
		throw 7;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
			{
				trace += Mtrx[i][j];
			}
		}
	}
	return trace;
}
//нахождение определителя матрицы методом Гаусса
double Matrix::Determinate()
{
	if (n != m)
		throw 7;
	int k;
	double det = 1, tmp;
	for (k = 0; k < n; k++)
		for (int i = k + 1; i < n; i++) 
		{
			tmp = Mtrx[i][k] / Mtrx[k][k];
			for (int j = 0; j < n; j++)
				Mtrx[i][j] -= Mtrx[k][j] * tmp;
		}
	for (int i = 0; i < n; i++)
	{
		det *= Mtrx.at(i).at(i);
	}
	return det;
}

//скалярное умножение векторов
double Matrix::MultScal(Matrix& B) 
{
	if ((B.m == 1 || B.n == 1) && (m == 1 || n == 1)) 
	{
		if (m != B.m || n != B.n) 
		{
				throw 8;
		}
		double c = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				c += Mtrx[i][j] * B.Fill(i, j);
			}
		}
		return c;
	}
	else
	{
		throw 8;
	}
}
//векторное умножение векторов
Matrix Matrix::MultOut(Matrix& B) 
{
	Matrix C(m, n), D(n, m);
	if (m == 1 && n == 3 && B.m == 1 && B.n == 3)
	{
		C.Fill(0, 0) = Mtrx[0][1] * B.Fill(0, 2) - Mtrx[0][2] * B.Fill(0, 1);
		C.Fill(0, 1) = Mtrx[0][0] * B.Fill(0, 2) - Mtrx[0][2] * B.Fill(0, 0);
		C.Fill(0, 2) = Mtrx[0][0] * B.Fill(0, 1) - Mtrx[0][1] * B.Fill(0, 0);
		return C;
	}
	else if (m == 3 && n == 1 && B.m == 3 && B.n == 1)
	{
		D.Fill(0, 0) = Mtrx[1][0] * B.Fill(2, 0) - Mtrx[2][0] * B.Fill(1, 0);
		D.Fill(0, 1) = Mtrx[0][0] * B.Fill(2, 0) - Mtrx[2][0] * B.Fill(1, 0);
		D.Fill(0, 0) = Mtrx[0][0] * B.Fill(2, 0) - Mtrx[1][0] * B.Fill(1, 0);
		return D;
	}
	else
		throw 8;
}
//Евклидова норма
double Matrix::EvNorm()
{
	if (n != 1 && m != 1)
		throw 9;
	double norm = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			norm += (abs(Mtrx[i][j])) * (abs(Mtrx[i][j]));
	return sqrt(norm);
}
//максимальная норма
double Matrix::MaxNorm()
{
	if (n != 1 && m != 1)
		throw 9;
	double max = Mtrx.at(0).at(0);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (abs(Mtrx[i][j]) > max)
			{
				max = abs(Mtrx[i][j]);
			}
		}
	}
	return max;
}
//норма матрицы
double Matrix::FrobNorm()
{
	if (n != m)
	{
		throw 9;
	}
	double norm = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			norm += Mtrx[i][j] * Mtrx[i][j];
		}
	}
	return sqrt(norm);
 }
