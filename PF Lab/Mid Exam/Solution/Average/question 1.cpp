#include <iostream>
using namespace std;
int main ()
{
	int n,count,p,a,b,c,d,e,f,g,h;
	cout<<"enter any num"<<endl;
		cin>>n;
		while (n/10!=0)
		{
		cout<<"which position"<<endl;
		cin>>p;
			a=n%10;
			n=n/10;
			if (p==a)
			{
				cout<<"unit"<<endl;
			}
			b=n%10;
				n=n/10;
             if (p==b)
			{
				cout<<"ten"<<endl;
			}
			 c=n%10;
			 n=n/10;
			if (p==c)
			{
				cout<<"hundred"<<endl;
			}
			d=n%10;
			n=n/10;
			if (p==d)
			{
				cout<<"thousands"<<endl;
			}
		    e=n%10;
			n=n/10;
			if (p==e)
			{
				cout<<"ten thousands"<<endl;
			}
			f=n%10;
			n=n/10;
			if (f==e)
			{
			cout<<"hundred thousands"<<endl;
			}
			g=n%10;
			n=n/10;
			if (p==g)
			{
				cout<<"millions"<<endl;
			}
			h=n%10;
			n=n/10;
			if (p==h)
			{
				cout<<"ten millions"<<endl;
			}
	      if (p!=a && p!=b && p!=c &&  p!=d &&  p!=e && p!=f && p!=g && p!=h)
		{
			cout<<"number not present __ write again"<<endl;
		}
		}
		system("pause");
		return 0;
}
