#include <iostream>
using namespace std;


int main()
{
	int r, c;
	do{
		cout << "Enter the number of rows for the array: ";
		cin >> r;
		if (r < 1)
			cout << "Rows should be greater than equal to 1\n";
	} while (r < 1);

	do{
		cout << "Enter the number of columns for the array: ";
		cin >> c;
		if (c < 1)
			cout << "Columns should be greater than equal to 1\n";
	} while (c < 1);

	int** arr = new int*[r];

	for (int i = 0; i < r; i++)
	{
		arr[i] = new int[c];
	}


	for (int m = 0; m < r; m++)	
		for (int n = 0; n < c; n++)
			arr[m][n] = rand() % 100 + 1;
	
	for (int m = 0; m < r; m++)
	{
		for (int n = 0; n < c; n++)
			cout << arr[m][n] << " ";
		cout << endl;
	}
	cout << endl<<"Sum for the Rows: \n";
	//sum for rows
	for (int m = 0; m < r; m++)
	{
		int sum_r = 0;
		for (int n = 0; n < c; n++)
		{
			sum_r = sum_r + arr[m][n];
		}
		cout << "Sum for Row#" << m <<": "<< sum_r<<endl;
	}

	//sum for columns
	cout << endl << "Sum for the Columns: \n";
	for (int n = 0; n < c; n++)
	{
		int sum_c = 0;
		for (int m = 0; m < r; m++)
		{
			sum_c = sum_c + arr[m][n];
		}
		cout << "Sum for Column#" << n << ": " << sum_c << endl;
	}

	int lar = arr[0][0];
	int a, b, x=0, y=0;
	for (a = 0; a < r; a++)
	{
		for (b = 0; b < c; b++)
		{
			if (lar < arr[a][b])
			{
				lar = arr[a][b];
				x = a;
				y = b;
			}
				
		}
	}
	cout << "\n\nThe larges element in the Array is: " << lar << "\n At position: (" << x << ", " << y << ")"<<endl;

	for (int n = 0; n < c; n++)
		delete arr[n];
	delete[] arr;
	system("pause");
	return 0;
}
