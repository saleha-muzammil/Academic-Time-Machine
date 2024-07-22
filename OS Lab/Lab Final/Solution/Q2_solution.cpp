#include<iostream>
using namespace std;
#include<stdio.h>
#include<time.h>
#include<pthread.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<cstring>

struct car
{
	char make[16];
	int year ;
	int price;
};
int records = 5;

void Display(car &obj )
{
	file.seekg(0);
	int r = 0;
	while(r!=records)
	{
		file.read((char*) &c, sizeof(car));

	}
}
void add(car &obj)
	{
		file.write((char*)&obj,sizeof(car));
		records = records +1;
		
	}
	
void Replace (car &obj, index)
{	
	file.seekg(ind);
	file.write((char*)&obj,sizeof(car));
}
int main (int argc, char*argv[])
{
/*
pthread_t id;
 char a ;
	 
if (pthread_create(&id, NULL, &myFunc, &a)==-1)
  {
      cout<<"Thread Creation Failed!"<<endl;
      return 1;
  }
  
 int *ptr;
  pthread_join(id, (void**) &ptr);
 
*/

car c1 ,c2,c3,c4,c5;
	char m[16]; int y, p;
	//add(c[0])	;	
	//Display(c[0]);
	
	c1.make = "BAC";
	c1.year = 2015;
	c1.price = 5000000;
	
	c2.make = "Vauxhall";
	c2.year = 2010;
	c2.price = 750000;
	
	c3.make = "Nissan";
	c3.year = 2014;
	c3.price = 1200000;
	
	c4.make = "Ariel Atom";
	c4.year = 2015;
	c4.price = 2000000;
	
	c5.make = "Caterham";
	c5.year = 1999;
	c5.price = 100000;
	

fstream file("record.bin", ios::binary | ios::in | ios::out| ios::trunc);
if(!file.is_open())
{
	cout<<"Error Opening the file" <<endl;
}
else
{

	file.write((char*)&c1,sizeof(car));
	file.write((char*)&c2,sizeof(car));
	file.write((char*)&c3,sizeof(car));
	file.write((char*)&c4,sizeof(car));
	file.write((char*)&c5,sizeof(car));
	
	file.seekg(0);
	


car c;

while(1)
{
	int choice ;
	cout<< "1. Add \n 2.Replace \n 3.Display \n 4 Exit"<<endl;
	cout<<"Enter your choice : ";
	cin>> choice;
	cout<<endl;
	if(choice == 4)
	{
		exit(1);
		return ;
	}
	else if(choice ==1 )
	{
		cout<< "1. Add" <<endl;
		cout<< "Enter make: ";
		cin>> m;cout<<endl;
		cout<<"Enter year: ";
		cin>> y;cout<<endl;
		cout<<"Enter price: ";
		cin>> p;cout<<endl;
		strcpy(c.make, m);
		c.year = y;
		c.price = p; int ind;
		add(c1);
		
	}
	else if(choice ==2)
	{
		cout<< "Enter make: ";
		cin>> m;cout<<endl;
		cout<<"Enter year: ";
		cin>> y;cout<<endl;
		cout<<"Enter price: ";
		cin>> p;cout<<endl;
		strcpy(c.make, m);
		c.year = y;
		c.price = p; int ind;
		cout<< "Enter index to replace the record: ";
		cin>> ind;cout<<endl;
		
		
		Replace(c,ind );
		
	}
	else if (choice ==3)
	{
		Display();
	}
}
	


		file.close();
}


}



