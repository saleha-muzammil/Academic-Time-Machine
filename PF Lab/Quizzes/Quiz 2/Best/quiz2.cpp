#include <iostream>
using namespace std;

int isPrime(int fib)
{
	int isPrime=1;
	int r;
	if (fib==0||fib==1)
	{
		isPrime=0;
	}
	for (int i=2; i<fib; i++)
	{
		r=fib%i;
		if (r==0)
		{
			isPrime=0;
			break;
		}
	}
	return isPrime;
}

int fibbionaci(int n)
{
	int fn=0;
	if (n==1)
	{
		return fn;
	}
	else if (n==2||n==3)
	{
		fn=1;
		return fn;
	}
	else
	{
		int n2=1,n3=1,nth;
		for(int i=4; i<=n; i++)
		{

			nth=n2+n3;
			int temp=n3;
			n3=nth;
			n2=temp;
		}
		//fn=n3;
		return nth;
	}
	
}



int main()
{
	
	int total=1;
	int fibnum=1;
	while(total<=5)
	{
		int fib=fibbionaci(fibnum);
		fibnum++;
		int Prime=isPrime(fib);
		if (Prime==1)
		{
			cout<<fib<<" ";
			total++;
		}
	}



	cout<<endl;
	system("PAUSE");
	return 0;
}