#include <iostream>
using namespace std;
void Union(int arr1[], int arr2[], int m, int n)
{
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		if (arr1[i] < arr2[j])
			cout << arr1[i++] << ",";
		else if (arr2[j] < arr1[i])
			cout << arr2[j++] << ",";
		else
			cout << arr2[j++] << ",";
			i++;
	}

}

void main()
{
	int arr1[5] = { 1, 2, 4, 5, 6 };
	int arr2[4] = { 2, 3, 5, 7 };

	Union(arr1, arr2, 5, 4);

}