# include <iostream>
# include <cstring>
using namespace std;
int findsubstring(char arr[],char sub[],int index);
void removeduplicatewords(char arr1[]);
int findsubstring(char arr[],char sub[],int index)
{
	int i=index;
	int l=strlen(arr);
	int n=0,count=0,ind=0;
	while(arr[i]!='\0')
	{

		if(arr[0]==sub[0])
		{
			count=0;
			n=1;
			for(int k=1;k<l;k++)
			{
				if(arr[n]==sub[k])
				{
					count++;
					n++;
				}
				else
					break;
			}
				 ind=n-l;
		}
		i++;
	}
	if(count>0)
		return ind;
	else
		return -1;
}
void removeduplicatewords(char arr1[])
{

	int l1=strlen(arr1);

	char arr2[100];
	int m=0,index=0;
	for(int i=0;arr1[i]!='\0';i++)
	{
		if(arr1[i]!=' ')
		{
			arr2[m]=arr1[i];
			m++;
		}
		else
		{
			arr2[m]='\0';
			index=m;
			int fi=findsubstring(arr1,arr2,index);
			if(fi!=-1)
			for(int w=index;arr1[w]!='\0';w++)
			{
			  arr1[m]=arr1[m+1];
			}
		}
	}
}
void main()
{
	char arr[]="hello i am muslim i am going to lahore hello";
	removeduplicatewords(arr);
	cout<<arr<<endl;
	system ("pause");
}