#include <iostream>
using namespace std;

int main(){
	int number;
	cout<<"Input number";
	cin>>number;
	int outputted = 0;
	int original_number = number;
	int required_digit ;
	cout<<"Input number whose place value is to be determined :";
	cin>>required_digit;
	int highest_power = 0;
	int current_ten = 1;
	int current_power = 0;
	
	while (number-current_ten > 0)
	{
		current_ten = current_ten*10;
		highest_power = highest_power+1;
	}
	highest_power = highest_power-1;
	int previous_subtracted_number = 0;
	current_power = highest_power	;
	while (outputted != 1 && original_number-previous_subtracted_number >0 && current_power >=0)
	{
			int current_sub_number = 1;
			int current_digit = -1;
			
		for (int i = current_power; i > 0; i--)
		{
			current_sub_number = current_sub_number*10;
		}
		number = number-previous_subtracted_number;
		while (number >= 0)
		{
			number = number-current_sub_number;
			current_digit = current_digit+1;
		}
		if (current_digit == required_digit && outputted == 0)
		{
			switch (current_power)
			{
			case 0:
				cout<<current_digit<<" has a place value of Units"<<endl;
				 outputted = 1;
				break;
			case 1:
				cout<<current_digit<<" has a place value of Tens"<<endl;
							 outputted = 1;
				break;
			case 2:
				cout<<current_digit<<" has a place value of hundreds"<<endl;
							 outputted = 1;
				break;
			case 3:
				cout<<current_digit<<" has a place value of thousands"<<endl;
							 outputted = 1;
				break;
			case 4:
				cout<<current_digit<<" has a place value of ten thousand"<<endl;
							 outputted = 1;
				break;
			case 5:
				cout<<current_digit<<" has a place value of hundred thousand"<<endl;
							 outputted = 1;
				break;
			case 6:
				cout<<current_digit<<" has a place value of millions"<<endl;
							 outputted = 1;
				break;
			case 7:
				cout<<current_digit<<" has a place value of ten million"<<endl;
							 outputted = 1;
				break;

			default:
				break;
			}
		}


		




		number = original_number;
		previous_subtracted_number = previous_subtracted_number+(current_sub_number*current_digit);
		current_power = current_power-1;

	}
	return 0;

	}




	
