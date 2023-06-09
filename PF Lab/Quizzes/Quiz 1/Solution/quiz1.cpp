#include <iostream>
using namespace std;
int main()
{
	float sub1,sub2,sub3,sub4,sub5,sum,prt;
	
	cout<<"Enter subject 1 marks ";
	cin>>sub1;
	cout<<"Enter subject 2 marks ";
	cin>>sub2;
	cout<<"Enter subject 3 marks ";
	cin>>sub3;
	cout<<"Enter subject 4 marks ";
	cin>>sub4;
	cout<<"Enter subject 5 marks ";
	cin>>sub5;
	
	sum=sub1+sub2+sub3+sub4+sub5;
	
	prt=(sum/500)*100;
	
	cout<<"Marks Obtained in Sub1: "<<sub1<<endl;
	cout<<"Marks Obtained in Sub2: "<<sub2<<endl;
	cout<<"Marks Obtained in Sub3: "<<sub3<<endl;
	cout<<"Marks Obtained in Sub4: "<<sub4<<endl;
	cout<<"Marks Obtained in Sub5: "<<sub5<<endl;
	
	cout<<"Total Percentage of Student:"<<prt<<endl;
	
	
return 0;


}