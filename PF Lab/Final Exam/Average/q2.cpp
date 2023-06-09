#include <iostream>
#include <cstring>
using namespace std;
int findsubstring(char a[],char sub[],int index,int l)
{
	int count=0;
	int j=0;
	char b[100];
	for(int i=index;a[i]!='\0';i++)
	{
		if(a[i]==sub[j])
		{
			b[j]=a[i];
			count++;
		}
		j++;
	}
	if(count==l)
	{
	cout<<"sub string is found :";
	for(int i=0;i<count;i++)
	{
		cout<<b[i];
	}
	}
	else 
	{
	cout<<"sub string is not present";
	return -1;
	}

	return 0;
}
void removeduplicatewords(char a[])
{
	char sub1[100];
	char sub2[100];
	cout<<"enter your sub strings :";
	cin.get(sub1,100);
	int m=0;
	for(int i=0;sub1[i]!='\0';i++)
	{
		m++;
	}
findsubstring(a,sub1,6,m);
cout<<endl;
	cout<<"enter second sub string :";
	cin>>sub2;
	int n=0;
	for(int j=0;sub2[j]!='\0';j++)
	{
		n++;
	}
findsubstring(a,sub2,39,n);


}
int main()
{
	char a[]="Hello I am muslim I am going to Lahore Hello";
	int size=strlen(a);
	removeduplicatewords(a);


	system("pause");
	return 0;
}