#include <iostream>
using namespace std;

int strlength(char array[])
{
	int counter=0;
	while (array[counter]!='\0')
	{
		counter++;
	}
	return counter;
}

int main()
{
	char string1[100];
	char string2[100];
	cout<<"Enter String 1: ";
	cin>>string1;
	cout<<"Enter String 2: ";
	cin>>string2;

	int l1=strlength(string1);
	int l2=strlength(string2);

	cout<<"The longer string is *";

	if (l1>l2)
	{
		cout<<string1<<"*"<<endl;
		cout<<"Length of longer string is *"<<l1<<"*";
	}
	else if (l1<l2)
	{
		cout<<string2<<"*"<<endl;
		cout<<"Length of longer string is *"<<l2<<"*";
	}
	else
	{
		cout<<string1<<"*"<<endl;
		cout<<"Length of longer string is *"<<l1<<"*";
	}

	cout <<endl;
	cout<<"Common Characters: ";
	
	for (int i=0;i<l1;i++)
	{
		for(int j=0;j<l2;j++)
		{
			if(string2[j]==string1[i])
			{ 
				cout<<string2[j]<<", ";
				break;
			}

		}
	}



	cout <<endl;
	system("PAUSE");
	return 0;
}