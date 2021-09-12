#include "help.h"
#include <fstream>
int main()
{
	vector <Matrix> MatrixArr;
	try
	{
			Matrix A;
			PCA PCA;
			ifstream f;
			f.open("data.txt");
			if (!f)
			{
				throw 13;
			}
			cout << "File named data.txt has been opened" << endl;
			//чтение из файла
			while (f)
			{
				MatrixArr.push_back(A << f);
			}
			MatrixArr.pop_back();
			f.close();
			if (MatrixArr.size() == 0)
				throw 0;
			//вызов алгоритма NIPALS
			PCA.NIPALS(MatrixArr[0]);
			ifstream ft;
			ft.open("scores.txt");
			if (!ft)
			{
				throw 13;
			}
			while (ft)
			{
				MatrixArr.push_back(A << ft);
			}
			MatrixArr.pop_back();
			ft.close();
			//PCA.Leverage(MatrixArr[1]);
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
