#include <iostream>
using namespace std ;
int m , j  , n , t;
int findpattern(char str[] , char pattern[])
{
	while (m=0)
	{

	for (int j=0 ; j < 10000 ; j++)
	{
		if (pattern[j] == '*')
		{
			 j = m ;
		}
		
	}
	}
	while (n = 0)
	{

	for (int m = j ; m < 10000; m++)
	{
		if (pattern[m] == '*')
		{
			m=n;
		}

	}
	}
	return 0;
}

int main() 
{
	
	char str [10000] = {} ;
	char arr [10000] = {} ;
	char pattern [10000] = {} ;
	char sub [10000] = {} ;
	cout << "str: " ;
	cin >> str[10000];


	for (int j = 0 ; j < 10000 ; j++)
	{
		cin >> pattern [j];
	}
 int findpattern (char str[] , char pattern []);
return 0;
}
