#include <iostream>
using namespace std;
int main(){
	int num,prev,next,d,diff,sub,a,neew,old,ratio,rato,com,e,b;
	sub = 0;
	prev = a = b = com = 0;
	num = 0;
	old = 1;
	cout<<"ENTER NUMBERS TO FIND SERIES"<<endl;
	for(int i=1; num!=-9999){
		cin >>num;
		next = num;
		d = next - prev;
		if(sub==d){
			a=a+1;
		}
		prev = next ;
		sub = d;
		ratio = 1;
		neew=num;
		e = neew / old;
		old = neew;
		if(com==e){
			b = b + 1;
		}
		com = rato;
	}
	if(a>=1){
		cout<<"series is arithmetic"<<endl;
	}
	else if(b>=1){
		cout<<"series is geometric"<<endl;
	}
	else{
		cout<<"not a series"
	}
system("PAUSE");
return 0;
}