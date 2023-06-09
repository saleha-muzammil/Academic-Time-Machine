#include <iostream>
using namespace std;
void GetHugeInt(int hugeInt[], int& size);
void PrintHugeint(int hugeInt[], int size);
void Multiply(int hugeInt1[], int hugeInt2[], int result[], int s1, int s2);
int Subtract(int hugeInt1[], int hugeInt2[], int result[], int s1, int s2);

void main()
{
	int hugeInt1[20], hugeInt2[20],result[40]={0};
	int size1, size2,resultSize=0;
	cout<<"Enter size of HugeInt: ";
	cin>>size1;
	GetHugeInt(hugeInt1,size1);
	cout<<"The hugeInt you entered is: ";
	PrintHugeint(hugeInt1,size1);
	cout<<"\nEnter size of HugeInt: ";
	cin>>size2;
	GetHugeInt(hugeInt2,size2);
	cout<<"The hugeInt you entered is: ";
	PrintHugeint(hugeInt2,size2);

	Multiply(hugeInt1, hugeInt2, result, size1, size2);
	cout<<"\nMultiply Result is: ";
	PrintHugeint(result,size1+size2-1);

	cout<<"\nSubtract Result is: ";
	if(Subtract(hugeInt1, hugeInt2, result, size1, size2)==true)
	{
		PrintHugeint(result,size1);
	}
	cout<<endl;
	system("pause");
}
void GetHugeInt(int hugeInt[], int& size)
{
	for (int i=0; i<size;i++)
	{
		cout<<"Enter digit # "<<i+1<<" of Number: ";
		cin>>hugeInt[i];
	}
}

void PrintHugeint(int hugeInt[], int size)
{
	for (int i=0;i<size;i++)
	{
		cout<<hugeInt[i];
	}
}

void Multiply(int hugeInt1[], int hugeInt2[], int result[], int s1, int s2)
{
	int multiple1=0,multiple2=0,count=0,finalMultiple=0,remainder,temp;
	for(int i=0;i<s1;i++)
	{
		multiple1=multiple1*10+hugeInt1[i];
	}
	for(int i=0;i<s2;i++)
	{
		multiple2=multiple2*10+hugeInt2[i];
	}
	finalMultiple=multiple1*multiple2;
	temp=finalMultiple;
	while(finalMultiple>0)
	{
		finalMultiple=finalMultiple/10;
		count++;
	}
	for(int i=count-1;i>=0;i--)
	{
		remainder=temp%10;
		result[i]=remainder;
		temp=temp/10;
	}
}

int Subtract(int hugeInt1[], int hugeInt2[], int result[], int s1, int s2)
{
	int num1=0,  num2=0, sub, temp,count=0,remainder,i;
	for(int i=0;i<s1;i++)
	{
		num1=num1*10+hugeInt1[i];
	}
	for(int i=0;i<s2;i++)
	{
		num2=num2*10+hugeInt2[i];
	}
	if (num1>num2)
	{
		sub=num1-num2;
		temp=sub;
		while(sub>0)
		{
			sub=sub/10;
			count++;
		}
		for( i=count-1;i>=0;i--)
		{
			remainder=temp%10;
			result[i]=remainder;
			temp=temp/10;
		}
		for (int j=count;j<20;j++)
		{
			result[j]=0;
		}
		return true;
	}
	else if (num1==num2)
	{
		cout<<"  Both arrays are Equal"<<endl;
	}
	else if (num1<num2)
	{
		cout<<"  Array 2 is greater than Array 1"<<endl;
	}
	return false;
}