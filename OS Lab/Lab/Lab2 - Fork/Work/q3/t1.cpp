#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main(int args, char const** arg0)
{
	system(*arg0);
	
	int pid2 = fork();
	if (pid2 == 0)
	{
		//second child
		//run command 2
		printf("within 2nd child, running command 'mkdir -p ./myFolder/mySF'\n process id of this process is %d\n\n", getpid());
		char const* args2 = "mkdir -p ./myFolder/mySF\0";
		execlp("./t2", args2, NULL);
	}

	return 0;
}
