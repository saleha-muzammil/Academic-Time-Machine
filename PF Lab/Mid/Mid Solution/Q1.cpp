#include<iostream>
using namespace std;
int main()
{
	int num1 = 0, num2 = 0, i = 0, j = 0, rem = 0;
	bool flag = false;
	cout << "Enter an integer between 0 and 10 million: ";
	cin >> num1;
	cout << " Enter an integer of single digit: ";
	cin >> num2;
	for (i = 0; num1 != 0; i++)
	{
		rem = num1 % 10;
		num1 = num1 / 10;
		if (rem == num2)
		{
			flag = true;
			break;
		}
	}
	if (flag == true)
	{
		if (i == 0)
			cout << "Unit" << endl;
		if (i ==1)
			cout << "Tens" << endl;
		if (i == 2)
			cout << "Hundreds" << endl;
		if (i == 3)
			cout << "Thousands" << endl;
		if (i == 4)
			cout << "Ten Thousands" << endl;
		if (i == 5)
			cout << "Hundred Thousands" << endl;
		if (i == 6)
			cout << "Millions" << endl;
	
    }
	else
		cout << "Not Found" << endl;
	return 0;

	
}