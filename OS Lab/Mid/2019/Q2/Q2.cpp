#include<iostream>
 #include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<pthread.h>
#include <unistd.h>

using namespace std;

struct Data
{
	char *buffer;
	int size;
};

void *myFunc(void *param)
{

	char *fname=(char*)param;
	int fd=open(fname,O_RDONLY,S_IRUSR | S_IWUSR);
	int size=lseek(fd,0,SEEK_END);
	Data *obj=new Data;
	
	obj->buffer=(char *)mmap(NULL,size,PROT_READ,MAP_SHARED,fd,0);
	obj->size=size;
	pthread_exit((void *)obj);
}
int main(int n,char *argv[])
{
	pthread_t *id=new pthread_t[n-1];
	Data **obj=new Data*[n-1];
	
	for(int i=0;i<n-1;i++)
	{
		if(pthread_create(&id[i],NULL,&myFunc,argv[i+1])==-1)
		{
			cout<<"Thread Creation Failed"<<endl;
		}
		
	}
	
	for (int i = 0; i < n-1; i++)
	{
	
		Data *temp;
		pthread_join(id[i],(void**)&temp);
		obj[i]=temp;
	
	}
	
	int fd=open("output.txt",O_CREAT | O_RDWR ,S_IRUSR | S_IWUSR);
	
	int totalsize=0;
	for(int i=0;i<n-1;i++)
	{
		totalsize+=obj[i]->size;
	}
	
	ftruncate(fd,totalsize);
	
	char *buffer=(char *)mmap(NULL,totalsize,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
	int k=0;
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<obj[i]->size;j++)
		{
			buffer[k]=obj[i]->buffer[j];
			k++;
		}
	}
	
	munmap(buffer,totalsize);
	close(fd);
	//unmapping all the input files
	for(int i=0;i<n-1;i++)
	{
		munmap(obj[i]->buffer,obj[i]->size);
	}
	return 0;

}
