#include <iostream>
#include <fstream>
using namespace std;



int main()
{
	int size , sum = 0,faulty = 0;
	cout << "Input size of the string : ";
	cin >> size;
	char *c1 = new char[size];
	cout << "Enter the input : ";
	cin >> c1;
	for(int x = 0 ; c1[x] != '\0' && faulty == 0 ; x++)
	{
		if(c1[x] == '1')
			sum++;
		else if (c1[x] == '2')
			sum +=2;
		else if (c1[x] == '3')
			sum +=3;
		else if (c1[x] == '4')
			sum +=4;
		else if (c1[x] == '5')
			sum +=5;
		else if (c1[x] == '6')
			sum +=6;
		else if (c1[x] == '7')
			sum +=7;
		else if (c1[x] == '8')
			sum +=8;
		else if (c1[x] == '9')
			sum +=9;
		else if (c1[x] == '0')
			sum = sum;
		else 
		{
			cout << "Faulty Input. Please restart" << endl;
			faulty = 1;
		}
	}
	if (faulty != 1)
		cout << "Sum of the single digits = " << sum << endl;
	return 0;
}
