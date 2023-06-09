#include <iostream>
using namespace std;


int main(){
	int num,c,value,powerOf2;

	c = 0;
	powerOf2 = 1;
	value = 0;

	do{
	
		cout << "Enter the Binary Digit "<<c<<": ";
		cin>>num;

		if (num >= 0) value = value + (powerOf2*num);

		powerOf2 *= 2;
		c++;

	}while(num >= 0);


	cout<<"The decimal number is: "<<value<<endl;



	system("PAUSE");
	return 0;
}