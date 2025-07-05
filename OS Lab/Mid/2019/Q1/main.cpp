#include<iostream>
 #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include <stdlib.h>
using namespace std;
short is_time_equal_to_current_time(unsigned short hour, unsigned short minutes)
{
	time_t my_time;
	struct tm * timeinfo; 
	time (&my_time);
	timeinfo = localtime (&my_time);
	if (hour > 23 || minutes > 60)
	{
		cout<<("Hour or minutes out of range.Returning -1!!!\n");
		return -1; 
	}
	if( hour == timeinfo->tm_hour && minutes == timeinfo->tm_min)
		return 1;
	else return 0;
}

int main()
{
	int fd=open("tasks.txt",O_RDONLY);
	if(fd<0)
	{
		cout<<"File doesn't exist"<<endl;
		return 1;
	}
	char buffer[500];
	int s=read(fd,buffer,500);
	int count=0;
	for(int i=0;i<s;i++)
	{
		if(buffer[i]=='\n')
		{
			count++;
		}
	}
	
	char *token=strtok(buffer,"\n");
	char **arr=new char*[count-1];
	int i=0;
	while(token!=NULL)
	{
		arr[i]=new char[strlen(token)+1];
		strcpy(arr[i],token);
    	//cout<<token<<endl;
    	token=strtok(NULL,"\n");
    	i++;
	}
	for(int i=0;i<count;i++)
	{
		cout<<arr[i]<<endl;
	}
	
	for(int i=0;i<count;i++)
	{
		int fd[2];
		pipe(fd);
		pid_t pid;
		pid=fork();
		if(pid==0)
		{
			close(fd[1]);
			char data[50];
			int s=read(fd[0],data,50);
			
			//cout<<data<<endl;
			
			char *token=strtok(data," ");
			int hour=atoi(token);
			cout<<"Hour: "<<hour<<endl;
			token=strtok(NULL," ");
			int min=atoi(token);
			cout<<"Minute: "<<min<<endl;
			token=strtok(NULL,"\n");
			cout<<token<<endl;
			
			
			while(true)
			{
				if(is_time_equal_to_current_time(hour,min)==1)
				{
					execlp(token,token,NULL);
				}
			}
			
		}
		else if(pid>0)
		{
			
			close(fd[0]);
			write(fd[1],arr[i],strlen(arr[i])+1);
			
		}
	}
	
	return 0;
}
