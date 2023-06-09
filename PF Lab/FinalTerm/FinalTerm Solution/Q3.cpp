#include <iostream>
using namespace std;


bool Findsubstr(char * c1 , char * c2)
{
	for (int mark1 = 0 ; c1[mark1] != '\0' ; mark1++)
	{
		int mark2 = 0; //Initial position for second string.
		if (c1[mark1] == c2[mark2])
		{
			int temp1 = mark1;
			int d = 2;
			while (c1[temp1] != '\0' && c2[mark2] != '\0' && d == 2)
			{
				temp1++;
				mark2++;
				if(c1[temp1] == c2[mark2] && c1[temp1] != '\0' && c2[mark2] != '\0')
				{
					temp1++;
					mark2++;
				}
				else if (c1[temp1] != c2[mark2])
					d = 5;
				if (c2[mark2] == '\0')
					return true;
				if (c1[temp1] == '\0' && c2[mark2] != '\0')
					return false;
			}
		}
	}
	return false;
}

int main()
{
	char * c1 = new char[100];
	char * c2 = new char[100];
	cout << "Input string 1 : ";
	cin.getline(c1 , 100);
	cout << "Input string 2 : ";
	cin.getline(c2 , 100);
	bool flag = false;
	flag =	Findsubstr(c1,c2);
	if (flag == 1)
		cout << "True\n";
	else 
		cout << "False\n";
	return 0;
}