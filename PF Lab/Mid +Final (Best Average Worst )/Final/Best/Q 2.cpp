#include <iostream>
using namespace std;

void getHugeInt(int h[],int &s)
{
	cout<<"Enter the size of Huge Int"<<endl;
	cin>>s;

	for(int i=0;i<s;i++)
	{
		cin>>h[i];
	}
}
void printHugeInt(int h[],int s)
{
	//To count the leading zeros
	int count=0;

	for(int i=0;h[i]==0;i++)
	{
		count++;
	}

	for(int i=count;i<s;i++)
	{
		cout<<h[i];
	}
	cout<<endl;
}
void multiply(int h1[],int h2[],int result[],int rs,int s1,int s2)
{
	//TO make a digit from array 
	long long r=0;
	//To make digit form the numbers of array1 
	long long n1=0;
	//To make digit form the numbers of array2
	long long n2=0;
	//To store the multiple 
	long long mul=0;
	//To take digit one by one
	int a=0;

	//To convert the 1st HugeInt in one digit
	for(int i=0;i<s1;i++)
	{
		a=h1[i];
		r=r*10+a;
	}
	
	n1=r;
	r=0;

	//To convert the 2st HugeInt in one digit
	for(int i=0;i<s2;i++)
	{
		a=h2[i];
		r=r*10+a;
	}

	n2=r;
	r=0;
	
	mul=n1*n2;

	rs=rs-1;

	//To convert the result of  HugeInts in result array
	for(int i=rs;i>=0;i--)
	{
		r=mul%10;
		result[i]=r;
		mul=mul/10;
	}

}
void subtract(int h1[],int h2[],int result[],int s1,int s2)
{
	//TO make a digit from array 
	long long r=0;
	//To make digit form the numbers of array1 
	long long n1=0;
	//To make digit form the numbers of array2
	long long n2=0;
	//To store the multiple 
	long long sub=0;
	//To take digit one by one
	int a=0;

	//To convert the 1st HugeInt in one digit
	for(int i=0;i<s1;i++)
	{
		a=h1[i];
		r=r*10+a;
	}

	n1=r;
	r=0;

	//To convert the 2st HugeInt in one digit
	for(int i=0;i<s2;i++)
	{
		a=h2[i];
		r=r*10+a;
	}

	n2=r;
	r=0;

	sub=n1-n2;

	//To convert the result of  HugeInts in result array
	for(int i=s1-1;i>=0;i--)
	{
		r=sub%10;
		result[i]=r;
		sub=sub/10;
	}

}

void main()
{
	int h1[20]={0};
	int h2[20]={0};
	int result[40]={0};
	int s1=0,s2=0,rs=0;


	getHugeInt(h1,s1);
	cout<<"The 1st HugeInt you entered is:"<<endl;
	printHugeInt(h1,s1);
	cout<<endl;

	getHugeInt(h2,s2);
	cout<<"The 2nd HugeInt you entered is:"<<endl;
	printHugeInt(h2,s2);
	cout<<endl;

	while(s1<s2)
	{
		cout<<"Size of s1 should be greater than s2"<<endl;
		cout<<"Kindly re-enter the HugeInt arrays"<<endl;

		getHugeInt(h1,s1);
		cout<<"The 1st HugeInt you entered is:"<<endl;
		printHugeInt(h1,s1);
		cout<<endl;

		getHugeInt(h2,s2);
		cout<<"The 2nd HugeInt you entered is:"<<endl;
		printHugeInt(h2,s2);
		cout<<endl;
	}


	//Caculating the size of result array;
	rs=s1+s2;

	multiply(h1,h2,result,rs,s1,s2);
	cout<<"Multiple Result is:"<<endl;
	printHugeInt(result,rs);
	cout<<endl;

	subtract(h1,h2,result,s1,s2);
	cout<<"Subtract Result is:"<<endl;
	printHugeInt(result,s1);
	cout<<endl;

}