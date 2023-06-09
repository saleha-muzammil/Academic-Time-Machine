#include<iostream>
using namespace std;
int main()
{
	int arr[10];
	bool f=true;
	cout<<"Enter Values : ";
	for(int i=0;i<10;i++)
	{
		cin>>arr[i];
		if(arr[i]<0&&arr[i]>99999)
		{
			cout<<"\nInvalid Input\n";
			break;
		}
	}
	int n,n1=0;
	int a[10];
	for(int i=0;i<10;i++)
	{
		a[i]=arr[i];
	}
	int b[10],b1=0;
	for(int i=0;i<10;i++)
	{
		b[i]=0;
	}
	cout<<"\nEnter specified no : ";
	cin>>n;
	if(n<0&&n>999999)
		cout<<"\nInvalid Input\n";
	else
	{
		for(int i=0;i<10;i++)
		{
			for(int j=9;j>i;j--)
			{
				if((a[i]+a[j]==n)&&a[j]!=0)
				{
					b[b1]=a[i];
					b[b1+1]=a[j];
					b1=b1+2;
					a[j]=0;
				}
			}
		}
		int c=0;
		for(int i=0;b[i]!=0;i++)
		{
			c++;
		}
		int i=0;
		cout<<"\nArray Pairs whose sum is 12 : \n";
		while(i<c)
		{
			cout<<b[i]<<","<<b[i+1]<<endl;
			i=i+2;
		}
		cout<<"\nNo. of pairs whose Sum is "<<n<<":"<<c/2<<endl<<endl;


	}
	system("pause");
	return 0;
	}
