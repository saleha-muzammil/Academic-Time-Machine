# include <iostream>
using namespace std;
int main()
{
int num=0,a=0,b=0,c=0,d=0;

	while(num!=-9999)
	{
		cin>>num;
		a=num;
		d=num-a;
		while(d!=num-a)
		{
		d=a-num;
		d=a/num;
		if(num-1+num-2==num)
			cout<<"this is fibonachic series";
		else
			cout<<"not a series";
		}
		if(d==0)
			cout<<"this is arithmetic series";
		else
				cout<<"not a series";
		if(d==1)
			cout<<"this is geomatric series";
		else
				cout<<"not a series";
		system ("pause");
		return 0;
	}


