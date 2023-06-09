#include <iostream>
using namespace std;

int main(){
	float number,previous_number;
	previous_number = -200000000;
	int k;
	cout<<"Input the value of K : ";
	cin>>k;
	cout<<"Input the values: ";
	int values = 0;
	int ascending = 0;
	int descending = 0;
	do{
		cin>>number;
		values = values+1;
		if (number> previous_number)
		{
			ascending = ascending+1;
		}
		if(number < previous_number){
			descending = descending +1;
		}

		previous_number = number;
	}while(number <= -1 && values >k );




	return 0;
}