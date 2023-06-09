#include <iostream>
using namespace std;
void getHugeInt(int HugeInt[], int &size)
{
	while(size>!20)
	{
		cout<<"Enter the size: ";
		cin>>size;
	}
for(int i=0;i<size;i++)
{
	cout<<"Enter element "<<size;
	cin>>HugeInt[size];
}
}
void printHugeInt(int HugeInt [], int size[])
{   int size1;
	getHugeInt(HugeInt, size1);
}

void multiply(int HugeInt1[], int HugeInt2[], int result[], int s1, int s2)
{	
      int k;
	cout<<"Enter the Size of array 1 ";
	cin>>s1;
	getHugeInt(HugeInt1, s1);
	cout<<"Enter the size of array 2 ";
	cin>>s2;
	getHugeInt(HugeInt2, s2);
	for( k; k<s1+s2;k++)
	{
		result[k] = HugeInt1[s1]*HugeInt2[s2];
		cout<<"Result is "<<result[k];
	}
}
void subtract(int HugeInt1[], int HugeInt2[], int result[], int s1, int s2)
{
	int i,j,k;
	cout<<"Enter the Size of array 1 ";
	cin>>s1;
	cout<<"Enter the size of array 2 ";
	cin>>s2;
	for( i=0;i<s1;i++)
{
	cout<<"Enter element "<<s1<<endl;
	cin>>HugeInt1[i];
}
	for( j=0; j<s2; j++)
	{
	cout<<"Enter the element "<<s2<<endl;;
	cin>>HugeInt2[j];
}
	for(k=0; k<s1;k++ )
	{
	result[k]= HugeInt1[s1]-HugeInt2[s2];
	}

}
void main()
{
	int HugeInt1[20], HugeInt2[20], result[40] = {0};
	int size1, size2, resultSize=0;
	getHugeInt(HugeInt1, size1);
	cout<<"The HugeInt you entered: ";
	printHugeInt(HugeInt1, size1);
	getHugeInt(HugeInt2, size2);
	cout<<"The HugeInt you entered is: "<<endl;
	printHugeInt(HugeInt2, size2);
	multiply(HugeInt1, HugeInt2, result, size1, size2);
	cout<< "Multiply Result is: "<<endl;
	printHugeInt(result, size1, size2);
	subtract(HugeInt1, HugeInt2, result, size1, size2);
	cout<< "Subtract Result is: ":
	printHugeInt(result, size1);
}


