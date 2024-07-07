#include<iostream>
using namespace std;

class A
{
	int a; //Its access is private by default
protected:
	int protectedData;
public:
	A();
	~A();
	void PrintInfo();
};
A::A()
{
	cout << "A() Called.\n";
	a = 10;
	protectedData = 100;
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
//----------------------------------------------------------------------------------
class B : public A
{
	int b; //Its access is private by default
public:
	B();
	~B();
	void PrintInfo();
};
B::B()
{
	cout << "B() Called.\n";
	protectedData = 200;	//Overwriting the protected member which is accessible in this scope.
	b = 20;	
}
B::~B()
{
	cout << "~B() Called.\n";
}
void B::PrintInfo()
{
	A::PrintInfo();
	cout << "b = " << b << endl;	
}
//----------------------------------------------------------------------------------
class C : public B
{
	int c; //Its access is private by default
public:
	C();
	~C();
	void PrintInfo();
};
C::C()
{
	cout << "C() Called.\n";
	protectedData = 300;	//Overwriting the protected member which is accessible in this scope.
	c = 30;
	//b = 2000;	//b is private data of B which is not directly accessible here
}
C::~C()
{
	cout << "~C() Called.\n";
}
void C::PrintInfo()
{
	B::PrintInfo();
	cout << "c = " << c << endl;
}

void main()
{
	C objC;
	objC.PrintInfo();
	//cout << objC.protectedData;	//Protected data is not accessible here
}