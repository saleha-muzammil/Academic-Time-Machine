#include<iostream>
#include<math.h>
using namespace std;
void inputarray(float arr[], int size)
{
	cout<<"Enter elements of the array:"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}


}//input function ends

float getaverage(float arr[],int size)
{
	for(int j=0;j<size;j++)
	{
	float average=arr[j];
	
	float temp= average+arr[j+1];
	float totalaverage=temp/size;
	return totalaverage;
	}

}//average ends

float getstandardeviation(float arr[],int size,float average1)
{
	float s,N,xi=arr[0],x_avrg=average1;
	N=size;
	s=sqrt(N*(xi-x_avrg)*(xi-x_avrg)/N-1);
	return s;
}//standard deviation ends


float percentage(float arr[],int size,float average,float std)
{int count=0;
	for (int j=0;j<size;j++)
	{
	if(arr[j]>(average -std))
	{
		count++;
	}	
	if(arr[j]<(average -std))
	{
		count++;
	}	
	
	float per=(count/size)*100;
	return per;

	}


}//perecntage ends



void main()

{
	float data[10];
	int size=10;
	inputarray(data,size);
	float average=getaverage(data,size);
	float std=getstandardeviation(data,size,average);
	cout<<average<<endl<<std<<endl;
	float per=percentage(data,size,average,std);
	cout<< per <<endl;
	if (per>65 && per>75)
	cout<<"it is the good bell shape"<<endl;
	else
		cout<<"it is the bad bell shape"<<endl;


}//main body ends