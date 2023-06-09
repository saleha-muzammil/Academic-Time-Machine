# include <iostream>
using namespace std;
float percentage(float arr[],int s,float average,float stddev);
float getstd(float arr[],int s);
void inputarray(float arr[],int s);
float getaverage(float arr[],int s);
void printdata(float arr[],int s)
{
	for(int i=0;i<s;i++)
	{
	cout<<arr[i]<<" ";
	}
	cout<<endl;

}
float percentage(float arr[],int s,float average,float stddev)
{
  float count=0.0;
  float a=average-stddev;
  float b=average+stddev;
  for(int i=0;i<s;i++)
  {
    if(arr[i]>a && arr[i]<b)
		count++;
  }
  float perc=(count/s)*100;
  return perc;
}
float getstd(float arr[],int s)
{
	float sum=0.0,a=0.0,val=0.0,std=0.0,ss=0.0;
	
   for(int i=0;i<s;i++)
   {
     sum=sum+arr[i];
   }
   float avg=sum/s;
   float sum1=0.0;
   for(int i=0;i<s;i++)
   {
	   float num=s;
	   sum1=sum1+arr[i];
     a=arr[i]-avg;
	 a=a*a;
	 val=sum1*a;
	 num=num-1;
	 std=val/num;
	 ss=pow(std,0.5);
   return ss;
   }
   
}
float getaverage(float arr[],int s)
{
	int count=0;
	float sum=0.0;
    for(int i=0;i<10;i++)
	{
	   sum=sum+arr[i];
	   count++;
	}
	 float avg=sum/count;
	 return avg;
}
void inputarray(float arr[],int s)
{
	int i=0;
   while(i!=s)
   {
	    cin>>arr[i];
    if(arr[i]>=0 && arr[i]<=99)
	{
	  i++;
	}
	else
		cout<<"wrong input enter again\n";
   }
}
void main()
{
	float data[10];
	int size=10;
	cout<<"enter the elements of array from 0-99\n";
	inputarray(data,size);
	printdata(data,size);
	float average=getaverage(data,size);
	float std=getstd(data,size);
	cout<<average<<endl<<std<<endl;
	float per=percentage(data,size,average,std);
	cout<<per<<endl;
	if(per>65 && per<75)
		cout<<"good bell shape\n";
	else
		cout<<"bad bell shape\n";
	system ("pause");
}