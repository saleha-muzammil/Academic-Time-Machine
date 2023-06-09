#include<iostream>

using namespace std;

void getint(int Hugeint[],int &s);
void printint(int hugeint[],int s);
void mul(int hugeint1[],int hugeint2[],int result[],int s1,int s2);
void sub(int hugeint1[],int hugeint2[],int result[],int s1,int s2);

int main()

{
	int Hugeint1[20],Hugeint2[20],result[40]={0};
	int size1,size2,resultsize=0;
	getint(Hugeint1,size1);
	cout<<"	The Hugeint you entered is";
	printint(Hugeint1,size1);
	getint(Hugeint2,size2);
	cout<<"	The Hugeint you entered is";
	printint(Hugeint2,size2);

	
	mul(Hugeint1,Hugeint2,result,size1,size2);
	cout<<"	Product of two numbers is : ";
	printint(result,(size1+size2)-1);
	sub(Hugeint1,Hugeint2,result,size1,size2);
	cout<<"	Difference of two numbers is : ";
	printint(result,size1);
	system("pause");
	return 0;

}
void getint(int Hugeint[],int &s)
{
	int i;
	cout<<"	enter size of array : ";
	cin>>s;

	for(i=0;i<s;i++)
	{
		cout<<"		Enter digit # "<<i+1<<" of number : ";
		cin>>Hugeint[i];
		if(Hugeint[i]>10)
		{
			cout<<"	Invalid Input"<<endl;
			i--;
		}
	
	}




}
void printint(int hugeint[],int s)
{
	int i=0;
	
	for(i=0;i<s;i++)
	{
		cout<<hugeint[i];
	
	}
	cout<<endl;



}
void mul(int hugeint1[],int hugeint2[],int result[],int s1,int s2)
{
	int i,n=0,mul=1;
	int num1=0,num2=0;
	for(i=0;i<s1;i++)
	{
		num1=(num1+hugeint1[i]);
		num1=num1*10;
	
	}
	num1=num1/10;
	//cout<<"**"<<num1;
	for(i=0;i<s2;i++)
	{
		num2=(num2+hugeint2[i]);
		num2=num2*10;
	
	}
	num2=num2/10;
	//cout<<"**"<<num2;
	mul=num1*num2;
	i=0;
	while(mul!=0)
	{
		n=mul%10;
		result[i]=n;
		i++;
		mul=mul/10;
	}
	int mid;
	mid=i/2;

	for(int j=0;j<(i/2);j++)
	{

		int a=0,b=i-1,temp;
		temp=result[a];
		result[a]=result[b];
		result[b]=temp;
		
		a++;
		b--;

	}
}

void sub(int hugeint1[],int hugeint2[],int result[],int s1,int s2)
{
	int i,n=0,sub=1;
	int num1=0,num2=0;
	for(i=0;i<s1;i++)
	{
		num1=(num1+hugeint1[i]);
		num1=num1*10;
	
	}
	num1=num1/10;
	//cout<<"**"<<num1;
	for(i=0;i<s2;i++)
	{
		num2=(num2+hugeint2[i]);
		num2=num2*10;
	
	}
	num2=num2/10;
	//cout<<"**"<<num2;
	sub=num1-num2;
	i=0;
	while(sub!=0)
	{
		n=sub%10;
		result[i]=n;
		i++;
		sub=sub/10;
	}
	for(int j=0;j<(i/2);j++)
	{
		int a=0,b=i-1,temp;
		temp=result[a];
		result[a]=result[b];
		result[b]=temp;
		
		a++;
		b--;

	}
}