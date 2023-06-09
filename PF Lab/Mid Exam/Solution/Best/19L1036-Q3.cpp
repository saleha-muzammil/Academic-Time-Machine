#include<iostream>

using namespace std;

int main()
{
	int locker,student,n,i,x,counter=0,open=0,close=0;
	cout<<"	Enter no of lockers : ";
	cin>>locker;
	cout<<"	Enter no of students : ";
	cin>>student;
	for(i=1;i<=student;i++)
	{
		for(n=1;n<=locker;n++)
		{
			if(n%i==0)
			{
			counter++;
			}
		}
	if(counter%2==0)
		close++;
	else if(counter%2==1)
		open++;
	
	}
	cout<<"	No of open locker = "<<open<<endl;
	cout<<"	No of closed locker = "<<close<<endl;
	system("pause");
	return 0;
}