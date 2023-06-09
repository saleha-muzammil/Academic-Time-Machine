#include <iostream>
using namespace std;

int stringlength(char arr[])
{
	int i=0;
	while(arr[i]!='\0')
	{
		i++;
	}
	return i;
}

int strcomparison(char sub[], char arr[], int s, int n)
{
	int i=0,j=s;
	while (arr[j]!='\0' && sub[i]!='\0' && j<s+n)
	{
		if (arr[j]<sub[i])
			return -1;
		else if (arr[j]>sub[i])
			return 1;
		i++;
		j++;
	}
	if (arr[j]<sub[i])
			return -1;
		else if (arr[j]>sub[i])
			return 1;
		else
			return 0;
}

int findSubstring(char arr[], char sub[], int index)
{
	int l1=stringlength(sub);
	int l2=stringlength(arr);
	//l2=l2-index;

	for (int i=0; i<l2-l1; i++)
	{
		if (strcomparison(sub,arr,i,l1)==0)
			return i;
	}
	return -1;

}

void removeDuplicateWords(char arr[])
{
	char sub[50];
	int i=0;
	while (arr[i]!='\0')
	{
		int j=0;
		while(arr[i]!=' '&&arr[i]!='\0')
		{
			sub[j]=arr[i];
			i++;
			j++;
		}
		sub[j]='\0';
		if(arr[i]=='\0')
			break;
		i++;

		int index;
		index=findSubstring(arr,sub,i);

		if (index!=-1)
		{
			for (int k=0;k<=stringlength(sub);k++)
			{
				int a=index;
				while(a<stringlength(arr)+1)
				{
					arr[i]=arr[i+1];
					a++;
				}
			}

		}
	}

}







void main()
{

	char arr[]="Hello I am muslim I am going to Lahore Hello";
	removeDuplicateWords(arr);
	cout<<arr<<endl;


	system("PAUSE");
}