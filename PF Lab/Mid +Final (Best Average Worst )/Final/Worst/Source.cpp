#include<iostream>
using namespace std;
void getHugeInt(int HugeInt[],int &size){
	int i;
	
	for(i=0;i<size;i++){
		cout<<"Enter Digit # "<<i+1<<" of Number: ";
		cin>>HugeInt[i];
	}

}

void printHugeInt(int HugeInt[],int size){
	int i=0;
	for(i=0;i<size;i++){
		cout<<HugeInt[i];
	}cout<<endl;
}

void multiply(int HugeInt[],int HugeInt2[],int result[],int s1,int s2){
	int a,sum=0,sum1=0,y=1;
	for (int i=0;i<s1;i++){
		int b=0;
		b=HugeInt[i];
		b=b*y;
		sum=sum+b;
		y=y*10;
	}

	for (int i=0;i<s2;i++){
		int z=0;
		z=HugeInt2[i];
		z=z*y;
		sum1=sum1+z;
		y=y*10;
	}
	

	for(int i=0,j=0;i<s1,j<s2;i++,j++){
			for(int k=0;k<s1+s2;k++){
				result[k] = HugeInt[i]*HugeInt2[j];
			}
		}

}
   

void subtract(int HugeInt[],int HugeInt2[],int result[],int s1,int s2){
			int k=0;
		
	for(int i=0,j=0;i<s1,j<s2;i++,j++){
		for (int p=0;p<s1;p++){
			
			result[p]=HugeInt[i]-HugeInt2[j];}}

}
int main(){
	int HugeInt1[20],HugeInt2[20],result[40]={0};
	int size1,size2,resultSize;

	/////////size 1 input////////////
	cout<<"Enter The size of HugeInt1"<<endl;
    cin>>size1;
		if(size1>20|| size1<0){
			cout<<"Size CAnt Be greater Than 20"<<endl;
		  cin>>size1;
		}  

	//////////taking Hugeint1 and printing////
 	getHugeInt(HugeInt1,size1);
	cout<<"The Huge You Entered:"<<endl;
	printHugeInt(HugeInt1,size1);

	/////////size 2 input////////////
    cout<<"Enter The size of HugeInt2"<<endl;
    cin>>size2;
		if(size2>20 || size2<0){
			cout<<"Size CAnt Be greater Than 20"<<endl;
		    cin>>size2;
		}	

	//////////taking Hugeint2 and printing////
	getHugeInt(HugeInt2,size2);
	cout<<"The Huge You Entered:";
	printHugeInt(HugeInt2,size2);

	multiply(HugeInt1 , HugeInt2 , result,size1, size2);
	cout<<"The Multiply Result is: "<<endl;
	printHugeInt(result , size1 + size2);

	subtract(HugeInt1 , HugeInt2 , result,size1, size2);
	cout<<"The Subtract Result is: "<<endl;
	printHugeInt(result,size1);


system("pause");
return 0;
}
