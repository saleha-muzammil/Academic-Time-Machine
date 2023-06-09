#include <iostream>
using namespace std;

int main(){
	
	int num_of_lockers ;
	cout<<"Enter number of lockers";
	cin>>num_of_lockers;
	int students = num_of_lockers;
	int num_of_divisible = 0;
	int increment = 1;
	for (int k = num_of_lockers; k > 0; k--)
	{

		 increment = 1;
	for (int j = 1; j < k; j++)
	{
		int num_of_div = 0;
		for (int i = increment; i<=j ; i = i+increment)
		{
			if (j % i ==0 )
			{
				num_of_div = num_of_div+1;	
			}
			
		}
		increment = increment+1;
		if (num_of_div % 2 == 0 && num_of_div > 0)
				{
					num_of_divisible = num_of_divisible+1;
				}

	}
	}
	cout<<"Number of open lockers is :"<<num_of_divisible;
	return 0;

	}




	
