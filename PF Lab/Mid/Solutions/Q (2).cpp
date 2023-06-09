#include<iostream>
using namespace std;

int main()
{
	int arr[10]={1,2,5,10,16,20,21,23,29,34};
	int size=13;
	int x=12;
	int num1=0;
	int num2=0;
	int sum=0;

	if(arr[0]<x)	//in a sorted array, first element should be less than x to pair with some other element
	{
		for(int i=0; i<size && arr[i]<x ; i++)
		{
			for(int j=0;j<size && arr[j]<x; j++)
			{
				if(j!=i)	//the pair should be 2 distinct numbers of array
				{
					if((arr[i]+arr[j]> sum) && (arr[i]+arr[j] <=x))		//condition for a considerable candidate
					{
						num1=arr[i];
						num2=arr[j];
						sum=num1+num2;
					}
				}
			}
		}
	
		cout<<"the pair closest to x is " << num1 << " and "<< num2<<endl;
	}
	else
		cout<<"No such pair exists"<<endl;
}
