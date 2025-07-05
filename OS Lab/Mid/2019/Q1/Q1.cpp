#include<time.h>
#include<iostream>
#include<fstream>
#include <unistd.h>
#include <string.h>
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
	unsigned short hr, min;
	char buff[512]={0};
	ifstream fin;
	pid_t pid;
	int pipefd[2];
	fin.open("tasks.txt");
	if (!fin.is_open())
	{
		cout<<"Unable to open tasks.txt.\n";
		return -1;
	}
	while (!fin.eof())
	{
		fin>>hr>>min>>buff;
		if (fin.eof())
			break;
		//cout<<"read values"<< hr<<" "<<min<<" " << buff<<endl;
		int rc = pipe(pipefd);
		if (rc == -1)
		{
			cout<<"Unable to create pipe.\n";
			return -1;
		}
		pid = fork();
		if (pid)
		{ //parents code
			close(pipefd[0]);
			write(pipefd[1],&hr,sizeof(unsigned short));
			write(pipefd[1],&min,sizeof(unsigned short));
			write(pipefd[1],buff, strlen(buff));
			close(pipefd[1]);
		}
		else
		{ //childs code
			unsigned short h;
			unsigned short m;
			char buf[512]={0};
			close(pipefd[1]);
			read(pipefd[0],&h,sizeof(short));
			read(pipefd[0],&m,sizeof(short));
			read(pipefd[0],buf, 511);
			close(pipefd[0]);
			cout<<getpid()<<" "<<h<<" "<<m<<" "<<buf<<endl;
			while(!is_time_equal_to_current_time(h,m));
			int rc2 = execlp(buf,buf,NULL);
			if (rc2==-1)
			{
				cout<<"Unable to exec!!!"<<endl;
				return -1;
			}
			return -1;
		}
		
	}


}

