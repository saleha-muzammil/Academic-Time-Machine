#include <iostream>
using namespace std;
int main()
{
     int temp, number1, fasctor, rev = 0;
     cout << "Enter a positive number: ";
     cin >> number1;
     temp = number1;
     while (number1 != 0)
     {
         fasctor = number1 % 10;
         rev = (rev * 10) + fasctor;
         number1 = number1 / 10;
     } 
     if (temp == rev)
         cout << " The number is a palindrome.\n";
     else
         cout << " The number is not a palindrome.\n";
	 system("pause");

    return 0;
}