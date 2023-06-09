#include<iostream>
using namespace std;
int findPattern(char arr[],char sub[]){
	int index=1;
	bool found=true;
	for (int i=0; i<10;i++){
		int y=0;
		while(arr[i]!='/0'){
		if(arr[i]==sub[y]){
			index=1;
	     found =true;
		}
		else if(arr[i]!=sub[y]){
					index =-1;
					found=false;
		}
				
	}
}
	return index;
			
}

void main(){
	char arr[]="Hello I am muslim i am going to lahore";
	char pattern[]="Hello lahore";
	int index=findPattern(arr,pattern);
	if (!index){
		cout<<"pattern not found";}
	else{
		cout<<"pattern found";}



system("pause");
return 0;
}