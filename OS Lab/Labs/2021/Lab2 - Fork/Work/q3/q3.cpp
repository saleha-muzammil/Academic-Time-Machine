#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main()
{
	int pid1 = fork();
	if (pid1 == 0)
	{
		//first child
		//run command 1
		printf("within 1st child, running command 'mkdir ./myF1 ./myF2'\n process id of this process is %d\n\n", getpid());
		char const * args1 = "mkdir ./myF1 ./myF2\0"; 
		execlp("./t1", args1, NULL);
	}

	return 0;
}
