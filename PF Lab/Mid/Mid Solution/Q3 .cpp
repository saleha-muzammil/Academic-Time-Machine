#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int arr[10] = { 0 }, i = 0, j = 0, k = 0, sum = 0;
	bool flag = false;
	cout << "Enter 10 integers in array: " << endl;
	for (i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	cout << "Enter a number K: " << endl;
	cin >> k;
	for (i = 0; i < 10; i++)
	{
		sum = 0;
		for (j = i; j < 10; j++)
		{

			sum = sum + arr[j];
			if (sum == k)
			{
				flag = true;
				cout <<"Array from index "<<i << " to index " << j << endl;
				break;
			}
			
		}
		if (flag == true)
			break;
	}
	if (flag == false)
		cout << "Not found" << endl;


	_getch();
	return 0;










}