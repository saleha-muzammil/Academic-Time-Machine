#include<iostream>

using namespace std;
int findPattern(char str[],char pattern []);
int findSubstring(char arr[],char sub[],int index);
int main()
{
	char arr[]="Hello I am a muslim I am going to Lahore ";
	char pattern[]="Hello*am*to";

	findPattern(arr,pattern);
	if(findPattern(arr,pattern)==-1)
	{
		cout<<" Pattern not found"<<endl;
	}
	else
	{
		cout<<" Pattern found"<<endl;
	}
	system("pause");
	return 0;
}
int findPattern(char str[],char pattern [])
{
	char sub[50]={'0'};
	int j=0,n=0;
	int i=0;
	for(n=0;n!='/0';n++)
	{
		if(str[n]==pattern[n])
		{
			break;
		}
	}
	for(i=n;pattern[i]!='*';i++)
	{
		sub[i]=pattern[i];
		
	
	}
	findSubstring(str,sub,n);
	if(findSubstring(str,sub,n)==-1)
	{
		return -1;
	}

	/*for(int n=0;n<i;n++)
	{
		cout<<sub[n];
		
	
	}*/

	return 0;


}
int findSubstring(char arr[],char sub[],int index)
{
	int i=0,flag=0;
	for(i=0;i<index;i++)
	{
		if(arr[i]==sub[i])
		{
			flag=1;
		}
	}
	if(flag=1)
	{
		return 1;
	}
	else 
	{
		return -1;
	}
}