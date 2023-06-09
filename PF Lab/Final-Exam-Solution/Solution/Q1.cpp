#include<iostream>
#include<cstring>
#include<ctime>
#include<conio.h>
using namespace std;
int main()
{
	char numbers[200];
	int replacementarray[200];
	int sum = 0;
	int range;
	cout << "Enter range of numbers: ";
	cin >> range;
	for (int i = 0;i < range;i++)
		cin >> numbers[i];
	for (int i = 0;i < range;i++)
		replacementarray[i] = numbers[i]-48;
	for (int i = 0;i < range;i++)
		sum = sum + replacementarray[i];
	cout <<"Sum of the single digits = "<< sum;
	_getch();
}