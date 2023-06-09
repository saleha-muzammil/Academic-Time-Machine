#include<iostream>
using namespace std;
int main()
{
	float charges=15;
	float bal;
	int chk;
	cout<<"Enter your Balance : ";
	cin>>bal;
	cout<<"\nEnter No of checks : ";
	cin>>chk;
	if(bal<0||chk<0)
	{
		if(bal<0&&chk<0)
			cout<<"\nInvalid Balance and Checks.\n";
		else if(chk<0)
			cout<<"\nInvalid checks.\n";
		else if(bal<0)
			cout<<"\nInvalid Balance.\n";

	}
	else
	{
		if(chk<20)
		{
			charges=charges+(0.10*chk);
		}
		else if(chk>=20&&chk<=39)
		{
			charges=charges+(0.80*chk);
		}
		else if(chk>=40)
		{
			charges=charges+(0.06*chk);
		}
		cout<<"\nBank's Service fees of Month : "<<charges<<endl;
	}
	

	system("pause");
	return 0;
}