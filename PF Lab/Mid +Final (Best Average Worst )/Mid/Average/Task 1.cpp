#include <iostream>
using namespace std;

int main(){
	int k=0, count=0;
	float k2=0, z=0, zstore=0;
	cout<<"Please enter the value you want to find: ";
	cin>>k;
	cout<<"Please start to enter the values: ";
	cin>>k2;
	bool same=false, same2=false, sameorder1=false, sameorder2=false;
	z=k2;
	while(k2>=0 && z>=0){
		
		if(z>k2){
			sameorder2=true;
			k2=z;
			if(count==k-1){
				zstore=k2;
			same=true;
		}
		}
			if(z<k2){
				sameorder1=true;
				k2=z;
				if(count==k-1){
					zstore=k2;
					same2=true;
				}
			}
		count=count+1;
		cout<<"Enter values: ";
		cin>>z;
	}
	if(same==true && sameorder2==true && sameorder1==false){
		cout<<"The "<<k<<" smallest element is "<<zstore<<". "<<endl;
	}
	if(same2==true && sameorder2==false && sameorder1==true){
		cout<<"The "<<k<<" smallest element is "<<zstore<<". "<<endl;
	}
	else{
		cout<<"The numbers are not in sorted order."<<endl;
	}

system("pause");
 return 0;
}