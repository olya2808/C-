#include "help.h"
#include <cmath>
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
//элеменетарные преобразования
Matrix Matrix::ElementaryTr(int flag)
{
	Matrix help(1, n), M(m, n);
	double tmp, temp;
	int sign = 0, signal = 0;
	for (int l = 0; l < m; l++) 
	{
		for (int k = 0; k < n - 1; k++)
			if (Mtrx.at(k).at(k) == 0)
				for (int r = 0; r < m; r++)
					if (Mtrx.at(r).at(k) != 0)
					{
						for (int c = 0; c < n; c++) help.Fill(0, c) = Mtrx.at(0).at(c);
						for (int c = 0; c < n; c++) Mtrx.at(k).at(c) = Mtrx.at(r).at(c);
						for (int c = 0; c < n; c++) Mtrx.at(r).at(c) = help.Fill(0, c);
						sign += abs(r - k);
						l++;
					}
		for (int i = l + 1; i < m; i++) 
		{
			tmp = Mtrx[i][l] / Mtrx[l][l];
			for (int j = 0; j < m; j++)
			{
				Mtrx[i][j] -= Mtrx[l][j] * tmp;
			}
		}
	}
	for (int l = 0; l < m; l++)
	{
		temp = Mtrx[l][0];
		for (int k = 0; k < m; k++)
			if (Mtrx[k][0] == temp && k != l) 
			{
				for (int a1 = 0; a1 < n; a1++)
					if (Mtrx[k][a1] == Mtrx[l][a1])
						signal++;
				if (signal == n)
					for (int a2 = 0; a2 < n; a2++)
						Mtrx[k][a2] = 0;
				signal = 0;
			}
	}
	if (sign % 2 == 1 && flag == 0)
		Mtrx[0][0] = -Mtrx[0][0];
	M.Mtrx = Mtrx;
	return M;
}
//нахождение определителя матрицы методом Гаусса
double Matrix::Determinate()
{
	Matrix M(n, m);
	M.Mtrx = Mtrx;
	if (n != m)
		throw 7;
	double det = 1;
	M.ElementaryTr(0);
	for (int i = 0; i < n; i++)
		det *= M.Mtrx.at(i).at(i);
	if (det == 0)
	{
		return abs(det);
	}
	else
	{
		return det;
	}
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
//нахождение угла между векторами
double Matrix::Angle(Matrix& B)
{
	double ans;
	ans = MultScal(B) / (EvNorm()*B.EvNorm());
	return ans;
}
//нахождение ранга матрицы
int Matrix::Rank()
{
	int count = 0, zero = 0;
	Matrix M(m, n);
	M.Mtrx = Mtrx;
	M = M.ElementaryTr(0);
	for (int k = 0; k < m; k++)
		if (M.Mtrx[k][0] == 0) 
		{
			for (int c = 0; c < n; c++)
			{
				if (M.Mtrx[k][c] == 0)
					count++;
			}
			if (count == n) 
			{
				zero++;
			}
			count = 0;
		}
	return M.m - zero;
}
//нахождение миноров матрицы
Matrix Matrix::Minor(int a, int b)
{
	Matrix M(n, m), N(n - 1, m - 1);
	M.Mtrx = Mtrx;
	M.Mtrx.erase(M.Mtrx.begin() + a);
	for (int i = 0; i < n - 1; i++)
		M.Mtrx.at(i).erase(M.Mtrx.at(i).begin() + b);
	N.Mtrx = M.Mtrx;
	return N;
}
//нахождение обратной матрицы
Matrix Matrix::InvertM()
{
	double det;
	Matrix M(n, m);
	det = Determinate();
	if ((n != m)||(det == 0))
	{
		throw 11;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
		{
			M.Mtrx.at(i).at(j) = pow(-1, i + j) * Minor(i, j).Determinate();
			M.Out(0);
		}
	M = M.Transpose();
	M * (1 / det);
	return M;
}
//транспонирование
Matrix Matrix::Transpose()
{
	Matrix ans(n, m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			ans.Fill(i, j) = Mtrx[j][i];
	return ans;
}
//нахождение минора
