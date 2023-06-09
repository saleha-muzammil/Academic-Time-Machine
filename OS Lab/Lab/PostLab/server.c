#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int convertArr(char* source, int* destination)
{
	char temp[20];
	int i = 0;
	int k = 0;
	for (int j = 0; source[j] != '\0'; j++)
	{
		k = 0;
		for (j; source[j] != '\n' && source[j] != '\0'; j++)
		{
			temp[k++] = source[j];
		}
		temp[k] = '\0';
		destination[i++] = atoi(temp);
	}	
	return i;
}
double average(int sum, int n)
{
	return (sum * 1.0)/(n * 1.0);
}
int sum(int* arr, int n)
{
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		count+= arr[i];
	}
	return count;
}

int main()
{
	char* readFromFile;
	//Get existing shared memory.
	int key = shmget(112233, sizeof(char)*1024, 0);
	//Attatch shared memory
	readFromFile = (char*)shmat(key, NULL, 0);
	//Main working of program
	int arr[50];
	int i = convertArr(readFromFile, arr);
	int arr1[50];
	//Removing duplicates here
	int check = -1;
	int ix = 0;
	for (int j = 0; j < i; j++)
	{
		check = 1;
		for (int k = 0; k < ix; k++)
		{
			if (arr[j] == arr[k])
			{
				check = -1;
				break;
			}
		}
		if (check == 1)
		{
			arr1[ix++] = arr[j];
		}
	}
	printf("Duplicates removed!\n");
	for (int x = 0; x < ix; x++)
	{
		printf("%d\n", arr1[x]);
	}
	printf("\n");
	int ans = sum(arr1, ix);
	printf("Sum = %d\nAvg = %f\n", ans, average(ans, i));
	//Detatch shared memory
	shmdt(readFromFile);
	//Delete shared memory
	shmctl(key, IPC_RMID, NULL);
	
	return 0;
}
