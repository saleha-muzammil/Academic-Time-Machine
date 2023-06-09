#include <iostream>
using namespace std;

void main()
{
	int locker,divisors,count,opened, num1,num2;
	cout<<"Enter Number of lockers : ";
	cin>>locker;
	opened=locker;
	divisors=locker/2;
	count=1;
	locker=locker/2;
	while (divisors>=1)
	{
		locker--;
		divisors=locker/divisors;
		count++;
	}
	divisors=opened/2;
	cout<<"Number of students are : "<<count<<endl;
	while (divisors<=1)
	{
		divisors--;

	}
	system("pause");
}