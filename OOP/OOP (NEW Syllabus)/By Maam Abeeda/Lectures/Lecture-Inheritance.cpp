#include<iostream>
using namespace std;

//-----------------------------------------------------------------------------------------
//Person Class
//-----------------------------------------------------------------------------------------
class Person
{
private:
	char name[50];
	char cnic[20];	
public:
	Person(char*, char*);
	void PrintInfo();
	void SetValues(char*, char*);	
	char* GetName();
	~Person();
};
char* Person::GetName()
{
	return name;
}
Person::Person(char* _name = "", char* nic = "")
{
	strcpy_s(name, _name);
	strcpy_s(cnic, nic);
	cout << "Person Overloaded Constructor Called for " << name << endl;	
}
Person::~Person()
{
	cout << "~Person() Called for " << name << endl;
}

void Person::PrintInfo()
{
	cout << "Name:\t" << name << endl;
	cout << "CNIC:\t" << cnic << endl;	
}
void Person::SetValues(char* empName, char* nic)
{
	strcpy_s(name, empName);
	strcpy_s(cnic, nic);	
}
//-----------------------------------------------------------------------------------------
//Faculty Class
//-----------------------------------------------------------------------------------------
class Faculty : public Person
{
private:
	char designation[20];
public:
	
	Faculty(char*, char*, char*);
	void SetValues(char*, char*, char*);	//This is function Overloading not Overriding as parameters list is different from Base Class' SetValues
	~Faculty();
	void PrintInfo();	//This is function overriding as name and function parameters are same as that of base class
	char* GetDesignation(){return designation;}
};


Faculty::Faculty(char* _name = "", char* nic="", char* _designation="") :Person(_name, nic)	//Remove Members Initializer List and check the behavior
{
	cout << "Faculty Overloaded Constructor Called.\n";
	strcpy_s(designation, _designation);
}
void Faculty::SetValues(char* _name, char* nic, char* _designation) 
{
	Person::SetValues(_name, nic);
	strcpy_s(designation, _designation);
}
Faculty::~Faculty()
{
	cout << "~Faculty() "<<GetName()<< endl;		//Why don't we directly access name here?
}
void Faculty::PrintInfo()
{
	Person::PrintInfo();
	cout << "Designation:\t" << designation << endl;
}
//-----------------------------------------------------------------------------------------
// Class HourlyWorker
//-----------------------------------------------------------------------------------------
class HourlyWorker : public Person	//Member Access Specifier is Public. This is Public Inheritance
{
private:
	int workingHours;
	int wagePerHour;
public:
	HourlyWorker();
	HourlyWorker(char*, char*, int, int);
	void SetValues(char*, char*, int, int);	//This is function Overloading not Overriding as parameters list is different from Base Class' SetValues
	~HourlyWorker();
	void PrintInfo();	//This is function overriding as name and function parameters are same as that of base class
	int CalculatePay();	//HourlyWorker Specific Function, Child's functionality
};
int HourlyWorker::CalculatePay()
{
	return workingHours * wagePerHour;
}
void HourlyWorker::PrintInfo() //This is function overriding as name and function parameters are same as that of base class
{
	//PrintInfo();//This is recursive call i.e. function calling itself.
	Person::PrintInfo();	//We need to call parent's PrintInfo
	cout << "Total Working Hours :\t" << workingHours << endl;
	cout << "Wage per Hour :\t" << wagePerHour << endl;
	cout << "Total Payment:\t" << CalculatePay()<<endl;		//Child's functionality
}
HourlyWorker::~HourlyWorker()
{
	cout << "HourlyWorker Destructor Called for "<<GetName()<< endl;	//Why don't we directly access name here?
}
HourlyWorker::HourlyWorker(char* empName = "", char* nic= "", int workHrs=0, int wPh=0) :Person(empName, nic)
{
	cout << "HourlyWorker Overloaded Constructor Called.\n";
	workingHours = workHrs;
	wagePerHour = wPh;
}
void HourlyWorker::SetValues(char* empName, char* nic, int workHrs, int wPh) //This is function Overloading not Overriding as parameters list is different from Base Class' SetValues
{	
	Person::SetValues(empName, nic); //Notice this function call	
	workingHours = workHrs;
	wagePerHour = wPh;
}

//-----------------------------------------------------------------------------------------
// Main()
//-----------------------------------------------------------------------------------------
void main()
{
	//Add breakpoints in all above functions and debug to check the flow of execution.


	//Test 1 - Test Creation of object using default constructors
	cout<<"---------------------------------------------TEST 1--------------------------------------------\n";
	{
		Faculty f1;		//What will be order of Constructors and Destructors Calls?
		cout << "\n\n\n";	
	}

	//Test 2 - Test Creation of object using Overloaded Constructor and Members Initializer List
	cout<<"---------------------------------------------TEST 2--------------------------------------------\n";
	{
		Faculty f1;
		f1.SetValues("abc xyz", "1234567890", "lecturer");	//This is overloaded SetValues
		cout << "\n\n\n";
		f1.PrintInfo();
		cout << "\n\n\n";
	}

	//Test 3 - Calling Set Values of Base Class
	cout<<"---------------------------------------------TEST 3--------------------------------------------\n";	
	{
		Faculty f1;
		f1.Person::SetValues("abc xyz", "1234567890");	//This is inerited SetValues
		cout << "\n\n\n";
		f1.PrintInfo();
		cout << "\n\n\n";
	}

	////Test 4 - Test Inherited Behavior
	cout<<"---------------------------------------------TEST 4--------------------------------------------\n";	
	{
		Faculty f1;
		f1.SetValues("abc xyz", "1234567890", "lecturer");
		cout << "\n\n\n";
		cout<<"Name:\t"<<f1.GetName(); //GetName has been inherited from Parent Class
		cout << "\n\n\n";
	}

	////Test 5 - Calling Parent's PrintInfo using Child Object
	cout<<"---------------------------------------------TEST 5--------------------------------------------\n";	
	{
		Faculty f1;
		f1.SetValues("abc xyz", "1234567890", "lecturer");
		cout << "\n\n\n";
		f1.Person::PrintInfo();
		cout << "\n\n\n";
	}

	////Test 6 - Calling Child Specific Functionality
	cout<<"---------------------------------------------TEST 6--------------------------------------------\n";	
	{
		Faculty f1;
		f1.SetValues("abc xyz", "1234567890", "lecturer");
		cout << "\n\n\n";
		cout<<"Designation:\t"<<f1.GetDesignation();
		cout << "\n\n\n";
	}


	//////Test 7 - HourlyWorker is also a Person
	cout<<"---------------------------------------------TEST 7--------------------------------------------\n";	
	{
		HourlyWorker hw1("dummy Person", "111222333", 50, 500);	
		cout << "\n\n\n";
		hw1.PrintInfo();
		cout << "\n\n\n";
	}
}