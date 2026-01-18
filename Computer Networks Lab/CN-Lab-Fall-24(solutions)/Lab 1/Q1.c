#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>


int main(){
	char arr[1000];
	char* fileName= "inputFile.txt";
	int fd=open(fileName, O_RDONLY);
	int bytesRead=read(fd, arr, sizeof(char)*1000);
	printf("File contents:\n%s", arr);
	
	return 0;
}
