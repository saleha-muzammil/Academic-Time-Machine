#include<iostream>
using namespace std;
int main(){
int num1,num2,s1[50000];
cout<<"Please enter the total digits you want to display";
cin>>num1;
for(int i=0;i<num1;i++){
cout<<"Enter the number"<<i+1<<endl;
cin>>s1[i];
}
cout<<"the value is:";
for(int i=0;i<num1;i++){
	cout<<s1[i];
}
cout<<"enter the value to determine its position:";
cin>>num2;
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
if(num2==6){

	cout<<s1[5];
}
if(num2==7){

	cout<<s1[6];
}
else {
  cout<<"value doesnot found";

}

}
