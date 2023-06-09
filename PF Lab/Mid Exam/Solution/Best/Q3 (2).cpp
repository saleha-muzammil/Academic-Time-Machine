#include<iostream>
using namespace std;
int main()
{
	float number,diff,ratio,sum,number1,number2,number3,temp;
	bool art=true,geo=true,fib=false;

cout<<"ENTER THE NUMBER 1";
cin>>number1;
while(number1==-9999)
{
	cout<<"ENTRE THE THREE VALUES ATLEAST enter again ";
	cin>>number1;
}

cout<<"ENTER THE NUMBER 2";
cin>>number2;
while(number2==-9999)
{
	cout<<"ENTRE THE THREE VALUES ATLEAST enter again ";
	cin>>number2;
}
diff=number2-number1;
ratio=number2/number1;
sum=number1+number2;
cout<<"ENTER THE NUMBER 3";
cin>>number3;
while(number3==-9999)
{
	cout<<"ENTRE THE THREE VALUES ATLEAST enter again  ";
	cin>>number3;
}

int counter=4;
temp=number3;
number=1;
while(number!=-9999)
{
cout<<"ENTER THE NUMBER "<<	counter++;
cin>>number;
if(number==-9999)
break;
if(temp+sum==number)
{
fib=true;
}
else
	fib=false;


 if( number-temp==diff)
{
	art=true;
}
 else 
	 art=false;
if ( number/temp==ratio)
{
geo=true;

}
else geo=false;
}
if(fib==true)
{
cout<<"THIS IS FIIBONACHI SERIES\n";
}
if (geo==true)
	cout<<"THIS IS GEOMETRIC SERIES\n";
if (art==true)
	cout<<"ARITHEMATIC SERIES\n";


system("pause");
return 0;
}