#include <iostream>
using namespace std;
int main()
{
	int run_program;
	do
	{
		cout << "           *******************************        " << endl;
		cout << "           *******************************        " << endl;
		int num1;
		int sum1 = 0;
		cout << "Enter first number between 0 and 2147483647 otherwise terminates the program" << endl << endl;
		cout << "Enter the first number   :  ";
		cin >> num1;                              // first number
		if (num1 > 0 && num1 < 2147483647)        // boundry check for first number
		{
			cout << "Factors of " << num1 << " are : [ ";
			for (int i = 1; i <= num1 / 2; i++)   // loop used to find the factors of given first number till the half of that number
			{
				if (num1 % i == 0)                // if is used to check the whether the modulus of given number with i is zero or not
				{
					cout << i << " ";
					sum1 = sum1 + i;               // sum of all factors of first number
				}
			}
			cout << "]" << endl;
			cout << endl;
		}
		else
		{
			cout << "Please run again program and enter a number between 0 and 2147483647 ." << endl; 
			system("pause");                       // terminates program if first number is out of range
			return 0;
		}
		cout << "           *******************************        " << endl;
		int num2;
		int sum2 = 0;
		cout << "Enter second number between 0 and 2147483647 otherwise terminates the program" << endl << endl;
		cout << "Enter the second number  :  ";
		cin >> num2;                              // second number
		if (num2 > 0 && num2 < 2147483647)        // boundry check for first number
		{
			cout << "Factors of " << num2 << " are : [ ";
			for (int i = 1; i <= num2 / 2; i++)  // loop used to find the factors of given second number till the half of that number
			{
				if (num2 % i == 0)               // if is used to check the whether the modulus of given number with i is zero or not
				{
					cout << i << " ";
					sum2 = sum2 + i;             // sum of all factors of first number
				}
			}
			cout << "]" << endl;
			cout << endl;
		}
		else
		{
			cout << "Please run again program and enter a number between 0 and 2147483647 ." << endl;
			system("pause");                     // terminates program if first number is out of range
			return 0;
		}
		if (sum1 == num2 && sum2 == num1)       // This statement is used to check whether the given numbers are amicable or not
		{
			cout << "The " << num1 << " and " << num2 << " are amicable numbers." << endl;
		}
		else
		{
			cout << "The " << num1 << " and " << num2 << " are not amicable numbers." << endl;
		}
		cout << endl;
		cout << "Do you want to run the program again (Enter '1' run again and '0' for terminates the program )" << endl;
		cin >> run_program;                    
		cout << endl << endl;
	} while (run_program == 1);                // this loop is used to ask from the user whether you take input again or not
	cout << endl;
	system("pause");
	return 0;
}