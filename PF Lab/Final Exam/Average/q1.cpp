#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
void inputarray(float a[],int size)
{
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
	}
	cout<<"data :";
for(int i=0;i<size;i++)
{
	cout<<a[i]<<",";
}

}

float getaverage(float a[],int s)
{
	float sum=0;
	float average;

	for(int i=0;i<s;i++)
	{
		sum=sum+a[i];
	}
	average=sum/s;
	cout<<average;

	return 0;
}
float getstandarddeviation(float a[],int s)
{
	int i;
	float sum=0;
	int n=s;
	float avg=getaverage(a,s);
	float s;
	float ss;
	for(int i=0;i<s;i++)
	{
		sum=sum+a[i];
	}
	ss=pow((sum-avg),2);
	s=sqrt(ss/(n-1));
	cout<<ss;
	return 0;
}

int main()
{
	float data[10]={42,34,69,79,6,82,6,95,61,28};
	int size;
	int s;
	float a[100];
	cout<<"size of array :"; 
	cin>>s;
	inputarray(a,s);
	getaverage(data,s);


	system("PAUSE");
	return 0;
}