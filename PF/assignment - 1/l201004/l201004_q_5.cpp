//Converts a number from 1 to 999 to its name.
#include <iostream>
using namespace std;

int main()
{
	int number = 0;
	int first, second, third;
	int rest;
	cout << "Number: ";
	cin >> number;
//Checks boundary values.
	if (number <= 0 || number > 999)
	{
		cout << "Error: This number is out of range! ";
		return 1;
	}
	else
	{
		first = number / 100;
		rest = number % 100;
		second = rest / 10;
		third = rest % 10;
		switch (first)
		{
		case 0:
			break;
		case 1:
			cout << "One Hundred ";
			break;
		case 2:
			cout << "Two Hundred ";
			break;
		case 3:
			cout << "Three Hundred ";
			break;
		case 4:
			cout << "Four Hundred ";
			break;
		case 5:
			cout << "Five Hundred ";
			break;
		case 6:
			cout << "Six Hundred ";
			break;
		case 7:
			cout << "Seven Hundred ";
			break;
		case 8:
			cout << "Eight Hundred ";
			break;
		case 9:
			cout << "Nine Hundred ";
			break;
		}
		if (second != 1)
		{
			switch (second)
			{
			case 0:
				break;
			case 2:
				cout << "Twenty ";
				break;
			case 3:
				cout << "Thirty ";
				break;
			case 4:
				cout << "Forty ";
				break;
			case 5:
				cout << "Fifty ";
				break;
			case 6:
				cout << "Sixty ";
				break;
			case 7:
				cout << "Seventy ";
				break;
			case 8:
				cout << "Eighty ";
				break;
			case 9:
				cout << "Ninety ";
				break;
			}
			switch (third)
			{
			case 1:
				cout << "One";
				break;
			case 2:
				cout << "Two ";
				break;
			case 3:
				cout << "Three ";
				break;
			case 4:
				cout << "Four ";
				break;
			case 5:
				cout << "Five ";
				break;
			case 6:
				cout << "Six ";
				break;
			case 7:
				cout << "Seven ";
				break;
			case 8:
				cout << "Eight ";
				break;
			case 9:
				cout << "Nine ";
				break;
			}
		}

		else
		{
			if (third == 0)
				cout << "Ten";
			if (third == 1)
				cout << "Eleven";
			if (third == 2)
				cout << "Twelve";
			if (third == 3)
				cout << "Thirteen";
			if (third == 4)
				cout << "Fourteen";
			if (third == 5)
				cout << "Fifteen";
			if (third == 6)
				cout << "Sixteen";
			if (third == 7)
				cout << "Seventeen";
			if (third == 8)
				cout << "Eighteen";
			if (third == 9)
				cout << "Ninteen";

		}
		return 0;
	}
}