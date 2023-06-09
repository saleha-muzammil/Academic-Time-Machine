#include <iostream>
using namespace std;
int main()
{
	int k=0, k1=0, k2=0, i=0, dec=1, inc=1, num=0;
	bool m=1;

	cout<<"Enter the value of K "<<endl;
	cin>>k;
	cout<<"Enter the values: "<<endl;
	while (m) {
		cin>>k1;
		if (k1==-1) {
			break;
		}
		if (i!=0) {
			if (k2>k1) {
				dec++;
			}
			else if (k1>k2) {
				inc++;
			}
		}
		i++;
		if (k==i) {
			num=k1;
		}
		k2=k1;
	}
	if (dec==i) {
		cout<<"The "<<k<<"th largest element is: "<<num<<endl;
	}

	else if (inc==i){
		cout<<"The "<<k<<"th smallest element is: "<<num<<endl;
	}
	else {
		cout<<"The values are not sorted"<<endl;

	}



	return 0;
}
