#include<iostream>
using namespace std;

int** Test1()
{
	int** ptr = new int*[50];
		for (int i = 0; i < 50; i++)
		{
			ptr[i] = new int[50000000];
			cout << "Memory allocated.\n";
		}
		return ptr;
}
void Test2()
{

	int** ptr = Test1();

	
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50000000; j++)
			{
				cout<<ptr[i][j];
			}
			ptr[i] = new int[50000000];
			cout << "Memory allocated.\n";
		}
	
}
void main()
{
	
	Test2();
}