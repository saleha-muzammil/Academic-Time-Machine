#include <iostream>
using namespace std;

int main() { 


	float num=0, pnum;
	float numk, i=1, x;
	bool NegInput=false, isAscending=false, isDescending=false;
	float smallnum=0, bignum;
	float klarge, ksmall;

	cout << "Enter value of K" << endl;
	cin >> numk;

	x=numk+1;

	cout << "Enter a unique number: " << endl;
	cin >> num;
	bignum=num;
	
while (num>=0 && NegInput==false) {
																	//ASSUMING VALUES ENTERED WILL NOT REPEAT AT ALL AND USER WILL ENTER AT LEAST K+1 values before entering a negative number
pnum=num;                                                              


if (num<0 && i>=x) {

	NegInput=true; }



cout << "Enter a unique number: " << endl;
cin >> num;

i++;

if (i==numk) { ksmall=num; klarge=num;}
if (num>bignum) {
	smallnum=bignum;
	bignum=num;

} else if (smallnum>num) {smallnum=num;}


if (num>pnum) {isAscending=true;} else {isDescending=true;}

pnum=num;


}

if (isAscending) {cout << "Ascending order. "<< endl;
cout << numk << "th" << " " << "smallest element is: " << ksmall << endl; }
else if (!isAscending) { cout << "Descending order. " << endl;
cout << numk << "th" << " " << "largest element is: " << klarge << endl;}
else {cout << "Not in sorted order. " << endl;}






system ("pause");
return 0;


}
