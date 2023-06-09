#include <iostream>
using namespace std;

int main() {


	int num;
	int digit, y;
	bool match=false;
	int x=10, mult=10;     //modulus won't work with double integer type thus assuming input will fit in int 
	// ASSUMING ALL DIGITS ENTERED WILL BE UNIQUE NO REPETITIONS
	cout << "Enter a number: "<< endl;
	cin >> num;

	cout << "Enter the digit whose place you want to know: " << endl;
	cin >> digit;


	while (!match && num>9) {
		
		if (num%x==digit)  {

		match=true;} else {x=x*10;}

	num=num/x; 
}

	if (x==1) { cout << "Units" << endl;}
	else if (x==10) { cout << "Tens" << endl;}
	else if (x==100) { cout << "Hundreds" << endl;}
	else if (x==1000) { cout << "Thousands" << endl;}
	else if (x==10000) { cout << "Ten Thousands" << endl;}
    else if (x==100000) { cout << "Hundred Thousands" << endl;}
    else if (x==1000000) { cout << "Millions" << endl;}
	else if (x==10000000) { cout << "Ten Millions" << endl;}


	system ("pause");
	return 0;
}