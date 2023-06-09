#include <iostream>
using namespace std;


int main(){
	int num,copy,original_num,first_digit,reverse;
	reverse = 0;

	cout << "Input any number: ";
	cin>>num;
	cout<<num<<endl;

	original_num = num;
	while(1){//Strippping Zeros

		first_digit = num % 10;

		if(first_digit == 0){ 
			num /= 10;

		}else break;


		
	}


	copy = num;
	while(copy > 0){//Revese Number

		first_digit = copy % 10;

		if(first_digit == 0){continue;}

		reverse = reverse*10 + first_digit;

		copy/=10;
	}

	if(reverse == num){
		cout << original_num<<"("<<num <<")" <<" is palindrome";
	} else{
		cout << original_num <<" is not a palindrome";
	}

	cout<<endl;
	system("PAUSE");
	return 0;
}