#include "help.h"
int main()
{
	int w;
	int signal = 0;
	vector <Matrix> MatrixArr;
	//меню для выбора функций
	do {
		cout << "What do you want ot do?" << endl;
		cout << "1) Add new matrix" << endl;
		cout << "2) Summarize" << endl;
		cout << "3) Subtract" << endl;
		cout << "4) Multiply by number" << endl;
		cout << "5) Multiply by matrix" << endl;
		cout << "6) Multiply with Adamar" << endl;
		cout << "7) Print matrixes" << endl;
		cout << "8) Delete" << endl;
		cout << "9) Clear console" << endl;//зачем?
		cout << "10) Exit" << endl;
		cin >> w;
		//выполнение в зависимости от выбора
		try {
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
					cout << "Input dimentions of your matrix"<<endl;
					cin >> n >> m;
					Matrix M(n, m);
					cout << "Input numbers for your matrix" << endl;
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++)
						{
							cin >> M.Fill(i, j);
						}
					}
					MatrixArr.push_back(M);
					break;
				}
				//создание единичной матрицы
				case 2:
				{
					int n;
					cout << "Input dimention of your matrix"<<endl;
					cin >> n;
					Elementary M(n);
					MatrixArr.push_back(M);
					break;
				}
				//создание диагональной матрицы
				case 3:
				{
					int n;
					cout << "Input dimention of your matrix"<<endl;
					cin >> n;
					Diagonal M(n);
					cout << "Input numbers for your matrix" << endl;
					for (int i = 0; i < n; i++)
					{
						cin >> M.Fill(i, i);
					}
					MatrixArr.push_back(M);
					break;
				}
				//создание верхнетреугольной матрицы
				case 4:
				{
					int n;
					cout << "Input dimention of your matrix"<<endl;
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
					break;
				}
				//создание нижнетреугольной матрицы
				case 5:
				{
					int n;
					cout << "Input dimention of your matrix"<<endl;
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
					break;
				}
				//создание симметричной матрицы
				case 6:
				{
					int n;
					cout << "Input dimention of your matrix"<<endl;
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
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					signal = 1;
					MatrixArr[i].Out(signal);
				}
				if (MatrixArr.size() == 0 || MatrixArr.size() == 1)
					throw 0;
				cout << "Choose 2 matrixes that you want to summarize" << endl;
				cin >> a >> b;
				MatrixArr.at(a - 1) + MatrixArr.at(b - 1);
				signal = 0;
				cout << "Result:" << endl;
				MatrixArr.at(a-1).Out(signal);
				break;
			}
			//вычитание матриц
			case 3: 
			{
				int a, b;
				for (int i = 0; i < MatrixArr.size(); i++)
				{
					cout << i + 1 << ") ";
					signal = 1;
					MatrixArr[i].Out(signal);
				}
				if (MatrixArr.size() == 0 || MatrixArr.size() == 1)
					throw 0;
				cout << "Choose 2 matrix that you want to subtract"<<endl;
				cin >> a >> b;
				MatrixArr.at(a - 1) - MatrixArr.at(b - 1);
				signal = 0;
				cout << "Result:" << endl;
				MatrixArr.at(a - 1).Out(signal);
				break;
			}
			//умножение матрицы на число
			case 4: 
			{
				int a;
				double b;
				for (int i = 0; i < MatrixArr.size(); i++) 
				{
					cout << i + 1 << ") ";
					signal = 1;
					MatrixArr[i].Out(signal);
				}
				if (MatrixArr.size() == 0)
					throw 0;
				cout << "Choose matrix that you want to multiply and by what number" << endl;;
				cin >> a >> b;
				MatrixArr.at(a - 1) * b;
				signal = 0;
				cout << "Result:" << endl;
				MatrixArr.at(a - 1).Out(signal);
				break;
			}
			//умножение матриц
			case 5: 
			{
				int a, b;
				for (int i = 0; i < MatrixArr.size(); i++) 
				{
					cout << i + 1 << ") ";
					signal = 1;
					MatrixArr[i].Out(signal);
				}
				if (MatrixArr.size() == 0 || MatrixArr.size() == 1)
					throw 0;
				cout << "Choose 2 matrixes that you want to multiply" << endl;;
				cin >> a >> b;
				MatrixArr.push_back(MatrixArr.at(a - 1) * MatrixArr.at(b - 1));
				signal = 0;
				break;
			}
			//произведение Адамара
			case 6:
			{
				int a, b;
				for (int i = 0; i < MatrixArr.size(); i++) 
				{
					cout << i + 1 << ") ";
					signal = 1;
					MatrixArr[i].Out(signal);
				}
				if (MatrixArr.size() == 0 || MatrixArr.size() == 1)
					throw 0;
				cout << "Choose 2 matrixes that you want to multiply with Adamar"<<endl;
				cin >> a >> b;
				MatrixArr.push_back(MatrixArr.at(a - 1).Adamar(MatrixArr.at(b - 1)));
				signal = 0;
				break;
			}
			//вывод матриц на экран
			case 7: 
			{
				if (MatrixArr.size() == 0)
					throw 0;
				for (int k = 0; k < MatrixArr.size(); k++)
				{
					cout << k + 1 << ") ";
					signal = 1;
					MatrixArr.at(k).Out(signal);
				}
				signal = 0;
				break;
			}
			//удаление матриц
			case 8: 
			{
				int j;
				for (int i = 0; i < MatrixArr.size(); i++) 
				{
					cout << i + 1 << ") ";
					signal = 1;
					MatrixArr[i].Out(signal);
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
				signal = 0;
				break;
			}
			//очищение консоли
			case 9: 
			{
				break;
			}
			//выход
			case 10: 
			{
				return 0;
			}
			}
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
		}
	} while (w!= 10);
}
