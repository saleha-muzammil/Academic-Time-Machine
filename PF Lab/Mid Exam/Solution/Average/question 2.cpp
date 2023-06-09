#include <iostream>
using namespace std;
int main ()
{
float k1,k2;
	float check1,check2,count1,count2,i=0,j=0,k=0,l=1;
	cin>>k1;
	cin>>k2;
	while (k1!=-1 && k2!=-1)
	{
		if (k1>k2)
		{
			if (k=0)
			{
			k1=check1;
				k2=check2;
			k=k+1;
			i=1;
			}
			if (k>0 && k1<check1|| k2<check2)
			{
				k1=check1;
				k2=check2;
				i=1;
			}
		}
		if (k2>k1)
		if (k1>check1 || k2>check2)
		{
			k1=check1;
				k2=check2;
		    j=1;
		}
		cin>>k1;
		cin>>k2;
	}
	if (i==0&& j==0)
	{
		if (check2>check1)
		{
			cout<<check1<<" is larges"<<endl;
		}
		else
		{
			cout<<check2<< " is largest "<<endl;
		}
	}
		if (j==1 && i==0)
		{
			if (check2<check1)
			{
				cout<<check2<< " is smallest"<<endl;
			}
			else
			cout<<check1<< " is smallest"<<endl;
		}
		if (i==1   && j==1)
		{
			cout<<"unsorted order"<<endl;
		}
		system("pause");
		return 0;
}

