#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main(int args, char const** arg0)
{
	system(*arg0);
	
	int pid3 = fork();
	if (pid3 == 0)
	{
		printf("within 3rd child, running command 'ls -S'\n process id of this process is %d\n\n", getpid());
		char const* args3 = "ls -S\0";
		execlp("./t3", args3, NULL);
	}

	return 0;
}
