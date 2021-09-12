#define _CRT_SECURE_NO_WARNINGS
#include "help.h"
#include <fstream>
int main()
{
	int w, wf;
	vector <Matrix> MatrixArr;
	try
	{
		//меню для работы с файлами
		cout << "From where do you want to get your matrix?" << endl;
		cout << "1) Use new txt file" << endl;
		cout << "2) Use new bin file" << endl;
		cout << "3) Use existing txt file" << endl;
		cout << "4) Use existing bin file" << endl;
		cout << "5) Exit" << endl;
		int wf;
		cin >> wf;
		switch (wf)
		{ 
		//случай для создания нового текстового файла
		case 1:
		{
			ofstream f;
			f.open("matrix.txt");
			if (!f) 
			{
				throw 12;
			}
			cout << "File named matrix.txt has been created" << endl;
			f.close();
			break;
		}
		//случай для создания нового бинарного файла
		case 2:
		{
			ofstream f;
			f.open("matrix.bin");
			if (!f)
			{
				throw 12;
			}
			cout << "File named matrix.bin has been created" << endl;
			f.close();
			break;
		}
		//случай для сущуствующего текстового файла
		case 3:
		{
			Matrix A;
			ifstream f;
			f.open("matrix.txt");
			if (!f)
			{
				throw 13;
			}
			cout << "File named exmatrix.txt has been opened" << endl;
			while (f)
			{
				MatrixArr.push_back(A<<f);
			}
			MatrixArr.pop_back();
			f.close();
			break;
		}
		//случай для сущуствующего бинарного файла
		case 4:
		{
			Matrix A;
			ifstream f;
			f.open("matrix.bin");
			if (!f)
			{
				throw 13;
			}
			cout << "File named exmatrix.bin has been opened" << endl;
			while (/*!feof(f)*/!f.eof())
			{
				MatrixArr.push_back(A.BinR(f));
			}
			MatrixArr.pop_back();
			f.close();
			break;
		}
		case 5:
		{
			return 0;
			break;
		}
		default:
		{
			cout << "Wrong choice" << endl;
			break;
		}
		}
		do
		{
			//меню для выбора функций
			cout << "What do you want ot do?" << endl;
			cout << "1) Add new matrix" << endl;
			cout << "2) Summarize" << endl;
			cout << "3) Subtract" << endl;
			cout << "4) Multiply by number" << endl;
			cout << "5) Multiply by matrix" << endl;
			cout << "6) Multiply with Adamar" << endl;
			cout << "7) Find a trace of the matrix" << endl;
			cout << "8) Find a determinate of the matrix" << endl;
			cout << "9) Scalar multiplication" << endl;
			cout << "10) Outer multiplication" << endl;
			cout << "11) Find a norm of the vector" << endl;
			cout << "12) Find a maximum norm of the vector" << endl;
			cout << "13) Find a norm of the matrix" << endl;
			cout << "14) Find an angle between vectors" << endl;
			cout << "15) Find a rank of the matrix" << endl;
			cout << "16) Find an invertible matrix" << endl;
			cout << "17) Transpose the matrix" << endl;
			cout << "18) Print the matrixes" << endl;
			cout << "19) Delete" << endl;
			cout << "20) Exit" << endl;
			cin >> w;
			//выполнение в зависимости от выбора
			switch (w)
			{
			case 1:
			{
				int way;
				//выбор типа матрицы
				cout << "Which matrix do you want to add?" << endl;
				cout << "1) Usual matrix" << endl;
				cout << "2) Elementary matrix" << endl;
				cout << "3) Diagonal matrix" << endl;
				cout << "4) Upper triangle matrix" << endl;
				cout << "5) Down triangle matrix" << endl;
				cout << "6) Simmetric matrix" << endl;
				cin >> way;
				//создание выбранного типа матрицы
				switch (way)
				{
					//создание обычной матрицы
				case 1:
				{
					int n, m;
					cout << "Input dimentions of your matrix" << endl;
					cin >> n >> m;
					Matrix M(n, m);
					cout << "Input numbers for your matrix" << endl;
					for (int i = 0; i < n; i++) 
					{
						for (int j = 0; j < m; j++)
						{
							cin >> M.Fill(i, j);
						}
					}
					MatrixArr.push_back(M);
					cout << "Result:" << endl;
					M.Out(0);
					break;
				}
				//создание единичной матрицы
				case 2:
				{
					int n;
					cout << "Input dimention of your matrix" << endl;
					cin >> n;
					Elementary M(n);
					MatrixArr.push_back(M);
					cout << "Result:" << endl;
					M.Out(0);
					break;
				}
				//создание диагональной матрицы
				case 3:
				{
					int n;
					cout << "Input dimention of your matrix" << endl;
					cin >> n;
					Diagonal M(n);
					cout << "Input numbers for your matrix" << endl;
					for (int i = 0; i < n; i++)
					{
						cin >> M.Fill(i, i);
					}
					MatrixArr.push_back(M);
					cout << "Result:" << endl;
					M.Out(0);
					break;
				}
				//создание верхнетреугольной матрицы
				case 4:
				{
					int n;
					cout << "Input dimention of your matrix" << endl;
					cin >> n;
					UpperTriang M(n);
					cout << "Input numbers for your matrix" << endl;
					for (int i = 0; i < n; i++)
					{
						for (int j = i; j < n; j++)
						{
							cin >> M.Fill(i, j);
						}
					}
					MatrixArr.push_back(M);
					cout << "Result:" << endl;
					M.Out(0);
					break;
				}
				//создание нижнетреугольной матрицы
				case 5:
				{
					int n;
					cout << "Input dimention of your matrix" << endl;
					cin >> n;
					DownTriang M(n);
					cout << "Input numbers for your matrix" << endl;
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j <= i; j++)
						{
							cin >> M.Fill(i, j);
						}
					}
					MatrixArr.push_back(M);
					cout << "Result:" << endl;
					M.Out(0);
					break;
				}
				//создание симметричной матрицы
				case 6:
				{
					int n;
					cout << "Input dimention of your matrix" << endl;
					cin >> n;
					Simmetric M(n);
					cout << "Input numbers for your matrix" << endl;
					for (int i = 0; i < n; i++)
					{
						for (int j = i; j < n; j++)
						{
							cin >> M.Fill(i, j);
							M.Fill(j, i) = M.Fill(i, j);
						}
					}
					MatrixArr.push_back(M);
					cout << "Result:" << endl;
					M.Out(0);
					break;
				}
				break;
				}
				break;
			}
			//сложение матриц
			case 2:
			{
				int a, b;
				if (MatrixArr.size() == 0 || MatrixArr.size() == 1)
					throw 0;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				cout << "Choose 2 matrixes that you want to summarize" << endl;
				cin >> a >> b;
				MatrixArr.at(a - 1) + MatrixArr.at(b - 1);
				cout << "Result:" << endl;
				MatrixArr.at(a - 1).Out(0);
				break;
			}
			//вычитание матриц
			case 3:
			{
				int a, b;
				if (MatrixArr.size() == 0 || MatrixArr.size() == 1)
					throw 0;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				cout << "Choose 2 matrix that you want to subtract" << endl;
				cin >> a >> b;
				MatrixArr.at(a - 1) - MatrixArr.at(b - 1);
				cout << "Result:" << endl;
				MatrixArr.at(a - 1).Out(0);
				break;
			}
			//умножение матрицы на число
			case 4:
			{
				int a;
				double b;
				if (MatrixArr.size() == 0)
					throw 0;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				cout << "Choose matrix that you want to multiply and by what number" << endl;;
				cin >> a >> b;
				MatrixArr.at(a - 1) * b;
				cout << "Result:" << endl;
				MatrixArr.at(a - 1).Out(0);
				break;
			}
			//умножение матриц
			case 5:
			{
				int a, b;
				Matrix M;
				if (MatrixArr.size() == 0 || MatrixArr.size() == 1)
					throw 0;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				cout << "Choose 2 matrixes that you want to multiply" << endl;;
				cin >> a >> b;
				M = MatrixArr.at(a - 1) * MatrixArr.at(b - 1);
				cout << "Result:" << endl;
				M.Out(0);
				break;
			}
			//произведение Адамара
			case 6:
			{
				int a, b;
				Matrix M;
				if (MatrixArr.size() == 0 || MatrixArr.size() == 1)
					throw 0;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				cout << "Choose 2 matrixes that you want to multiply with Adamar" << endl;
				cin >> a >> b;
				cout << "Result:" << endl;
				M = MatrixArr.at(a - 1).Adamar(MatrixArr.at(b - 1));
				M.Out(0);
				break;
			}
			//нахождение следа матрицы
			case 7:
			{
				int a;
				if (MatrixArr.size() == 0)
					throw 0;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				cout << "Choose matrix which trace you want to find" << endl;
				cin >> a;
				cout << "Trace: " << MatrixArr.at(a - 1).Trace() << endl;
				break;
			}
			//нахождение определителя методом Гаусса
			case 8:
			{
				int a;
				if (MatrixArr.size() == 0)
					throw 0;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				cout << "Choose matrix which determenate you want to find" << endl;
				cin >> a;
				cout << "Determinate: " << MatrixArr.at(a - 1).Determinate() << endl;
				break;
			}
			//скалярное умножение
			case 9:
			{
				int a, b;
				if (MatrixArr.size() == 0 || MatrixArr.size() == 1)
					throw 0;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				cout << "Choose vectors that you want to multiply" << endl;
				cin >> a >> b;
				cout << "Result: " << MatrixArr.at(a - 1).MultScal(MatrixArr.at(b - 1)) << endl;
				break;
			}
			//внешнее умножение
			case 10:
			{
				Matrix A1, A2;
				int a, b;
				if (MatrixArr.size() == 0 || MatrixArr.size() == 1)
					throw 0;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				cout << "Choose vectors that you want to multiply" << endl;
				cin >> a >> b;
				A1 = MatrixArr.at(a - 1).MultOut(MatrixArr.at(b - 1));
				cout << "The first vector multiplication: " << endl;
				A1.Out(0);
				A2 = MatrixArr.at(b - 1).MultOut(MatrixArr.at(a - 1));
				cout << "The second vector multiplication: " << endl;
				A2.Out(0);
				cout << "Outer multiplication: " << endl;
				A1 - A2;
				A1*0.5;
				A1.Out(0);
				break;
			}
			//Евклидова норма
			case 11:
			{
				int a;
				if (MatrixArr.size() == 0)
					throw 0;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				cout << "Choose vector which norm you want to find" << endl;
				cin >> a;
				cout << "Norm: " << MatrixArr.at(a - 1).EvNorm() << endl;
				break;
			}
			//максимальная норма
			case 12:
			{
				int a;
				if (MatrixArr.size() == 0)
					throw 0;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				cout << "Choose vector which norm you want to find" << endl;
				cin >> a;
				cout << "MaxNorm: " << MatrixArr.at(a - 1).MaxNorm() << endl;
				break;
			}
			//норма матрицы
			case 13:
			{
				int a;
				if (MatrixArr.size() == 0)
					throw 0;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				cout << "Choose matrix which norm you want to find" << endl;
				cin >> a;
				cout << "Matrix norm: " << MatrixArr.at(a - 1).FrobNorm() << endl;
				break;
			}
			//угол между векторами
			case 14:
			{
				int a, b;
				double ans;
				if (MatrixArr.size() == 0 || MatrixArr.size() == 1)
					throw 0;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				cout << "Choose vectors that you want to find an angle between" << endl;
				cin >> a >> b;
				cout << "Result: " << MatrixArr.at(a - 1).Angle(MatrixArr.at(b - 1)) << endl;
				break;
			}
			//ранг матрицы
			case 15:
			{
				int a;
				if (MatrixArr.size() == 0)
					throw 0;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				cout << "Choose matrix which rank you want to find" << endl;
				cin >> a;
				cout << "Rank: " << MatrixArr.at(a - 1).Rank() << endl;
				break;
			}
			//обратная матрица
			case 16:
			{
				int a;
				Matrix M;
				if (MatrixArr.size() == 0)
					throw 0;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				cout << "Choose matrix which invertible you want to find" << endl;
				cin >> a;
				M = MatrixArr.at(a - 1).InvertM();
				cout << "Invertible matrix: " << endl;
				M.Out(0);
				break;
			}
			//транспонирование матрицы
			case 17:
			{
				int a;
				Matrix M;
				if (MatrixArr.size() == 0)
					throw 0;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				cout << "Choose matrix that you want to transpose" << endl;
				cin >> a;
				cout << "Result: " << endl;
				M = MatrixArr.at(a - 1).Transpose();
				M.Out(0);
				break;
			}
			//вывод матриц на экран
			case 18:
			{
				if (MatrixArr.size() == 0)
					throw 0;
				for (int k = 0; k < MatrixArr.size(); k++)
				{
					cout << k + 1 << ") ";
					MatrixArr.at(k).Out(1);
				}
				break;
			}
			//удаление матриц
			case 19:
			{
				int j;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					MatrixArr[i].Out(1);
				}
				if (MatrixArr.size() == 0)
					throw 0;
				cout << "Choose matrix that you want to delete or '0' to go back to the menu" << endl;
				cin >> j;
				if (MatrixArr.size() == 1)
					MatrixArr.pop_back();
				else
				{
					if (j == 0)
						break;
					MatrixArr.erase(MatrixArr.begin() + j - 1);
				}
				break;
			}
			//выход
			case 20:
			{
				if (wf == 1)
				{
					ofstream f;
					f.open("matrix.txt");
					for (int i = 0; i < MatrixArr.size(); i++)
					{
						MatrixArr[i] >> f;
					}
					f.close();
				}
				if (wf == 2)
				{
					ofstream f;
					f.open("matrix.bin");
					for (int i = 0; i < MatrixArr.size(); i++)
					{
						MatrixArr[i].BinW(f);
					}
					f.close();
				}
				if (wf == 3)
				{
					ofstream f;
					f.open("matrix.txt", ios::trunc);
					for (int i = 0; i < MatrixArr.size(); i++)
					{
						MatrixArr[i] >> f;
					}
					f.close();
				}
				if (wf == 4)
				{
					ofstream f;
					f.open("matrix.bin");
					if (!f)
					{
						throw 13;
					}
					for (int i = 0; i < MatrixArr.size(); i++)
					{
						MatrixArr[i].BinW(f);
					}
					f.close();
				}
				return 0;
			}
			default:
			{
				cout << "Wrong choice" << endl;
				break;
			}
			}
		} while (w != 20);
	}
	//ошибки
	catch (int er)
	{
		if (er == 0)
			cout << "There are not enough matrixes" << endl;
		if (er == 1)
			cout << "Matrixes cannot be subtracted" << endl;
		if (er == 2)
			cout << "Matrixes cannot be summarized" << endl;
		if (er == 3)
			cout << "Matrixes cannot be multiplied" << endl;
		if (er == 4)
			cout << "Matrixes cannot be multiplied with Adamar" << endl;
		if (er == 5)
			cout << "Matrix cannot be created" << endl;
		if (er == 6)
			cout << "Matrix should be with different numbers" << endl;
		if (er == 7)
			cout << "Matrix is not square" << endl;
		if (er == 8)
			cout << "Vectors cannot be multiplied" << endl;
		if (er == 9)
			cout << "Norm cannot be found" << endl;
		if (er == 10)
			cout << "Angle cannot be found" << endl;
		if (er == 11)
			cout << "Invertible matrix cannot be found" << endl;
		if (er == 12)
			cout << "File cannot be created" << endl;
		if (er == 13)
			cout << "File cannot be opened" << endl;
	}
}
