#include<iostream>
#include<conio.h>
using namespace std;
void drawhotel(int arr[8][6],int rows, int col)
{
	for (int i = 0;i < rows;i++)
	{
		cout << "Floor" << i + 1<<"\t";
		for (int j = 0;j < col;j++)
		{
			if (arr[i][j] == 0)
				cout << "*\t";
			else
				cout << "X\t";
		}
		cout << endl;
	}
}
bool Firstclass_vacancy(int arr[8][6], int rows, int col,int parameter)
{
	bool flag = false;
	for (int i = 0;i < rows&&flag == false;i++)
	{
		for (int j = 0;j < col&&flag == false;j++)
		{
			if (arr[i][j] == 0)
			{
				arr[i][j] = parameter;
				flag = true;
			}
		}
	}
	return flag;
}
bool Secondclass_vacancy_nonsmoking(int arr[8][6], int rows, int col, int parameter)
{
	bool flag = false;
	for (int i = rows;i <= 4&&flag == false;i++)
	{
		for (int j = 0;j < col&&flag == false;j++)
		{
			if (arr[i][j] == 0)
			{
				arr[i][j] = parameter;
				flag = true;
			}
		}
	}
	return flag;
}
bool Secondclass_vacancy_smoking(int arr[8][6], int rows, int col, int parameter)
{
	bool flag = false;
	for (int i = rows;i <= 7&&flag == false;i++)
	{
		for (int j = 0;j < col&&flag == false;j++)
		{
			if (arr[i][j] == 0)
			{
				arr[i][j] = parameter;
				flag = true;
			}
		}
	}
	return flag;
}
int main()
{
	int hotel[8][6] = { 0 };
	int n = 0,clas=0,smoker=0;
	while (clas != -1 || smoker != -1 )
	{
		cout << "Please press 1 for fist class and 2 for economy class and press -1 to exit: ";
		cin >> clas;
		if (clas == -1)
			break;
		cout << "Please press 3 for non-smoking zone and 4 for smoking zone and press -1 to exit: ";
		cin >> smoker;
		if (smoker == -1)
			break;
		cout << "Press -1 to exit reservation.\n";
		if (clas == 1 && smoker == 3)
		{
			if (!Firstclass_vacancy(hotel, 2, 6, clas))
			{
				cout << "No vacancy available.\n";
			}
			cout << endl;
			drawhotel(hotel, 8, 6);
		}
		else if (clas == 1 && smoker == 4)
			cout << "No vacancy avaialbe.\n";
		else if (clas == 2 && smoker == 3)
		{
			if (!Secondclass_vacancy_nonsmoking(hotel, 2, 6, clas))
				cout << "No vacancy available.\n";
			cout << endl;
			drawhotel(hotel, 8, 6);
		}
		else if (clas == 2 && smoker == 4)
		{
			if (!Secondclass_vacancy_smoking(hotel, 5, 6, clas))
				cout << "No vacancy available.\n";
			cout << endl;
			drawhotel(hotel, 8, 6);
		}
		else
			cout << "No vacancy available";
		cout << endl;
		cout << "Press any key to continue.";
		_getch();
		system("cls");
	}
	_getch();
}