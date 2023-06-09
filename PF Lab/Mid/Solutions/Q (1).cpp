#include<iostream>
using namespace std;

void basic(int num)
{
	if (num == 1)
	{
		cout << "One \n";
	}
	if (num == 2)
	{
		cout << "two \n";
	}
	if (num == 3)
	{
		cout << "three \n";
	}
	if (num == 4)
	{
		cout << "four \n";
	}
	if (num == 5)
	{
		cout << "five \n";
	}
	if (num == 6)
	{
		cout << "six \n";
	}
	if (num == 7)
	{
		cout << "seven \n";
	}
	if (num == 8)
	{
		cout << "eight \n";
	}
	if (num == 9)
	{
		cout << "nine \n";
	}
	if (num == 10)
	{
		cout << "ten \n";
	}
	if (num == 11)
	{
		cout << "eleven \n";
	}
	if (num == 12)
	{
		cout << "twelve \n";
	}
	if (num == 13)
	{
		cout << "thirteen \n";
	}
	if (num == 14)
	{
		cout << "fourteen \n";
	}
	if (num == 15)
	{
		cout << "fifteen \n";
	}
	if (num == 16)
	{
		cout << "sixteen \n";
	}
	if (num == 17)
	{
		cout << "seventeen \n";
	}
	if (num == 18)
	{
		cout << "eighteen \n";
	}
	if (num == 19)
	{
		cout << "ninteen \n";
	}

}
void forDivide(int num)
{
	if (num == 2)
	{
		cout << "twenty ";
	}
	if (num == 3)
	{
		cout << "thirty ";
	}
	if (num == 4)
	{
		cout << "fourty ";
	}
	if (num == 5)
	{
		cout << "fifty ";
	}
	if (num == 6)
	{
		cout << "sixty ";
	}
	if (num == 7)
	{
		cout << "seventy ";
	}
	if (num == 8)
	{
		cout << "eighty ";
	}
	if (num == 9)
	{
		cout << "ninety ";
	}

}
int main()
{
	int number , divide=0 , mod=0;
	
	cout << "Input a Number between 1 and 100 \n";
	
	cin >> number;

	if (number == 100)
	{
		cout << "Hundred \n";
	}

	divide = number / 10;
	mod = number % 10;

	if (number < 20)
	{
		basic(number);
	}
	else if (divide < 10 && mod < 10)
	{
		forDivide(divide);
		basic(mod);

	}

	system("pause");
	return 0;

}
