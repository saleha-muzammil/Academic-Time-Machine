#include<iostream>
using namespace std;
int main()
{int num,y,i,multiple,x,r,sum=0;
cout<<"enter number";
y=num;
i=1;
while(y>0){
	x=1;
	multiple=1;
	r=y%10;
	y=y/10;
	for(int j=1;j<1;j++){
		multiple=multiple*10;}
	x=r*multiple;
	sum=sum+x;
	i++;}
if(sum=num)
{cout<<num<<"number is palindrome";}
else
{cout<<num<<"number is palindrome";}
cout<<endl;
system("pause");
return 0;}
