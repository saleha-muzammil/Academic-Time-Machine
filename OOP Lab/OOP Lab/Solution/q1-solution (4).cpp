#include<iostream>
#include<conio.h>
using namespace std;
class MobilePhone
{
protected:
	int* Battery;
	bool* Camera;
	char* OSversion;
public:
	MobilePhone()
	{
		Battery = nullptr;
		Camera = nullptr;
		OSversion = nullptr;
	}
	MobilePhone(int battery, bool camera, char*osversion)
	{
		Battery = new int[1];
		Battery[0]= battery;
		Camera = new bool[1];
		Camera[0] = camera;
		OSversion = new char[strlen(osversion) + 1];
		int i = 0;
		for (i = 0; i <= strlen(osversion); i++)
			OSversion[i] = osversion[i];
		OSversion[i] = '\0';
	}
	virtual ~MobilePhone()
	{
		cout << "~MobilePhone() called" << endl;
		if (OSversion != nullptr)
			delete[] OSversion;
		if (Battery != nullptr)
			delete[] Battery;
		if (Camera != nullptr)
			delete[] Camera;
	}
	virtual void PrintInfo()
	{
		cout << "Battery	" << *Battery << endl << "OS Version	" << *OSversion << endl;
		if (*Camera)
			cout << "Camera:	yes" << endl;
		else
			cout << "Camera:	no" << endl;
	}

};
class OnlineStore
{
	char* name;
	MobilePhone* listOfPhones;
public:
	OnlineStore()
	{
		listOfPhones = new MobilePhone[10];                                                                                                              
		name = nullptr;
	}
	void SetName(char* arr)
	{
		name = new char[strlen(arr) + 1];
		int i = 0;
		for (i = 0; i <= strlen(arr); i++)
			name[i] = arr[i];
		name[i] = '\0';
	}
	~OnlineStore()
	{
		cout << "~OnlineStore() called"<<endl;
		if (name != nullptr)
			delete[] name;
		if (listOfPhones != nullptr)
			delete[] listOfPhones; 
	}
	template<class T> void addPhone(T mobile)
	{
		if (NumberOfPhones < 10)
		{
			listOfPhones[NumberOfPhones] = mobile;
			NumberOfPhones++;
		}
		else
			cout << "You cannot add more phones!! " << endl;
	}                                                                                                 
	void printAvailablePhones()
	{
		for (int i = 0; i < NumberOfPhones; i++)
			listOfPhones[i].PrintInfo();
	}
	static int NumberOfPhones;                                                                        
};
int OnlineStore:: NumberOfPhones = 0;

class Android :MobilePhone
{
	int* Ram;                                                                                                                                                                                                                                   
public:
	Android()
	{
		Ram = nullptr;
	}
	Android(int ram, int battery, bool camera, char*osversion) :MobilePhone(battery, camera, osversion)
	{
		Ram = new int[1];
		Ram[0] = ram;
	}
	~Android()
	{
		cout << "~Android() called()" << endl;
		if (Ram != nullptr)
			delete[] Ram;
	}
	void PrintInfo()
	{
		MobilePhone::PrintInfo();
		cout << "Ram	" << *Ram << endl;
	}
};
class iPhone:MobilePhone
{
	bool* audioJack;
public:
	iPhone()
	{
		audioJack = nullptr;
	}
	iPhone(bool aj, int battery, bool camera, char*osversion) :MobilePhone(battery, camera, osversion)
	{
		audioJack = new bool[1];
		audioJack[0] = aj;
	}
	~iPhone()
	{
		cout << "~iPhone() called()" << endl;
		if (audioJack != nullptr)
			delete[] audioJack;
	}
	void PrintInfo()
	{
		MobilePhone::PrintInfo();
		if (*audioJack == true)
			cout << "Audio Jack:	yes" << endl;
		else
			cout << "Audio Jack:	no" << endl;
	}
};