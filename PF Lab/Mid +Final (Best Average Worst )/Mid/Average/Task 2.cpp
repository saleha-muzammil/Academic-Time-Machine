#include <iostream>
using namespace std;

int main(){
	int numoflockers=0, z=1, count=0, count2=0;
	cout<<"Please enter the total number of lockers: ";
	cin>>numoflockers;

	while(numoflockers>=0){
	
		while(z<=numoflockers){
	     if(numoflockers%z==0){
			 count=count+1;
			}
		 z=z+1;
		}
		if(count%2==0){
			count2=count2+1;
		}
		count=0;
		z=1;
		numoflockers=numoflockers-1;
	}
	
	
	
	
		cout<<"The number of opened lockers are: "<<count2<<endl;
	
		
system("pause");
 return 0;
}