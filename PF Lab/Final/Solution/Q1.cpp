# include <iostream>
using namespace std;
int main()
{
	int length=0;
	cout<<"Enter the length of string ";
	cin>>length;
	char *C_string;
	C_string=new char [length+1];
	cout<<"Enter a string ";
	cin>>C_string;
	int sum=0;
	for (int i=0;i<length;i++)
	{
		sum=sum+C_string[i]-48;
	}
	delete []C_string;
	cout<<sum<<endl;
	system("pause");
	return 0;
}