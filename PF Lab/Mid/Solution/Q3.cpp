#include <iostream>
using namespace std;
bool binarysearch(int val, int arr[])         //I have used Binary Search function.
{
	int size = 10, low = 0, high = size - 1;
	int mid = 0;
	bool check = false;
	while (check == false && low <= high)
	{
		mid = (high + low) / 2;
		if (val == arr[mid])
			check = true;
		else if (val > arr[mid])
			low = mid + 1;
		else if (val < arr[mid])
			high = mid - 1;
	}
	return check;
}
int main()
{
	int arr1[10] = { 1,3,6,9,10,11,12,13,15,20 };//First array
	cout << "A1 : 1 3 6 9 10 11 12 13 15 20" << endl<<endl;
	int arr2[10] = { 2,3,10,12,14,15,18,20,21,22 };//Second array
	cout << "A2 : 2 3 10 12 14 15 18 20 21 22" << endl<<endl;
	cout << "Output:" << endl<<endl;
	cout << "A3 : ";
	int arr3[10] = { 0 };//Third Array
	int x = 0;
	bool check = true;
	for (int i = 0,k=0; i < 10; i++)
	{
		x = arr1[i];
		check = binarysearch(x, arr2);//Binary Search Function is used here.
		if (check == false)
		{
			arr3[k] = arr1[i];
			cout << arr3[k]<<" " ;
			k++;
		}
	}
	cout << endl<<endl;
	return 0;
}
