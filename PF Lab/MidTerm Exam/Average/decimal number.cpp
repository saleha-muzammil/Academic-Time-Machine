#include <iostream>
using namespace std;
int main(){
	int digit,rem,sum,pro,power;
	power=1;
	digit = sum = 0;
	cout<<"enter binary digit"<<endl;
	for(int i=1; digit!=-1; i++){
		cin >>digit;
		rem = power * digit;
		sum = sum + rem;
		power = power + power;
	}
	cout<<"THE DECIMAL NUMBER IS ";
	cout<<sum<<endl;
	system("PAUSE");
	return 0;
}