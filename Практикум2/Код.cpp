#include<iostream>
#include<array>
#include<cctype>
#include<string>
using namespace std;
class Exeption
{

};
template<class Q, int N>
class Queue
{
	//template <typename U>
		//friend ostream& operator <<(ostream& o, const Queue<U>& a);
public:
	Q* arr = new Q[N];
	int i = 0, j = 0;
	void insert(Q q)
	{
		i++;
		if (i > N)
		{
			throw Exeption();
		}
		arr[i - 1] = q;
		cout << arr[i - 1] << endl;
	}
	void get(int pos)
	{
		int k;
		j++;
		cout << "get=" << arr[pos] << endl;;
		for ( k = pos; k < N - j; k++)
		{
			arr[k] = arr[k + 1];
		}
		cout << "Array after get" << endl;
		for (k = 0; k < N - j; k++)
		{
			cout << arr[k] << endl;
		}
	}
};
int main()
{
	Queue<int,5>qi;
	try
	{
		for (int i = 0; i < 5;i++)
		{
			qi.insert(i);
		}
		qi.get(0);
	}
	catch (Exeption)
	{
		cout << "too much people in the queue" << endl;
	}
	return 0;
}
