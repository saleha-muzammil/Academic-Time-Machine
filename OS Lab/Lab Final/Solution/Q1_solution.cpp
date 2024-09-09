#include<iostream>
using namespace std;
#include<stdio.h>
#include<time.h>
#include<pthread.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<cstring>

sem_t s1 ;
int PID[5] = 1234;

pthread_mutex_t mymutex;

void* myFunc(void* param)
{
 mymutex_lock(&a);
 
 //ifstream fn;
ofstream fo;

//fn.open("logfile.txt");

/*
if(fn.is_open())
{	while(!fn.eof() ){
	fn>> a;
	arr[ind] = a;
	ind++;
	}
	cout<<endl<<endl;
}

else 
{
	cout<<"Error opening the file"<<endl;
}
*/

fo.open("logfile.txt");
if(fo.is_open())
{
	fo<<"PID = ";
	fo<< PID;	
	fo<< "; "
	PID++;
	time_t rawtime;
	struct tm *timeinfo;
	
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	
	fo<<"Current local time and date: ";
	fo<< asctime(timeinfo);

}
else 
{
	cout<<"Error opening the file"<<endl;
}
	
 mymutex _ unlock(&a);

pthread_exit( (void*) a);
}

int main()
{
	int a=atoi(argv[1]);

	char arr[100];
	char a= ' ';
	int ind= 0;
	
	 pthread_t id;
	 int a ;
	 for(int i = 0 i < a;a++){
	if (pthread_create(&id, NULL, &myFunc, &a)==-1)
	  {
	      cout<<"Thread Creation Failed!"<<endl;
	      return 1;
	  }
  }
  for(int i = 0 i < a;a++){
	 int *ptr;
	  pthread_join(id, (void**) &ptr);
  }
	return 0;
}


