#include <iostream>
using namespace std;

void main()
{
	int K, count=0,check=0;
	float usersInput,number,smallest=0,largest=0;
	cout<<"Enter value of K : ";
	cin>>K;
	cout<<"Input the Values : ";
	cin>>usersInput;
	number=0;
	while (usersInput!=-1)
	{
		if (usersInput>number)   //smaller case
		{
			if (count==K)
			{
				smallest=number;
			}
			count++;
			number=usersInput;
			cin>>usersInput;
		}
		else if (usersInput<number)  //larger case
		{
			if (count==K)
			{
				largest=number;
			}
			count++;
			number=usersInput;
			cin>>usersInput;
		}
		else 
		{
			cout<<"The values are not is sorted order "<<endl;
			check=1;
		}
	}
		if(smallest!=0 && check!=1)
		{
			cout<<"The "<<K<<"nd Smallest Number is : "<<smallest<<endl;
		}
		else if (largest!=0 && check!=1)
		{
			cout<<"The "<<K<<"nd largest Number is : "<<largest<<endl;
		}
	system("pause");
}