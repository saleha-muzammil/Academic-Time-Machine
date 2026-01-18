#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include <string.h>


int main(){
	char arr[1000], buffer[1000];
	
	//reading the file contents
	char* fileName= "inputFile.txt";
	int fd=open(fileName, O_RDONLY);
	int bytesRead=read(fd, arr, sizeof(char)*1000);
	
	//tokenizing the string
	char* curr=strtok(arr, " ");	
	char* result[1000];
	int wordCount=0;
	while (curr!=NULL){
		result[wordCount++]=curr;
		//printf("%s\n", result[wordCount-1]);
		curr=strtok(NULL, " ");
	}
	
	int fd1=open("nonAlpha.txt", O_WRONLY|O_CREAT|O_APPEND, 0777);
	for (int i=0;i<wordCount;i++){
		int isAlpha=0;
		for (int j=0;j<strlen(result[i]);j++){
			if ((result[i][j]>='a' && result[i][j]<='z') 
			|| (result[i][j]>='A' && result[i][j]<='Z')){
			isAlpha=1;
			}
		}
		if (isAlpha!=1){
			if (write(fd1, result[i], strlen(result[i]))==-1){
				return -1;
			}
			char* tmp=" ";
			write(fd1, tmp, sizeof(char));
		}
	}
	
	close(fd);
	
	return 0;
}
