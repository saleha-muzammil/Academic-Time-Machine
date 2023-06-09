#include<iostream>
using namespace std;
int main(){
	int s1[500],i,j=0;
	int num,num2;
	for(i=0;i<num&&num!=0;i++){
       cout << "enter the number"<<i+1<<endl;
	   cin >>s1[i];
	}
	int temp;
	for(i=0,j=i+1;i<num,j<num;i++,j++){
	
		if(s1[i]==s1[j]){
		 temp=s1[i];
		 s1[j]=s1[i];
		 s1[j]=temp;
		
		}
	cout<<s1[i];
	
	}
	cout<<"enter the number to find value";
	cin >>num2;
	if(num2==1){
	cout<<s1[0];
	}
	if(num2==2){
	cout<<s1[1];
	}
	if(num2==3){
	cout<<s1[2];
	}
	if(num2==4){
	cout<<s1[3];
	}
	if(num2==5){
	cout<<s1[4];
	}
	else{
	cout<<"Donot find in the list";
	}
	system("pause");
	return 0;


}