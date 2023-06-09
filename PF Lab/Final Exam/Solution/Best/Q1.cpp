#include <iostream>
using namespace std;
int FindPattern( char arr[], char pattern[]);
int FindSubString(char arr[],char sub[], int& index,int& j);
bool found=false;

void main()
{

	char arr[]="Hello I  a muslim I am going to Lahore"; 
	char pattern[]="a*am*Lahore";
	int index=FindPattern(arr,pattern);
	if (index==-1)
		cout<<"Pattern Not found"<<endl;
	else
		cout<<"Pattern found"<<endl;
	system("pause");
}
int FindPattern( char arr[], char pattern[])
{
	int j=0;
	int i;
	for (i=0;arr[i]>'\0';i++)
	{
		FindSubString(arr, pattern,i,j);
	}
	if(pattern[j]=='\0' )
		return i;
	else 
		return -1;
}

int FindSubString(char arr[],char sub[], int& index,int& j)
{
	if (arr[index]==sub[j])
		{
			j++;
		}
			else if (sub[j]=='*')
			j++;
	if(sub[j]=='\0')
	{
		found=true;
		return 1;
	}
	else 
		return 0;
}