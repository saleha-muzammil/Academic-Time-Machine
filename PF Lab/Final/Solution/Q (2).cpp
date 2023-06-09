#include <iostream>
using namespace std;
int main()
{
	char data[8][6] = { 0 };
	//8 total floors
	//Floor 1 and 2 first class
	//3,4,5 are non smoking
	cout << "Which type of Hotel do you want? First Class = 1, Economy = 2, Exit = -1\n";
	int ans;
	bool found = false;
	int ans2;
	cin >> ans;
	while (ans != -1)
	{
		found = false;
		//For FirstClass
		if (ans == 1)
		{

			for (int i = 0; i < 2 && found == false; i++)
			{
				for (int j = 0; j < 6 && found == false; j++)
				{
					if (data[i][j] != 'X')
					{
						data[i][j] = 'X';
						found = true;
					}
				}
			}
			if (!found)
			{
				cout << "There are no Rooms Available in First Class\n";
			}
			else
				cout << "Action Successfull, Please Come again!\n";
		}
		//For Economy
		else if (ans == 2)
		{
			cout << "Do you want Smoking or non smoking? Non-Smoking = 1, Smoking = 2\n";
			cin >> ans2;
			if (ans2 == 1)
			{
				for (int i = 2; i < 5 && found == false; i++)
				{
					for (int j = 0; j < 6 && found == false; j++)
					{
						if (data[i][j] != 'X')
						{
							data[i][j] = 'X';
							found = true;
						}
					}
				}
				if (!found)
				{
					cout << "There are no Rooms Available in Economy Class in Non-Smokers Section\n";
				}
				else
					cout << "Action Successfull, Please Come again!\n";
			}
			else if (ans2 == 2)
			{
				for (int i = 5; i < 8 && found == false; i++)
				{
					for (int j = 0; j < 6 && found == false; j++)
					{
						if (data[i][j] != 'X')
						{
							data[i][j] = 'X';
							found = true;
						}
					}
				}
				if (!found)
				{
					cout << "There are no Rooms Available in Economy Class in Smokers Section\n";
				}
				else
					cout << "Action Successfull, Please Come again!\n";
			}
			else
				cout << "Invalid Input\n";
		}
		else
			cout << "Enter a valid Input Either 1 or 2\n";
		system("cls");
		cout << "Which type of Hotel do you want? First Class = 1, Economy = 2, Exit = -1\n";
		cin >> ans;
		ans2 = 0;
	}
	system("cls");
	for (int i = 0; i < 8; i++)
	{
		cout << "Floor" << i+1 << "		";
		for (int j = 0; j < 6; j++)
		{
			if (data[i][j] != 'X')
				cout << "*	";
			else
				cout << "X	";
		}
		cout << endl;
	}
	system("pause");
}