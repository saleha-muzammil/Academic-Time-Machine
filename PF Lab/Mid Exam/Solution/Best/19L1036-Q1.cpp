#include<iostream>

using namespace std;

int main()
{

	float num=0,previousnum=0,counter=0,k,reqnum=0,x=4,num1=0;
	cout<<"	Enter value of K : ";
	cin>>k;
	cout<<"	Enter a number : ";
	cin>>num;
	previousnum=num;
	counter++;
	while(num!=-1)
	{
		num1=previousnum;
		previousnum=num;
		cout<<"	Enter a number : ";
		cin>>num;
		counter++;
		if(num1<previousnum<num)
		{
			if(counter==k)
			{
			reqnum=num;
			x=1;
			}
		}
		else if(num1>previousnum>num)
		{
		if (counter==k)
		{
			reqnum=num;
			x=2;
		}
		}
		else
		x=0;
	}	
		
	

	if(x=1)
	{

		cout<<k<<"	th smallest number is : "<<reqnum<<endl; 
	}
	else if(x=2)
	{
	cout<<k<<"	th highest number is : "<<reqnum<<endl;
	}
	else if(x=0)
	{

		cout<<"	Values are not sorted"<<endl;
	}







		system("pause");
		return 0;
}	
	