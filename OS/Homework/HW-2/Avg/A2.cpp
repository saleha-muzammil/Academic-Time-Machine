#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

int main()
{
	int key = shmget(12345, sizeof(sem_t), IPC_CREAT | IPC_EXCL | 0666);
	int process = 1;
	
	if (key < 0)
	{
		key = shmget(12345, sizeof(sem_t), 0666);
		process = 2;
	}
	
	if (process == 1)
	{
		char str[200];
		char c;
		sem_t *sem = (sem_t *) shmat(key, NULL, 0);
		ifstream input("inputAssing-2.txt");
		
		cout << "Input File: \"inputAssign-2.txt\"" << endl
			 << "#######################################################################" << endl;
		
		for (int i = 0; i < 10 && !input.eof(); i++)
		{
			input.getline(str, 200, '\n');
			cout << str << endl;
		}
		
		cout << "#######################################################################" << endl;

		cout << "\nWaiting for second process" << endl;
		sem_wait(sem);
		
		cout << "Enter option (u for scroll up, d for scroll down, x for exit): ";
		cin >> c;
		
		if (c == 'x' || c == 'X')
		{
			shmdt(sem);
			shmctl(key, IPC_RMID, NULL);
			sem_post(sem);
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		char str[200];
		sem_t *sem = (sem_t *) shmat(key, NULL, 0);
		ifstream input("inputAssing-2.txt");
		
		cout << "Input File: \"inputAssign-2.txt\"" << endl
			 << "#######################################################################" << endl;
		
		for (int i = 0; i < 10 && !input.eof(); i++)
		{
			input.getline(str, 200, '\n');
			cout << str << endl;
		}
		
		cout << "#######################################################################" << endl;
		
		sem_post(sem);
		
		shmdt(sem);
		sem_wait(sem);
		exit(EXIT_SUCCESS);
	}
	
	return 0;
}
