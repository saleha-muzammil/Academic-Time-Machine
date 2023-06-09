#include<iostream>
#include<cstring>
using namespace std;
int findpattern(char arr[],char sub[])
{
	cout<<"enter the search words"<<endl;
	int i;
	for (int b = 0; b <arr[i]; b++)
	{
		cin>>sub[b];
		if(" ")
		{
			cout<<"*";
		}
	}
	return 0 ;
}
int findsubstring(char arr[],char sub[],int index)
{
	if (index==-1)
		cout<<"patteren not found"<<endl;
	else
		cout<<"patteren found"<<endl;
}
int main333()
{
	char arr[500];
	char sub[500];
	cout<<"enter the size of character array"<<endl;
	int a;
	cin>>a;
	cout<<"enter the characters"<<endl;
	for (int i = 0; i < a; i++)
	{
		cin>>arr[i];
	}
	int index=findpattern(arr,sub);
	findpattern(arr,sub);
	int i;
		for (int b = 0; b <arr[i]; b++)
	{
	cout<<sub[b];
	}
	findsubstring(arr,sub,index);
	system("pause");
	return 0;
}