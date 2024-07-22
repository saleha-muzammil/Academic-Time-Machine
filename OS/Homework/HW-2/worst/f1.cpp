#include<iostream>
#include <semaphore.h>
#include <sys/shm.h>
#include <queue>
#include<fstream>
#include<pthread.h>
#include <string.h>
using namespace std;
class S
{
public:
  int flag;
  int counter;
  char input;
};
void* fun1(void* param)
{
	 S *f2=(S*) param;
	S *update=new S;
   cout<<"enter the input"<<endl;
   cin>>update->input;
   update->flag=1;
   if(update->input=='d' && f2->counter<40)
   {
   update->counter=f2->counter+1;
   }
   else if(update->input=='u' && f2->counter>0)
   {
     update->counter=f2->counter-1;
   }
   return (void*) update; 
  //do not use exit routine, it will terminate the whole process
}
void* fun2(void *p2)
{
	 S *f2=(S*) p2;
	 cout<<f2->input;
	 cout<<f2->counter;
	 cout<<f2->flag;
	 cout<<"outer loop"<<endl;
	 ifstream fin;
	 fin.open("inputAssign-2.txt");
	 if(fin.is_open())
	 {
	 cout<<"file is open"<<endl;
	 }
	 int a;
	 int arr[50];
	 fin>>a;
	 int i=0;
	 while(!fin.eof())
	 {
		 arr[i]=a;
		 fin>>a;
		 i++;
	 }
	 cout<<f2->input<<endl;
	 if(f2->input=='d')
	 {
		 int index=f2->counter;
		 int index1=index+10;
		 cout<<"index="<<index<<endl;
		 while(index<=index1)
		 {
			 cout<<arr[index]<<' ';
			 cout<<"ali";
			 index++;
		 }
	 }
	else if(f2->input=='u')
	 {
		 int index=f2->counter;
		 for(;index<=f2->counter+10;index++)
		 {
			 cout<<arr[index]<<' ';
		 }
	 }
	 else if(f2->input==' ')
	 {
	  int index=f2->counter;
		 for(;index<=f2->counter+10;index++)
		 {
			 cout<<arr[index]<<' ';
		 }
	 }
}
int main()
{
   S *buffer;

 int id_sem=shmget(980, 1024, 0666 | IPC_CREAT | IPC_EXCL);
 int id_cs= shmget(981, 1024,  0666| IPC_CREAT | IPC_EXCL);

  sem_t *semaphore;
 
  if (id_sem==-1 || id_cs==-1)
 {
   
    cout<<"ERROR!";
    return 1;
  }
  semaphore= (sem_t*) shmat(id_sem, NULL, 0);
   cout<<"id of sem"<<id_sem<<endl;
   buffer= (S*) shmat(id_cs, NULL, 0);
   buffer[0].flag=0;
   buffer[0].counter=0;
   buffer[0].input=' ';
   S std;
   pthread_t id[2];
   S *updatedStd;
 sem_init(semaphore, 1, 1); //1 means semaphore is used for process synchronization, count is 1 (only one process will be allowed at a time)
  while(1){
  
  std=buffer[0];
  pthread_create(&id[0], NULL, &fun1, &std);
  pthread_join(id[0], (void**) &updatedStd);
  buffer[0]=*updatedStd;
  if(buffer[0].input=='x')
  {
  break;
  }
  pthread_create(&id[1], NULL, &fun2, &buffer[0]);
  
  pthread_join(id[1], (void**) &updatedStd);
  
  }
  sem_destroy(semaphore);
 shmdt(semaphore);
  shmdt(buffer);
  shmctl(id_sem, IPC_RMID, NULL);
  shmctl(id_cs, IPC_RMID, NULL);
  return 0;
}
  
