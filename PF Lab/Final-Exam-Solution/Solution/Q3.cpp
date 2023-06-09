#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
bool findsubstr(char* arr1,int size1, char* arr2,int size2)
{
	bool flag = false;
	int comp = 0;
	for (char* temp = arr1;temp < (arr1 + size1)&&flag==false;temp++)
	{
		char* temp1 = temp;
		for (char* temp2=arr2;temp2 < (arr2+size2);*temp1++,temp2++)
		{
			if (*temp1 == *temp2)
			{
				comp++;
			}
		}
		if (comp == size2)
			flag = true;
	}
	return flag;
}
int main()
{
	char* str1;
	char* str2;
	int st1, st2;
	bool flag;
	cout << "Enter size of first string: ";
	cin >> st1;
	str1 = new char[st1];
	cout << "Enter a sentence.\n";
	for (int i = 0;i < st1;i++)                           //take inputs using space
		cin >> str1[i];
	cout << "Enter size of second string: ";
	cin >> st2;
	str2 = new char[st2];
	cout << "Enter a sentence.\n";                      //take inputs using space
	for (int i = 0;i < st2;i++)
		cin >> str2[i];
	flag = findsubstr(str1, st1, str2, st2);
	if (flag == true)
		cout << "Second array is a substring of the first array.";
	else 
		cout<< "Second array is not a substring of the first array.";
	delete [] str1;
	delete [] str2;
	_getch();
}