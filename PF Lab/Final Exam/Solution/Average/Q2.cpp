#include <iostream>//system pause not added into code, when running please press SHIFT+F5
using namespace std;
void getHugeInt ( int HugeInt[], int&size);
void printHugeInt(int HugeInt[], int size);
void multiply(int HugeInt1[],int HugeInt2[], int result[], int s1, int s2);
void subtract (int HugeInt1[],int HugeInt2[], int result[], int s1, int s2) ;

int main() {
	int HugeInt1[20], HugeInt2[20], result[40]= {0};
	int size1, size2, resultSize=0;
	getHugeInt(HugeInt1, size1);
	cout<<"The HugeInt you entered is: ";
	printHugeInt(HugeInt1, size1);

	getHugeInt(HugeInt2, size2);
	cout<<"The HugeInt you entered is: ";
	printHugeInt(HugeInt2, size2);

	multiply(HugeInt1, HugeInt2, result , size1, size2);
	cout<<"Multiply result is: ";
	printHugeInt(result, size1+size2);

	subtract(HugeInt1,HugeInt2,result, size1, size2);
	cout<<"Subtraction result is: ";
	printHugeInt(result,size1);




	return 0;
}

void getHugeInt ( int HugeInt[], int&size) {
	cout<<"Enter the size of HugeInt: ";
	cin>>size;
	for (int i=0; i<size; i++) {
		cout<<"Enter the digit #"<<i+1<<" of Number: ";
		cin>>HugeInt[i];
	}

}
void printHugeInt(int HugeInt[], int size) {
	int n=0;
	for (int i=0; i<size; i++) {
	
		n+= HugeInt[i];
		n=n*10;
	}
	n=n/10;
	cout<<n<<endl<<endl;
}


void multiply(int HugeInt1[],int HugeInt2[], int result[], int s1, int s2) {
	int a=0;
	for (int i=0;i<s1; i++) {
		for (int j=0; j<s2; j++) {
			result[a]=HugeInt1[i]*HugeInt2[j];
			a++;
		}
	}
}


	
void subtract (int HugeInt1[],int HugeInt2[], int result[], int s1, int s2) {
	int i=s1-1;
	while (i>=0) {
		s1--;
		s2--;
		if ((s2>=0)&&(s1>=0)) {
			result[i]= HugeInt1[s1]-HugeInt2[s2];
		}
		if ((s2>=0)&&(s1<0)){
			result[i]=HugeInt1[s1];
		}

		i--;
		s1--;
		s2--;
	}

}