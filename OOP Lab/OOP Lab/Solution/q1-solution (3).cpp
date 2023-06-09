#include <iostream>
using namespace std;

int **Input(int &r, int &c)
{

	int** array1 = new int*[r];
	for (int i = 0; i < r; i++)					//DeclaratioN
	{

		*(array1 + i) = new int[c];
	}

	//Inputing Values:-
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << "Enter ELEMENT of (" << i << "," << j << ")=";
			cin >> *(*(array1 + i) + j);
		}
	}
	return array1;
}
void output(int **matrix, int &r, int &c)
{

	//PRINTING CODE:-
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << *(*(matrix + i) + j) << "	";
		}
		cout << "\n";
	}
}
int avg(int **arr1, int I, int J)
{

	int sum = 0;
	
	for (int i = I; i <= I + 2; i++)
	{

		for (int j = J; j <= J + 2; j++)
			sum += *(*(arr1 + i) + j);
	}
	return sum / 9;
}
int **compress(int **input, int rows, int cols)
{

	int** array1 = new int*[rows - 2];
	for (int i = 0; i < rows - 2; i++)					//Declaration of Array Compressed
	{

		*(array1 + i) = new int[cols - 2];
	}

	//populating COMPRESSED ARRAY:
	for (int i = 0; i < rows - 2; i++)
	{

		for (int j = 0; j < cols - 2; j++)
		{

			*(*(array1 + i) + j) = avg(input, i, j);
		}
	}
	return array1;
}




void deallocate(int **matrix, int r)
{

	for (int i = 0; i < r; i++)
		delete[] matrix[i];
	delete[] matrix;
}
//Q1
int main()
{


	int row = 3;
	int col = 4;
	int **arr = Input(row, col);
	output(arr, row, col);
	int** Compressed_Array = compress(arr, row, col);
	int crow = row - 2;
	int ccol = col - 2;
	cout << "Compressed-Array:-\n";
	output(Compressed_Array, crow, ccol);

	cout << "deallocation:\n";
	cout << "Free MEMORY original array=\n";
	deallocate(arr, row);
	cout << "Free MEMORY COMPRESSED-ARRAY=\n";
	deallocate(Compressed_Array, crow);

	system("pause");

	return 0;
}