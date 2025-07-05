#include "util.h"

void removeNonAlphabets(char* inputFileName, char* outputFileName)
{
	char* storeStr, * newStoreStr;
	storeStr = (char *) calloc(100, sizeof(char));
	newStoreStr = (char *) calloc(100, sizeof(char));
	
	int fd = open(inputFileName, O_RDONLY);
	int sz = read(fd, storeStr, 100);
	int j = 0;
	for (int i = 0; storeStr[i] != '\0'; i++)
	{
		if ((storeStr[i] >= 'a' && storeStr[i] <= 'z') || (storeStr[i] >= 'A' && storeStr[i] <= 'Z'))
		{
			newStoreStr[j++] = storeStr[i];
		}
	}
	newStoreStr[j] = '\0';
	close(fd);
	
	fd = open(outputFileName, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	sz = write(fd, newStoreStr, strlen(newStoreStr));
	close(fd);
}
