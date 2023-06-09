#include<iostream>
#include<cstring>
using namespace std;

void gethugeint1( int s1)
{
	 int hugeint1[500];
	for (int i = 0; i < s1; i++)
	{
		cin>>hugeint1[i];
	}
}
  void print1( int hugeint1[],int s1)
  {
	  for (int i = 0; i < s1; i++)
	{
		cout<<hugeint1[i];
	}
  }

  void gethugeint2(int s2)
  {
	  int hugeint2[500];
	  for (int j = 0; j < s2; j++)
	  {
		  cin>>hugeint2[j];
	  }
  }
void print2(int hugeint2[],int s2)
{
	for (int b = 0; b < s2; b++)
	{
		cout<<hugeint2[b];
	}
}
void multiply(int hugeint1[],int hugeint2[],int restultsize,int s1, int s2)
{
	int resultarr[500];

	for (int i = 0; i < s1; i++)
	{
		for (int j = 0; j < s2; j++)
		{
			resultarr[s1+s2]=hugeint1[i]*hugeint2[j];
		}
	}
}
void print3(int resultarr1[],int s1, int s2)
{
	int resultarr1[500];
		int multiply;
	for (int i = 0; i < s1; i++)
	{
		for (int j = 0; j < s2; j++)
		{
			multiply=resultarr1[s1+s2];
			cout<<multiply<<endl;
		}
	}
}
void subtract(int hugeint1[],int hugeint2[],int resultsize, int s1 ,int s2)
{
	int resultarr[500];
	for (int a = 0; a < s1; a++)
	{
		for (int b = 0; b < s2; b++)
		{
			resultarr[s1]=hugeint1[a]-hugeint2[b];
		}
	}
}
void print4(int resultarr2[],int s1, int s2)
{
	int resultarr2[500];
	int subtract;
	for (int a = 0; a < s1; a++)
	{
		for (int b = 0; b < s2; b++)
		{
			subtract=resultarr2[s1];
			cout<<subtract<<endl;
		}
	}
}
int main()
{
	int hugeint1[500];
	int hugeint2[500];
	int resultarr1[500];
	int resultarr2[500];
	int s1,s2,resultsize =0;
	cout<<"s1 is always greater than s2"<<endl;
	cout<<"enter the size 1"<<endl;
	cin>>s1;
	cout<<"enter the size 2"<<endl;
	cin>>s2;
	gethugeint1(s1);
	cout<<"hugeint1 ="<<endl;
	print1(hugeint1,s1);
	gethugeint2(s2);
	cout<<"hugeint2 ="<<endl;
	print2(hugeint2,s2);
	multiply(hugeint1,hugeint2,resultsize,s1,s2);
	cout<<"multiply result ="<<endl;
	print3(resultarr1,s1+s2);
	subtract(hugeint1,hugeint2,resultsize,s1,s2);
	print4(resultarr2,s1);
	system("pause");
	return 0;
}