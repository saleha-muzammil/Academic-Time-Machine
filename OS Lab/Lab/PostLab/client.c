#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main(int argc, char* argv[])
{
	if (argc > 2)
	{
		printf("more arguments than expected, exitting now");
		return -1;
	}
	char* readFromFile;
	//Open file in fd.
	int fd = open(argv[1], O_RDONLY);
	//Create shared memory
	int key = shmget(112233, sizeof(char)*1024, IPC_CREAT | IPC_EXCL | 0666);
	//Attach shared memory
	readFromFile = (char*)shmat(key, NULL, 0);
	//Read into shared memory
	read (fd, readFromFile, sizeof(char)*1024);
	//Detatch portion of shared memory
	shmdt(readFromFile);
	
	return 0;
}
