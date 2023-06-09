//Converts Hexadecimals to Binary.
#include <iostream>
using  namespace std;

int main()
{
	char digit_1;
	char digit_2;
	cout << "HEX digit # 1: ";
	cin >> digit_1;
	cout << "HEX digit # 2: ";
	cin >> digit_2;	
//Doesn't let invalid values pass.	
	if ((((int)digit_1 > 47 && (int)digit_1 < 58) || ((int)digit_1 < 71 && (int)digit_1 > 64) || ((int)digit_1 > 96 && (int)digit_1 < 103)) &&
		(((int)digit_2 > 47 && (int)digit_2 < 58) || ((int)digit_2 < 71 && (int)digit_2 > 64) || ((int)digit_2 > 96 && (int)digit_2 < 103)))
	{
		cout << "Binary equivalent to " << digit_1 << digit_2 << " is: ";
		switch (digit_1)
		{
		case '0':
			cout << "0000";
			break;
		case '1':
			cout << "0001";
			break;
		case '2':
			cout << "0010";
			break;
		case '3':
			cout << "0011";
			break;
		case '4':
			cout << "0100";
			break;
		case '5':
			cout << "0101";
			break;
		case '6':
			cout << "0110";
			break;
		case '7':
			cout << "0111";
			break;
		case '8':
			cout << "1000";
			break;
		case '9':
			cout << "1001";
			break;
		case 'A':
		case'a':
			cout << "1010";
			break;
		case 'B':
		case 'b':
			cout << "1011";
			break;
		case 'C':
		case 'c':
			cout << "1100";
			break;
		case 'D':
		case 'd':
			cout << "1101";
			break;
		case 'E':
		case 'e':
			cout << "1110";
			break;
		case 'F':
		case 'f':
			cout << "1111";
			break;
		}
		switch (digit_2)
		{
		case '0':
			cout << "0000";
			break;
		case '1':
			cout << "0001";
			break;
		case '2':
			cout << "0010";
			break;
		case '3':
			cout << "0011";
			break;
		case '4':
			cout << "0100";
			break;
		case '5':
			cout << "0101";
			break;
		case '6':
			cout << "0110";
			break;
		case '7':
			cout << "0111";
			break;
		case '8':
			cout << "1000";
			break;
		case '9':
			cout << "1001";
			break;
		case 'A':
		case'a':
			cout << "1010";
			break;
		case 'B':
		case 'b':
			cout << "1011";
			break;
		case 'C':
		case 'c':
			cout << "1100";
			break;
		case 'D':
		case 'd':
			cout << "1101";
			break;
		case 'E':
		case 'e':
			cout << "1110";
			break;
		case 'F':
		case 'f':
			cout << "1111";
			break;
		}
		return 0;
	}
	else
	{
		cout << "Oops! You have entered a digit which doesn't exist in hexadecimal system!\n";
		return 1;
	}
}
