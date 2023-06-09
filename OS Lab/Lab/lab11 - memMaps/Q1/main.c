#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sys/mman.h>
#include <pthread.h>
#include <fcntl.h>
using namespace std;

struct arguments
{
	char* ptr;
	bool firstHalf;
};

void* Convert(void* args)
{
	arguments mainArgs = *(arguments*) args;
	int startIX = 0, endIX = 50;
	if (mainArgs.firstHalf == false)
	{
		startIX = 51; endIX = 100;
	}
	for (int i = startIX; mainArgs.ptr[i] != '\0' && i < endIX; i++)
	{
		char temp = mainArgs.ptr[i];
		if (temp >= 65 && temp <= 90)
		{
			mainArgs.ptr[i] += 32;
		}
		else
		{
			if ( temp >= 97 && temp <= 122)
			{
				mainArgs.ptr[i] -= 32;
			}
			else
			{
				if (temp >= 48 && temp <=57)
				{
					if (temp == 48)
						mainArgs.ptr[i] = 'Z';
					else
						if (temp % 2 == 0)
							mainArgs.ptr[i] = 'E';
						else
							mainArgs.ptr[i] = 'O';
				}
				else
				{
					mainArgs.ptr[i] = ' ';
				}
			}
		}
	}


}

int main(int argc, char** argv)
{
	pthread_t t1, t2;
	int sizeF = 100;
	if (argc != 2)
	{
		cout << "wrong number of arguments passed, exitting now\n";
		exit(-1);
	}
	int fd = open(argv[1], O_RDONLY);
	arguments argsParse1, argsParse2;
	argsParse1.ptr = argsParse2.ptr = (char*)mmap(NULL, sizeF, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	argsParse1.firstHalf = true;
	argsParse2.firstHalf = false;
	pthread_create(&t1, NULL, &Convert, &argsParse1);
	pthread_create(&t2, NULL, &Convert, &argsParse2);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	sleep(1);
	cout << "This is the final string:\n" << argsParse1.ptr << endl;
	munmap(argsParse1.ptr, sizeF);
	close(fd);

	return 0;
}
