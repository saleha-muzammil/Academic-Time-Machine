#include <iostream>
using namespace std;
bool Findsubstr(char*str1, char*str2)
{
	bool matches = false;
	for (int i = 0; i < strlen(str1) - strlen(str2) && !matches; i++)
	{
		if (str1[i] = str2[0])
		{
			matches = true;
			for (int j = 0; j < strlen(str2) && matches; j++)
			{
				if (str1[i + j] != str2[j])
				{
					matches = false;
				}
			}
		}
	}
	if(matches)
		return matches;

}
int main()
{
	char* str;
	int size;
	cout << "Enter the size of your string\n";
	cin >> size;
	str = new char[size+1];
	//I have to add this or the code doesn't work for me.
	cin.getline(str, size);
	char* substr;
	substr = new char[size+1];
	cout << "Enter your string\n";
	cin.getline(str, size);
	cout << "Enter your other string \n";
	cin.getline(substr, size);
//	cout << str << endl << substr << endl;
	bool flag = Findsubstr(str, substr);
	if (flag)
	{
		cout << "substring was found\n";
	}
	else
		cout << "substring was not found\n";
	system("pause");


}