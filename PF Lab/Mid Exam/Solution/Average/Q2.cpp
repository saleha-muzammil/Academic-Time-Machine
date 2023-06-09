#include <iostream>
using namespace std;
int main()
{
	int num=0,desired=0, a=0, b=0, i=0, count=0;
	cout<<"enter the integer value"<<endl;
	cin>>num;
	cout<<"enter the desired digit to find the place value of"<<endl;
	cin>>desired;
	while (num>=1) {
		i++;
		a=num%10;
		num=num/10;
		if (a==desired) {
			count=i;
			b=a;
		}
	}
	if (b==0) {
		cout<<"digit is not present in entered number"<<endl;
	}
	if (count==1){
		cout<<"Unit"<<endl;
	}
	else if (count==2){
		cout<<"Tens"<<endl;
	}
	else if (count==3){
		cout<<"Hundreds"<<endl;
	}
	else if (count==4){
		cout<<"Thousands"<<endl;
	}
	else if (count==5){
		cout<<"Ten thousands"<<endl;
	}
	else if (count==6){
		cout<<"Hundred thousands"<<endl;
	}
	else if (count==7){
		cout<<"Millions"<<endl;
	}
	else if (count==8){
		cout<<"Ten Millions"<<endl;
	}



	return 0;
}
