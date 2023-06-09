#include <iostream>
using namespace std;
int main()
{
	int height = 0, i = 0, j = 0;
	char ch1 = '\0';
	cout << "Enter height of pattern: ";
	cin >> height;
	cout << "Enter character for pattern: ";
	cin >> ch1;
	for (i = 1; i <= height; i++)
	{
		for (j = 1; j <= i; j++)
		{

			cout << ch1 << " ";
		}

		cout << endl;
	}
	for (i = height; i >= 1; i--)
	{
		for (j = 1; j <= i; j++)
		{

			cout << ch1 << " ";
		}

		cout << endl;
	}
	return 0;

}