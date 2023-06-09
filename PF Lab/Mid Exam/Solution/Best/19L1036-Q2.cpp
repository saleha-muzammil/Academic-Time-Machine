#include<iostream>

using namespace std;

int main()
{
	int num,digit,last,n=1,i=0,place;
	cout<<"	Enter a number : ";
	cin>>num;
	while(num>10000000)
	{
		cout<<"	Number exceds from maximum range"<<endl;
		cout<<"	Enter a number : ";
		cin>>num;
	
	}
	cout<<"	enter a digit whose place value is to be checked : ";
	cin>>digit;
	while(num!=0)
	{
	last=num%10;
	if(last==digit)
	{
		place=n;
		i=1;
		break;
	}
	
	n=n*10;
	num=num/10;
	}
	if(i==1)
	{
	if(place==1)
	{
	cout<<"	"<<digit<<"	 is at units"<<endl;
	
	}
	else if(place==10)
	{
	cout<<"	"<<digit<<"	 is at tens"<<endl;
	
	}
	else if(place==100)
	{
	cout<<"	"<<digit<<"	 is at hundreds"<<endl;
	
	}
	else if(place==1000)
	{
	cout<<"	"<<digit<<"	 is at thousands"<<endl;
	
	}
	else if(place==10000)
	{
	cout<<"	"<<digit<<"	 is at ten thousands"<<endl;
	
	}
	else if(place==100000)
	{
	cout<<"	"<<digit<<"	 is at hundred thousand"<<endl;
	
	}
	else if(place==1000000)
	{
	cout<<"	"<<digit<<"	 is at million"<<endl;
	
	}
	else if(place==10000000)
	{
	cout<<"	"<<digit<<"	 is at ten million"<<endl;
	
	}
	}
	else
	{
	cout<<"	digit is not present in number "<<endl;
	}
	
system("pause");
	return 0;

}