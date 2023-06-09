# include <iostream>
using namespace std ;
int main()
{
	int num=0,a=0,sum=0,b=1,s=0;
	cin>>num;
	while(num!=0)
	{
		a=num%10;
		sum=a*b;
		b=b*10;
		s=sum+a;
		num=num/10;
	}
	if(s=num)
		cout<<"it is pailindrome number";
	else
		cout<<"not a pailindrome number";
	system("pause");
	return 0;
}