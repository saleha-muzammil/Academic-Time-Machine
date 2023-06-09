#include <iostream>
using namespace std;


int main () {

	int num, i=1;
	int students=1000, lockers=1000;
	int lockerno=0;
	int studentno;
	int cl=0, ol=0;
	int x=0;
// true =open


	cout << "Enter nth student number: " << endl;
	cin >> studentno;

	cout << "Enter locker number: " << endl;
	cin >> lockerno;





	for (i=1;i<=1000;i=i+studentno) {

			if (lockerno%i==0) {ol=ol+1;
			x=x+i;}
			else {cl=cl+1;}
			

		}


	if (x%2==0) {cout << lockerno << " is closed. " << endl;}
	else if (x%2!=0) { cout << lockerno << " is open." << endl;}






	system ("pause");
	return 0;

}