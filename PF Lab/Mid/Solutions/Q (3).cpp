#include<iostream>
#include<conio.h>
using namespace std;

int SecondLargest()
{
	int in = 0,max1=0,max2=0,i=1;
		cout << "Input Integers and -1 to stop."<<endl;
		cin >> in;
		max1 = in;
		while (in != -1)
		{
		
			cin >> in;
			if (max1 < in)
			{
				max2 = max1;
				max1 = in;
				
			}
			if (in<max1&&in>max2)
			{
				max2 = in;
			}


			i++;
		}
		if (i > 2)
		{
			return max2;
		}
		if (i <= 2)
		{
			return -1;
		}

}


int main()
{
	int large;
	large = SecondLargest();
	if (large != -1)
	{
		cout << "The \"Seconf Largest\" element is \"" << large << "\".";
	}
	if (large == -1)
	{
		cout << "There is no \"Second Largest\" element.";
	}


	_getch();
}