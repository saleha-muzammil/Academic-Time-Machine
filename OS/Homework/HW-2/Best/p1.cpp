#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <fstream>
#include <sys/shm.h>
#include<semaphore.h>
#include<stdlib.h>

using namespace std;


#define SIZE 10
int lineno=0;
int totallines=0;

void filedown(int& lineno,int totallines)
{
	//system("clear"); 
	//cout<<"in file up"<<endl;
	ifstream fin("inputAssign-2.txt");
	char buffer[80];
	if(lineno+10<totallines)
	{
		system("clear"); 
		for(int i=0;i!=lineno+11;i++)
		{
			fin.getline(buffer,80);
			if(i>lineno)
			{
				cout<<buffer<<endl;	
			}
			
	
		}
	lineno++;
	}
	fin.close();
	
	
	



}
void fileup(int& lineno,int totallines)
{	
	//system("clear"); 
	ifstream fin("inputAssign-2.txt");
	char buffer[80];
	int temp=lineno;
	if(lineno!=0)
	{
		system("clear"); 
		for(int i=0;i!=lineno+9&&i<totallines;i++)
		{
			fin.getline(buffer,80);
			if(i+1==temp)
			{
				cout<<buffer<<endl;;	
				temp++;
			}
			
	
		}
	lineno--;
	}
	else
	{
	system("clear");
	for(int i=0;i<10;i++)
	{	
		fin.getline(buffer,80);
			
		cout<<buffer<<endl;
				
	}
	}
	fin.close();

}

void* getinput(void *vptr_value)
{
	int shmid = shmget((key_t) 99 , SIZE ,  IPC_CREAT|0666);
	char * shm_Ptr = (char*) shmat(shmid , NULL , 0);

	char* temp;
	while(*shm_Ptr!='x')
	{
		temp=shm_Ptr;
		
		if(*shm_Ptr==0)
		{
			
			cin>>*shm_Ptr;
			
			*(shm_Ptr+1)='1';
				if(*shm_Ptr=='u')
				{
					fileup(lineno,totallines);
				}
				else if(*shm_Ptr=='d')
				{
					filedown(lineno,totallines);
					//system("clear"); 
				}
			
			
		}
		
	}


}



int main(int argc, char const *argv[])
{	ifstream in("inputAssign-2.txt");
	
	/*creating a shared memory segmant*/
	int shmid = shmget((key_t) 99 , SIZE ,  IPC_CREAT|0666);
	
	char buffer[80];
	 totallines=0;
	while (in.getline(buffer, 80))
        ++totallines;
	
	//cout<<totallines<<" Total lines are"<<endl;
	in.close();
	
	
	cout<<"Total lines are:"<<totallines;
	/*checking for errors*/
	if (shmid == -1 )
	{
		cout<<"failed to create shared memory segment"<<endl;
		return -1;
	
	}
	
	ifstream fin("inputAssign-2.txt");

	char * shm_Ptr = (char*) shmat(shmid , NULL , 0);
	

	
	*shm_Ptr = 0;

	//We dont need extra pointer for indexing because after strcpy the pointer does not move
	//so we will write  using this shm_ptr

	system("clear"); 
	//cout<<"Process 1 running ..."<<endl<<endl;
	
	
	
	for(int i=0;i<10;i++)
	{
		
		fin.getline(buffer,80);
		cout<<buffer<<endl;
		
	} 
	fin.close();
	char input;
	char * process = shm_Ptr + 1;

	
	

	//int lineno=0;


	pthread_t tid;
	pthread_create(&tid, NULL, getinput,NULL);
	//pthread_join(tid,NULL);
	//char input;
	int count=0;
	while(*shm_Ptr!='x')
	{
		
			
		if(*shm_Ptr==0)
		{
			//cout<<"in if";
			//while(*shm_Ptr==0)
			//{}
			
			//*shm_Ptr=input;
			//input='1';
			//*process=input;
		
			//sem_wait(mutex2);
			count=0;
		}
		else
		{
			if(count==0)
			{
				
			
				
				count++;
			}
			//cout<<"in else"<<endl;
			if(*(shm_Ptr+1)=='2')
			{	
				//sem_wait(mutex2);
				if(*shm_Ptr=='u')
				{
					fileup(lineno,totallines);
				}
 				else if(*shm_Ptr=='d')
				{
					filedown(lineno,totallines);
					//system("clear"); 
				}
				*process=0;
				*shm_Ptr=0;
				//sem_post(mutex);
			}
			
			
			//*shm_Ptr=0;
		}
		 			
	}
	
	shmdt(shm_Ptr);
	
	return 0;
}
