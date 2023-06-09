# include <iostream>
using namespace std;
int main()
{
	int binary=0,a=0,f=0,n=0,d=1,b=0,c=0,sum=0;
	cout<<"enter binary digit in reverse order\n";
	while(binary!=-1)
	{
		cout<<"enter binary digit"<<f<<" :";
		f++;

		cin>>binary;
		a=binary;
		if(binary!=-1)
		{
			c=a*b;
			sum=sum+c;
			b=1;
			b=d*10;
			d=10;
			
		}

	}
	cout<<sum-100;
	
	
	

	system ("pause");
	return 0;
}
