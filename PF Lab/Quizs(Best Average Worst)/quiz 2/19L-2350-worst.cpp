#include <iostream>
using namespace std;
void Union(int arr1[], int arr2[], int m, int n)
{
	int counter = 0, counter1 = 0;
	while (counter  < m ||counter 1 < n)
	{
		if (arr1[counter ] < arr2[counter1])
			cout << arr1[counter++];
		else if (arr2[counter1] < arr1[counter ])
			cout << arr2[counter1++];
		else
		{
			cout << arr2[counter1++];
			counter++;
		}
	}
	while (counter < m)
	{	
		cout << arr1[counter++];
	}	
	while (counter1< n)
	{
		cout << arr2[counter1++];
	}
}

int main()
{
	int arr1[5] = { 1, 2, 4, 5, 6 };
	int arr2[4] = { 2, 3, 5, 7 };


	Union(arr1, arr2, 5, 4);

	return 0;
}