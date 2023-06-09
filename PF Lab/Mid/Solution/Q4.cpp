#include<iostream>
using namespace std;
void ConvertToUpperCase(char string1[])
{
	int sp=0;
	for(int i=0;string1[i]!='\0';i++)
	{
		if(string1[i]=='.')
		{
			if(string1[i+1]>=97&&string1[i+1]<=122)
			{
				string1[i+1]=string1[i+1]-32;
			}
		}
	}
	for(int i=0;string1[i]==32;i++)
	{
		sp++;
	}
	if(string1[sp]>=97&&string1[sp]<=122)
	{	
		string1[sp]=string1[sp]-32;
	}
	if(string1[0]>=97&&string1[0]<=122)
	{	
		string1[0]=string1[0]-32;
	}
}
void ConvertToLowerCase(char string1[])
{
	int sp=0;
	for(int i=0;string1[i]!='\0';i++)
	{
		if(string1[i-1]!='.')
		{
			if(string1[i]>=65&&string1[i]<=90)
			{
				string1[i]=string1[i]+32;
			}
		}
	}
		for(int i=0;string1[i]==32;i++)
	{
		sp++;
	}
	if(string1[sp]>=97&&string1[sp]<=122)
	{	
		string1[sp]=string1[sp]-32;
	}
	if(string1[0]>=97&&string1[0]<=122)
	{	
		string1[0]=string1[0]-32;
	}
}
void RemoveSpecialCharacter(char string1[])
{
	int j=0;
	char a[100]={'\0'};
	for(int i=0;string1[i]!='\0';i++)
	{
		if(string1[i]==32||(string1[i]>=65&&string1[i]<=90)||(string1[i]>=97&&string1[i]<=122)||string1[i]=='.'||string1[i]=='0'||string1[i]=='1'||string1[i]=='2'||string1[i]=='3'||string1[i]=='4'||string1[i]=='5'||string1[i]=='6'||string1[i]=='7'||string1[i]=='8'||string1[i]=='9')
		{
			a[j]=string1[i];
			j++;
		}
	}
	for(int i=0;i<100;i++)
		string1[i]=32;
	int sp=0;
	for(int i=0;a[i]==32;i++)
	{
		sp++;
	}
	int k=0; 
	for(int i=0;a[i]!='\0';i++)
	{
		string1[i]=a[sp];
		sp++;
		k++;
	}
	string1[k]='\0';
}
int main()
{
	char string1[100]={'\0'};
	cout<<"Enter String : ";
	cin.getline(string1,100);
	cout<<"\n\nBefore Calling functions : \n";
	cout<<endl<<string1<<endl; 
	ConvertToUpperCase(string1);
	ConvertToLowerCase(string1);
	RemoveSpecialCharacter(string1);
	cout<<"\nAfter Calling All three Functions : ";
	cout<<endl<<endl<<string1<<endl<<endl; 
	system("pause");
	return 0;
}



