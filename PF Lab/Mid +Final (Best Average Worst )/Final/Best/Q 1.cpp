#include <iostream>
using namespace std;

int findSubString(char arr[],char sub[],int index)
{
	//To move the index of sub
	int j=0;
	//To find the length of array
	int count=0;
	//To find the length sub
	int count1=0;
	//To count spaces 
	int c=0;
	//To match with the length of sub
	int wordfound=0;
	
	//Finding the length of array
	while(arr[count]!='\0')
	{
		count++;
	}

	//Finding the length of sub array
	while(sub[count1]!='\0')
	{
		if(sub[count1]==' ')
		{
			c++;
		}

		count1++;
	}

	//Removing the number of spaces from the array
	count1=count1-c;

		for(int k=0;k<count;k++)
		{
			if(sub[j]!=' ')
			{
				if(arr[k]==sub[j])
				{
					wordfound++;
					j++;
				}
			}
			else
			{
				j++;
			}
		}

		if(wordfound==count1)
		{
			return 1;
		}
		else
		{
			return -1;
		}

}

int findPattern(char str[],char pattern[])
{
	//To store the pattern in the array
	char sub[50];
	//To move the index of sub array
	int j=0;
	int index=0;
	//To pass the index to function
	int l=0;

	for(int i=0;pattern[i]!='\0';i++)
	{
		if(pattern[i]!='*')
		{
			sub[j]=pattern[i];
			j++;
		}
		else
		{
			sub[j]=' ';
			j++;
		}
	}
	sub[j]='\0';

	 l=findSubString(str,sub,index);

	
return l;
}

void main()
{
	char arr[]="Hello I am muslim I am going to Lahore";
	char pattern[]="Hello*muslim*to*Lahore";
	int index=0;

	cout<<"String is : ";
	cout<<arr<<endl;

	cout<<"Sub-String is : ";
	for(int i=0;pattern[i]!='\0';i++)
	{
		if(pattern[i]!='*')
		{
			cout<<pattern[i];
		}
		else
		{
			cout<<" ";
		}
	}

	cout<<endl;

	index=findPattern(arr,pattern);

	if(index==-1)
	{
		cout<<"Pattern not found"<<endl;
	}
	else
	{
		cout<<"Pattern found"<<endl;
	}

}