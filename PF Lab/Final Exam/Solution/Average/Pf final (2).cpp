#include <iostream>
using namespace std;

void removeduplicatewords(char arr[]);
{
	char dup[100],j[50];
	size=sizeof(arr)/sizeof(arr[0])
	for(int i=0;i<size;i++)
    for(intj=i+1;j<size;j++)
	{
		if(arr[i]==arr[j])
		{
		for(int a=0;a<100;a++)
		{
			dup[a]=arr[i];
			int sbstr=findsubstring( arr,dup,i)
		return sbstr;
		}
		}
	
	
	
	}
	
}//duplicate words ends

int findsubstring(char arr[],char sub[],int index)
{
	for(int i=0;i<index;i++)
	if(arr[i]==sub[index])
	{
	
	char temp=' ';
	arr[index]=temp;
	

	}
		else 
		return -1;
}//substring ends


void main()
{
	char arr[]="hello i am muslim going to lahore hello";
	removeduplicatewords(arr);
	cout<< arr << endl;
	system("pause");
	

}