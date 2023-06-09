#include <iostream>
using namespace std;

int replace(int n)
{
    if(n==100)
      return 50;
    if(n==50)
      return 100;
}

int main()
{
	

	cout<<replace(100);

	return 0;
}