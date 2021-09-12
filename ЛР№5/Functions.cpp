#include "help.h"
#include <cmath>
#include <fstream>
//создание матрицы
void Matrix::Create()
{
	for (int k = 0; k < n; k++)
	{
		Mtrx.push_back(vector<double>(m));
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
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Mtrx.at(i).at(j) += B.Fill(i, j);
		}
	}
}
//перегрузка оператора вычитания
Matrix Matrix::operator-(Matrix &B)
{
	Matrix C(n, m);
	if (B.n != n || B.m != m)
	{
		throw 1;
	}
	if (Mtrx == B.Mtrx)
	{
		throw 6;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			C.Fill(i,j)=Mtrx.at(i).at(j) - B.Fill(i, j);
		}
	}
	return C;
}
//перегрузка оператора умножения на число
Matrix Matrix::operator*(double mul)
{
	Matrix C(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			C.Fill(i, j) = Mtrx.at(i).at(j) * mul;
		}
	}
	return C;
}
//перегрузка оператора умножения матриц
Matrix Matrix::operator*(Matrix &B)
{
	if (m != B.n)
		throw 3;
	if (Mtrx == B.Mtrx)
		throw 6;
	Matrix H(n, B.m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < B.m; ++j)
		{
			for (int k = 0; k < B.n; ++k)
			{
				H.Fill(i, j) += Mtrx[i][k] * B.Fill(k, j);
			}
		}
	}
	return H;
}
//перегрузка оператора вввода
void Matrix::operator>>(ofstream &ft)
{
	ft << n << " " << m << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ft << Mtrx[i][j] << " ";
		}
		ft << "\n";
	}
}
//перегрузка оператора вывода
Matrix Matrix::operator<<(ifstream &ft)
{
	int n1, m1;
	ft >> n1 >> m1;
	Matrix C(n1, m1);
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
		{
			ft >> C.Fill(i, j);
		}
	}
	return C;
}
//запись в бинарный файл
void Matrix::BinW(ofstream &fb)
{
	fb.write((char*)&n, sizeof(int));
	fb.write((char*)&m, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			fb.write((char*)&Mtrx[i][j], sizeof(double));
		}
	}
}
//считывание из бинарного файла
Matrix Matrix::BinR(ifstream &fb)
{
	int n1, m1;
	fb.read((char*)&n1, sizeof(int));
	fb.read((char*)&m1, sizeof(int));
	Matrix C(n1, m1);
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
		{
			fb.read((char*)&C.Fill(i, j), sizeof(double));
		}
	}
	return C;
}
//заполнение матрицы цифрами
double &Matrix::Fill(int i, int j)
{
	if (i >= n || j >= m)
		throw 5;
	return Mtrx[i][j];
}
//вывод матриц на экран
void Matrix::Out(int wid)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (wid && i == 0 && j == 0)
				cout.width(1);
			else
				cout.width(8);
			cout << fixed;
			cout.precision(3);
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
	Matrix H(n, m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			H.Fill(i, j) = Mtrx[i][j] * B.Fill(i, j);
	return H;
}
//нахождение следа матрицы
double Matrix::Trace()
{
	int i, j;
	double trace = 0;
	if (n != m)
		throw 7;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
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
	Matrix help(1, m), M(n, m);
	double tmp, temp;
	int sign = 0, signal = 0;
	for (int l = 0; l < n; l++)
	{
		for (int k = 0; k < m - 1; k++)
			if (Mtrx.at(k).at(k) == 0)
				for (int r = 0; r < n; r++)
					if (Mtrx.at(r).at(k) != 0)
					{
						for (int c = 0; c < n; c++) help.Fill(0, c) = Mtrx.at(0).at(c);
						for (int c = 0; c < n; c++) Mtrx.at(k).at(c) = Mtrx.at(r).at(c);
						for (int c = 0; c < n; c++) Mtrx.at(r).at(c) = help.Fill(0, c);
						sign += abs(r - k);
						l++;
					}
		for (int i = l + 1; i < n; i++)
		{
			tmp = Mtrx[i][l] / Mtrx[l][l];
			for (int j = 0; j < n; j++)
			{
				Mtrx[i][j] -= Mtrx[l][j] * tmp;
			}
		}
	}
	for (int l = 0; l < n; l++)
	{
		temp = Mtrx[l][0];
		for (int k = 0; k < n; k++)
			if (Mtrx[k][0] == temp && k != l)
			{
				for (int a1 = 0; a1 < n; a1++)
					if (Mtrx[k][a1] == Mtrx[l][a1])
						signal++;
				if (signal == m)
					for (int a2 = 0; a2 < m; a2++)
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
	int flag = 0;
	Matrix Bt(B.m, B.n);
	if ((B.m == 1 || B.n == 1) && (m == 1 || n == 1))
	{
		if (m != B.m || n != B.n)
		{
			if (m != B.n || n != B.m)
			{
				throw 8;
			}
			Bt = B.Transpose();
			flag = 1;
		}
		double c = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (flag == 1)
				{
					c += Mtrx[i][j] * Bt.Fill(i, j);
				}
				else
				{
					c += Mtrx[i][j] * B.Fill(i, j);
				}
				
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
	Matrix C(n, m), D(n, m);
	if (n == 1 && m == 3 && B.n == 1 && B.m == 3)
	{
		C.Fill(0, 0) = Mtrx[0][1] * B.Fill(0, 2) - Mtrx[0][2] * B.Fill(0, 1);
		C.Fill(0, 1) = Mtrx[0][0] * B.Fill(0, 2) - Mtrx[0][2] * B.Fill(0, 0);
		C.Fill(0, 2) = Mtrx[0][0] * B.Fill(0, 1) - Mtrx[0][1] * B.Fill(0, 0);
		return C;
	}
	else if (n == 3 && m == 1 && B.n == 3 && B.m == 1)
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
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			norm += (abs(Mtrx[i][j])) * (abs(Mtrx[i][j]));
	return sqrt(norm);
}
//максимальная норма
double Matrix::MaxNorm()
{
	if (n != 1 && m != 1)
		throw 9;
	double max = Mtrx.at(0).at(0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
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
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
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
	Matrix M(n, m);
	M.Mtrx = Mtrx;
	M = M.ElementaryTr(0);
	for (int k = 0; k < n; k++)
		if (M.Mtrx[k][0] == 0)
		{
			for (int c = 0; c < m; c++)
			{
				if (M.Mtrx[k][c] == 0)
					count++;
			}
			if (count == m)
			{
				zero++;
			}
			count = 0;
		}
	return M.n - zero;
}
//нахождение миноров матрицы
Matrix Matrix::Minor(int a, int b)
{
	Matrix M, N(n - 1, m - 1);
	M.Mtrx = Mtrx;
	cout << 'm' << endl;
	M.Out(0);
	M.Mtrx.erase(M.Mtrx.begin() + a);
	for (int i = 0; i < n - 1; i++)
	{
		M.Mtrx.at(i).erase(M.Mtrx.at(i).begin() + b);
		M.Out(0);
	}
	N.Mtrx = M.Mtrx;
	return N;
}
//нахождение обратной матрицы
Matrix Matrix::InvertM()
{
	double det,el;
	Matrix M(n, m), Min;
	det = Determinate();
	if ((n != m) || (det == 0))
	{
		throw 11;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Min = Minor(i, j);
			cout << "min" << endl;
			Min.Out(0);
			el = pow(-1, i + j) * Minor(i, j).Determinate();
			cout << Minor(i, j).Determinate() << endl;
			M.Mtrx[i][j] = el;
		}
	}
	M = M.Transpose();
	M * (1 / det);
	return M;
}
//транспонирование
Matrix Matrix::Transpose()
{
	Matrix ans(m, n);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			ans.Fill(i, j) = Mtrx[j][i];
	return ans;
}
//добавление столбца в матрицу
Matrix Matrix::Add(Matrix& t)
{
	Matrix C(t.n, m+1);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			C.Fill(i, j)=Mtrx[i][j];
		}
	}
	for (int i = 0; i < t.n; i++)
	{
		C.Fill(i,m) = t.Fill(i, 0);
	}
	return C;
}
//центрирование
void PCA::Centr(Matrix& B)
{
	double mj;
	for (int i = 0; i < B.m; i++)
	{
		mj = 0;
		for (int j = 0; j < B.n; j++)
		{
			mj += B.Fill(j,i);
		}
		mj /= B.n;
		for (int j = 0; j < B.n; j++)
		{
			B.Fill(j, i) -= mj;
		}
	}
}
//шкалирование
 void PCA::Scal(Matrix& B)
 {
	 double sum, sj;
	 for (int i = 0; i < B.m; i++)
	 {
		 sum = 0;
		 for (int j = 0; j < B.n; j++)
		 {
			 sum += B.Fill(j, i) * B.Fill(j, i);
		 }
		 sj = sqrt(sum /(B.n-1));
		 for (int j = 0; j < B.n; j++)
		 {
			 B.Fill(j, i) /=sj;
		 }
	 }
 }
 //нахождение нормы
 double Matrix::Norm()
 {
	 double norm = 0;
	 for (int i = 0; i < n; i++)
	 {
		 for (int j = 0; j < m; j++)
		 {
			 norm += abs(Mtrx[i][j]) * abs(Mtrx[i][j]);
		 }
	 }
	 return sqrt(norm);
 }
 /*double PCA::TRV(int A)
 {
	 vector<double> dev = Deviation(A);
	 int I = E.get_M();
	 int J = E.get_N();
	 double trv = 0;
	 for (double i : dev)
		 trv += i;
	 trv /= I * J;
	 return trv;
 }
 double PCA::ERV(int A)
 {
	 PCA zero(E, 0);
	 double erv = 1 - (TRV(A) / zero.TRV(0));
	 return erv;
 }
 vector<double> PCA::Deviation(int A)
 {
	 NIPALS(A);
	 vector<double> calc;
	 int m = E.get_M();
	 int n = E.get_N();
	 for (int i = 0; i < m; i++)
	 {
		 calc.push_back(0);
		 for (int j = 0; j < n; j++)
			 calc.back() += E.get(i, j) * E.get(i, j);
	 }
	 return calc;
 }*/
 vector<double> PCA::Leverage(Matrix& C)
 {
	 vector<double> calc;
	 Matrix T = C;
	for (int i = 0; i < T.n; i++)
	 {
		 Matrix t(T.m, 1),tt,TT, ti,tmp,fin;
		for (int k = 0; k < T.m; k++)
		{
			t.Fill(k, 0) = T.Fill(k, i);	
		}
		tt = t.Transpose();
		TT = T.Transpose();
		ti = (T*TT);
		cout << "tibefore" << endl;
		ti.Out(0);
		ti = ti.InvertM();
		cout << "ti" << endl;
		ti.Out(0);
		cout << ti.n << ti.m << endl;
		tmp = tt * ti;
		cout << "tmp" << endl;
		tmp.Out(0);
		fin = tmp * t;
		cout << "fin" << endl;
		fin.Out(0);
	 }
	 return calc;
 }
 //алгоритм NIPALS
 void PCA::NIPALS(Matrix& X)
 {
	 Matrix D;
	 Matrix T(0,0), P(0, 0),told,d,E;
	 ofstream ft,fp;
	 ft.open("scores.txt");
	 fp.open("loadings.txt");
	 double eps = 1e-8;
	 int min;
	 if (X.n < X.m)
	 {
		 min = X.n;
	 }
	 else
	 {
		 min = X.m;
	 }
	 D = X;
	 Centr(D);
	 Scal(D);
	 E = D;
	 for (int h = 0; h < min;h++)
	 {
		 Matrix t(E.n,1), tt,pt, p,ttE,Ep;
		 double ttt;
		 for (int i = 0; i < E.n; i++)
		 {
			 t.Fill(i, 0) = E.Fill(i, h);
		 }
		 do
		 {
			 tt = t.Transpose();
			 pt = (tt*E)*(1/(tt.MultScal(t)));
			 p = pt.Transpose();
			 p = p * (1 / p.Norm());
			 pt = p.Transpose();
			 told = t;
			 t = (E * p*(1/p.Transpose().MultScal(p)));
			 d = told - t;	 
		 } while (d.Norm() > eps);
		 pt = p.Transpose();
		 Matrix help;
		 help = t * pt;
		 E = E - help;
		 T = T.Add(t);
		 P = P.Add(p);
	 }
		T >> ft;
		ft.close();
		P >> fp;
	    fp.close();
 }
