#include <iostream>
using namespace std;

int isPrime(int &sum){
	int prime;
	int count;
	count = 0;
	for(int i=2; i<sum; i++){
	prime = sum % i;
	if(prime == 0){
		count = count + 1;
	}
	}
	return count;
}

int Fibonacci(int &a,int &b){
 int sum;

 a= 0;
 b =1;

	sum= a + b;
	a = b;
	b = sum;
	
 return sum;
 }
			  
int main(){
	int prime,fabprime,a,b,sum;
	a =sum =0;
	b = 1;
	for(int m=1; m<=12; m++){
		fabprime=Fibonacci(a,b);
		prime=isPrime(sum);
		if(prime>=1){
			prime = prime;
		}
		else {
			cout<<fabprime<<endl;
		}
	}
system("PAUSE");
return 0;
}		 