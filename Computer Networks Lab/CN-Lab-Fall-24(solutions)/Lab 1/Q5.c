#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include <string.h>


char *strrev(char *str){
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}


int main(){
	char arr[1000], buffer[1000];
	
	//reading the file contents
	char* fileName= "inputFile.txt";
	int fd=open(fileName, O_RDONLY);
	int bytesRead=read(fd, arr, sizeof(char)*1000);
	
	//tokenizing the string
	char* curr=strtok(arr, " \n");	
	char* result[1000];
	int wordCount=0;
	while (curr!=NULL){
		result[wordCount++]=curr;
		//printf("%s\n", result[wordCount-1]);
		curr=strtok(NULL, " \n");
	}
	
	int fd1=open("invertedInput.txt", O_WRONLY|O_CREAT|O_APPEND, 0777);
	for (int i=0;i<wordCount;i++){
		int isVowel=0;
		for (int j=0;j<strlen(result[i]);j++){
			if (result[i][j]=='a' ||
			result[i][j]=='e' ||
			result[i][j]=='i' ||
			result[i][j]=='o' ||
			result[i][j]=='u' ||
			result[i][j]=='A' ||
			result[i][j]=='E' ||
			result[i][j]=='I' ||
			result[i][j]=='O' ||
			result[i][j]=='U'){
			isVowel=1;
			}
		}
		if (isVowel==1){
			result[i]=strrev(result[i]);
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
