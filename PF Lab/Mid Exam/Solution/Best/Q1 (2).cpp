#include<iostream>
#include<cmath>
using namespace std;
int main()
{
int number,counter=-1,sum=0,ower=0,count=0;
while(true)
{

cout<<"ENTER THE "<<count<<" NUMBER\n";
cin>>number;
if(number==-1)
	break;
counter++;
}
cout<<pow(2,counter);
system("pause");
return 0;
}