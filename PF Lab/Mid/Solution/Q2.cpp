#include <iostream>
#include <fstream>
using namespace std;
void rotateRight(int array[], int array_size, int rotateSize)
{
	ifstream fin;
	fin.open("Input.txt");   // File Opened
	if (fin)
	{
		cout << "Input:" << endl<<endl;
		for (int i = 0; i < array_size&&!fin.eof(); i++)
		{
			
			fin >> array[i];
			cout << array[i];
		}
		cout << endl<<endl<<endl;
		cout << "Output:" << endl<<endl;
		int array2[15];
		for (int k = 0,j=14; k < rotateSize; k++,j--)
		{
			array2[k] = array[j];
			for (int a = k + 1,b=0; a < 15&&b<j; a++,b++)
				array2[a] = array[b];
		}
		for (int i = 0; i < 15; i++)
			cout << array2[i];
		cout << endl << endl;
	}
	fin.close();        //File closed
}
int main()
{
	int s = 15;
	int myarray[15];
	int a = 0;
	cout << "Enter the rotate size:";
	cin >> a;
	rotateRight(myarray, s, a);
	

	return 0;
}