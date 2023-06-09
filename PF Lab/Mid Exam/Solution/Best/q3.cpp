#include <iostream>
using namespace std;

void main()
{
	int count=1, totalDigits=0, number, remainder, users_input, originalNumber, place=1;
	int found=0;
	cout<<"Enter Number : ";
	cin>>number;
	originalNumber=number;
	while (number !=0)
	{
		totalDigits++;
		number=number/10;
	}
	cout<<"Enter Digit to find place value : ";
	cin>>users_input;
	remainder=originalNumber%10;
	originalNumber=originalNumber/10;
	while (count<=totalDigits)
	{
		if (users_input==remainder)
		{
			found=1;
			break;
		}
		count++;
		remainder=originalNumber%10;
		originalNumber=originalNumber/10;
		place =place*10;
		
	}
	if (place==1  && found==1)
	{
		cout<<users_input<<" is on \"Units\" place"<<endl;
	}
	else if (place==10 && found==1)
	{
		cout<<users_input<<" is on \"Tens\" place"<<endl;
	}
	else if (place==100 && found==1)
	{
		cout<<users_input<<" is on \"Hundred\" place"<<endl;
	}
	else if (place==1000 && found==1)
	{
		cout<<users_input<<" is on \"Thousand\" place"<<endl;
	}
	else if (place==10000 && found==1)
	{
		cout<<users_input<<" is on \"Ten Thousand\" place"<<endl;
	}
	else if (place==100000 && found==1)
	{
		cout<<users_input<<" is on \"Hundred Thousand Place\" place"<<endl;
	}
	else if (place==1000000 && found==1)
	{
		cout<<users_input<<" is on \"Million\" place"<<endl;
	}
	else if (place==10000000 && found==1)
	{
		cout<<users_input<<" is on \"Ten Million\" place"<<endl;
	}
	else if (found==0)
	{
		cout<<"Digit is not present "<<endl;
	}
	system("pause");
}