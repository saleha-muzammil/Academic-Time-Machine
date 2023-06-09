#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter a Number : ";
	cin>>n;
	if(n<0)
	{
		cout<<"\nEnter positive No.\n";
	}
	else if (n==0)
	{
		cout<<"\nMultiplication Table\n";
		cout<<"0\n";
	}
	else if(n>0)
	{
		cout<<"Multiplication Table : \n"<<"   ";
		for(int i=1;i<=n;i++)
		{
			cout<<i<<"\t";
		}
		cout<<endl<<endl;
		for(int i=1;i<=n;i++)
		{
			cout<<i<<"| ";
			for(int j=1;j<=n;j++)
			{
				cout<<i*j<<"\t";
			}
			cout<<endl;
		}
	}
	system("pause");
	return 0;
}