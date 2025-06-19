#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main()
{
	int pid;
	pid = fork();
	
	if (pid == 0)
		if (pid % 2 == 0)
			printf("Process id is odd\n");
		else
			printf("Process id is even\n");
	else
		if (pid > 0)
			printf("Process id is: %d \n", pid);
		else
			cout << "error in creating task";

	return 0;
}
