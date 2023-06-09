#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int n1 = 0, n2 = 0;
	ifstream fin1;
	ifstream fin2;
	ofstream merge_file("C.txt");
	fin1.open("A.txt");
	fin2.open("B.txt");
	if (fin1.is_open() == true && fin2.is_open() == true)     // use this check whether the given files open or not
	{
		fin1 >> n1;  
		fin2 >> n2;                                   // store first number of both files to check whether the number is greater or not
		while (fin1.eof() == false || fin2.eof() == false)      // loop run untill the file terminates
		{

			if (n1 > n2)                        // if n1 is greater then store in the merge file and then again take value from file
			{
				merge_file << n1 << endl;
				fin1 >> n1;
			}
			if (n2 == n1)                       // if n1 amd n2 are equal then store both numnbers in the merge file
			{
				merge_file << n2 << endl;
				merge_file << n1 << endl;
				fin2 >> n2;
				fin1 >> n1;
				merge_file << n2 << endl;
				merge_file << n1 << endl;
			}
			if (n2 > n1)                        // if n2 is greater then store in the merge file and then again take value from file
			{
				merge_file << n2 << endl;
				fin2 >> n2;
			}
			if (fin1.eof() == true)            // use this check if file 1 end then store remaining digits in the merge file
			{
				while (fin2.eof() == false)
				{
					fin2 >> n2;
					merge_file << n2 << endl;
				}
			}
		}
		fin1.close();
		fin2.close();
		merge_file.close();                      // close all files which are opened earlier
	}
	else
	{
		cout << "Error !!!!!!! ..... File not opened" << endl;      // messsage shows only if input files are not opened
	}
	cout << "Digits of 'A.txt' and 'B.txt' stored successfuly in 'C.txt' in descending order" << endl << endl;
	system("pause");
	return 0;
}
