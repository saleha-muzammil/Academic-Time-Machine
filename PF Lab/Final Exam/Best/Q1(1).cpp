# include <iostream>
# include <math.h>
using namespace std;
float getStandardDeviation(float arr[], int size);
float getAverage(float arr[], int size);
void printData(float arr[], int size);
void inputArray(float arr[], int size);
float percent(float arr[], int size, float average, float stdev);



void main()
{
	float data[10];
	int size=10;
	inputArray(data, size);
	printData(data, size);
	float average=getAverage(data, size);
	float std=getStandardDeviation(data, size);
	cout<<average<<endl<<std<<endl;
	float per=percent(data, size, average, std);
	cout<<per<<endl;
	if((per>65) && (per<75))
		cout<<"Good Bell Shape"<<endl;
	else
		cout<<"Bad Bell Shape"<<endl;


	/*int size=5;
	float dev;
	dev=getStandardDeviation(array, size);
	cout<<dev;*/


	
}


float getStandardDeviation(float arr[], int size1)
{
	int N=size1;
	float sum=0;
	float xi=2; //single value
	float avgX;
	float s;
	float x;
	
	avgX= getAverage(arr, N);
	
	x=((sum((xi-avgX)*(xi-avgX)))/(N-1));
	s=sqrt(x);
	return s;

}

float getAverage(float array1[], int size);
{ 

	float sum=0;
	float average;
	for(int i=0; i<size; i++)
	{
		sum=sum+array1[i];
	}
	average=sum/size;
	
	return average;
	
}

float percent(float arr[], int size, float average, float stdev)
{
	int count=0;
	float percentage;
	for(int i=0; i<size; i++)
	{
		if((arr[i]>(average-stdev))&&(arr[i]<(average+stdev)))
			count++;
	}

	percentage=(float)(count/size)*100;

	return percentage;


}

void inputArray(float arr[], int size)
{
	
	cout<<"Enter nums from 0 to 99 : "<<endl;
	for(int i=0; i<10; i++)
	{   
		cin>>arr[i];
	
	}


}

void printData(float arr[], int size)
{
	cout<<"Data is : ";
	for(int i=0; i<10; i++)
	{
		cout<<arr[i]<<endl;
	}

}