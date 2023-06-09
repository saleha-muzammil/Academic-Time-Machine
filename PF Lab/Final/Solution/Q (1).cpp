#include <iostream>
using namespace std;
int main()
{	
	char *data;
	data = new char[100];
	cout << "Enter you data=";
	cin.getline(data,99);
	int size = 0;
	for (int i = 0; data[i] != '\0';i++)
	{
		size++;
	}
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + (data[i] - 48);
	}
	cout << "Sum of single digits =" << sum;

	system("pause");
}