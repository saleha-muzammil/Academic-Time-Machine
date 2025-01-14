#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/shm.h>
#include<string.h>
using namespace std;

int main()
{
	char buffer[1024]; 
	char c; 
	int count = 0, i = 0;
	
	ifstream fin;
	fin.open("InputAssign-1.txt");
	if(fin.fail())
	{
		cout << "Can't open file 'InputAssign-1.txt'!\n";
	}
	else
	{	
		while(!fin.eof())
		{
			fin.get(c);
			buffer[i] = c;
			i++;
		}
		fin.close();
		for(int j = 0 ; j < i ; j++)
		{
			if(buffer[j] == '\n')
			{
				break;
			}
			if(buffer[j] == ',')
			{
				count++;
			}
		}
		int rowCount = 0;
		for(int j = 0 ; buffer[j] != '\0' ; j++)
		{
			if(buffer[j] == '\n')
			{
				rowCount++;
			}
		}
		rowCount = rowCount-2; //No of Rows
		count++; //No of processes
		int j = 0, l =0;
		char fileName[50]; 
		pid_t pid; 
		int value = shmget(IPC_PRIVATE, 1024, 0666|IPC_CREAT | IPC_EXCL);
		int* val = (int*) shmat(value, NULL, 0);
		int* val2 = (int*) shmat(value, NULL, 0);
		for(int k = 0 ; k < count ; k++)
		{
		pid_t pid;
			pid = fork();
			int fd[2];
			int status = pipe(fd);
			
			if(pid == 0) //execution if it is child
			{	j = *val;
				while(buffer[j] != ',')
				{	if(buffer[j] == '\n')
					{
						break;
					}
					if(buffer[j] != ' ')
					{
						fileName[l] = buffer[j];
						l++;
					}
					j++;
				}
				fileName[l] = '\0';
				strcat(fileName,".txt");
				ofstream fout(fileName);
				fout.close();
				for(int m = 0 ; m <= l ; m++)
				{
					fileName[m] = '\0';
				}
				l = 0; 
				j++; 
				*val = j;
				exit(0);
			}
			wait(NULL);
		}
	}
	return 0;
}
