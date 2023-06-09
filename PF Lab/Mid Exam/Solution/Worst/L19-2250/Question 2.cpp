#include<iostream>
using namespace std;
int main()
{
	long n,rev;
	cout<<"Enter any number:";
	cin>>n;
	while(n>0)
	{
       rev=n%10;
	   n=n/10;
	  if(n%1==0)
	  {
		  cout<<"Units";
		  }

	  else  if(n%10==0)
	  {
		  cout<<"Tens";
	  }
	  else if(n%100==0)
	  {
		  cout<<"Hundreds";
	  }
	 else  if(n%1000==0)
	  {
		  cout<<"thousands";
		  }
	  else  if(n%10000==0)
	  {
		  cout<<"Ten Thousands";
		  }
	 else  if(n%100000==0)
	  {
		  cout<<"Millions";
		  }
	  else  if(n%1000000==0)
	  {
		  cout<<"Ten Millions";
		  }
	}
	system("pause");
	return 0;
}