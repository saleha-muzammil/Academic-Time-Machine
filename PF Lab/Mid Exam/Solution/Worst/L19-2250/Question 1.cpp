#include<iostream>
using namespace std;
int main()
{
	float k,value,n,i=1,max,min;
	cout<<"Enter the value of K:";
	cin>>k;
	n=k+1;
	while(i>=n)
	{
	
		cout<<"Input the values:";
	    cin>>value;
		if(value==-1)
		{
			break;
		}
		max=value;
		if(max>max)
		{
			cout<<"The "<<k<<"th highest element is:"<<max;
		}
		min=value;
		if(min<min)
		{
			cout<<"The "<<k<<"th smallest element is : "<<min;
		}
		i++;
	}
	system("pause");
	return 0;
}