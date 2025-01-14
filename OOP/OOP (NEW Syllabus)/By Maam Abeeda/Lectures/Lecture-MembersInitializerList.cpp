#include<iostream>
using namespace std;

class A
{
private:
	int a;
protected:
	int protectedData;
public:
	A(int,int);
	~A();
	void PrintInfo();
};
A::A(int temp1, int temp2) :a(temp1), protectedData(temp2)//This is Members Initializer List
{
	cout << "A() Called.\n";
	cout << "a = " << a << endl;
	cout << "ProtectedData = " << protectedData << endl;
}
A::~A()
{
	cout << "~A() Called.\n";	
}
void A::PrintInfo()
{
	cout << "a = " << a << endl;
	cout << "ProtectedData = " << protectedData << endl;
}

void main()
{
	A objA(5, 10);
}