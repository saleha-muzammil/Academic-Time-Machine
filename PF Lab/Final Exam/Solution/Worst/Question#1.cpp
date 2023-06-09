#include<iostream>
using namespace std;
int findPattern(char str[],char pattern[]);
int findSubString(char arr[],char sub[],int index);
int main()
{
	char str[100],pattern[100];
	cout<<"Enter a character string"<<endl;
	cout<<"Str:\t";
	cin.get(str,100);
	cout<<"Enter a pattern"<<endl;
	cout<<"pattern:\t";
	cin.get(pattern,100);
	int index=findPattern(str,pattern);
	if(index==-1)
	{
		cout<<"Pattern Not Found";
	}
	else
	{
		cout<<"Pattern Found";
	}
	system("pause");
	return 0;
}
int findSubString(char arr[],char sub[],int index)
{
	for(int i=0;i<100;i++)
	{
			if(sub[i]!=arr[i])
			return -1;
			else
				return i;
		
	}
}
int findPattern(char str[],char pattern[])
{
	char ch[100];
	
	int i=0;
	while(pattern!='\0')
	{
		ch[i]=str[i];
		i++;
		
		findSubString(str,ch,i);
		if(!findSubString)
		{
	         return -1;
		}
		else
		{
			return 0;
		}
	}
}
	



