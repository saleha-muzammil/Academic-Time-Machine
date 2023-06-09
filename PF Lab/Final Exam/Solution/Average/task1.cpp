#include <iostream>
using namespace std;
int findSubString(char arr[],char sub[], int index)
{
int index;
   char find;
   char chararr[10];
	cout<<"Enter the index"<<endl;
	cin>>index;
	cout<<"find";
	cin>>find;
	cout<<"Enter array:"<<endl;
	cin>>arr[index];
	for (int i=0;i<index;i++)
	{
		if(arr[i]==find)
		{
		arr[i]=sub[index];
		chararr[10]=sub[index];
		}
	}

}

int findPattern(char str[], char pattern[])
{  

}
void main()
{
char arr[] = "Hello I am Muslim I am going to Lahore";
char pattern[] = "Hello*Lahore*to";
int index = findPattern(arr, pattern);
if (index == -1)
{
    cout<<"Pattern Not found";
}
else
{
	cout<<"Pattern found";
}
}
 

