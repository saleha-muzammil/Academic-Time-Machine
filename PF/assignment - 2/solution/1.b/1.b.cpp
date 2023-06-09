#include <iostream>                      
#include <fstream>                        // library for file input and output
using namespace std;
int main()
{
	int data1;                             // first number
	int data2;                             // second number
	ifstream file;                         // initialize file
	file.open("pair.txt");                 // file from whwre use data1 and data2
	if (file.is_open() == true)           // use check if file is open then execute next otherwise terminates the program after showing some message like "Error"
	{
		while (file.eof() == false)       // use loop til file is not end
		{
			file >> data1 >> data2;       // Take data from the file and the execute next 

			int sum1 = 0;
			if (data1 > 0 && data1 < 2147483647)  //boundry check for the first number
			{
				for (int i = 1; i <= data1 / 2; i++)  // use loop to find the factors of the given first number till the half of that number
				{
					if (data1 % i == 0)               //  use this 'if' to check modulus of given number with 1
					{
						sum1 = sum1 + i;              // sum of all the factors of given first number
					}
				}
			}
			int sum2 = 0;
			if (data2 > 0 && data2 < 2147483647)     // boundry check for the second number
			{
				for (int i = 1; i <= data2 / 2; i++) // use loop to find the factors of the given second number till the half of that number
				{
					if (data2 % i == 0)              //  use this 'if' to check modulus of given number with 1
					{
						sum2 = sum2 + i;             // sum of all the factors of given second number
					}
				}
			}
			if (sum1 == data2 && sum2 == data1)      // use this statement whether the given numbers are amicable or not
			{
				cout << "Is the pair " << data1 << "  " << data2 << " amicable ?" << "  Yes" << endl;
			}
			else
			{
				cout << "Is the pair " << data1 << "  " << data2 << " amicable ?" << "  No" << endl;
			}
			cout << endl;
		}
		file.close();                                  // file open above and close here
	}
	else
	{
		cout << "ERROR...!!! File not opened...\n";    // show this message if file is not opened
	}
	cout << endl;
	system("pause");
	return 0;
}