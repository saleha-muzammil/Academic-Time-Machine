#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define first 1
#define second 1

int main(){

	FILE *fp=fopen("file.txt", "r");
	char *text;
	long numbytes;

	if(fp == NULL)
		return 1;
     
	fseek(fp, 0L, SEEK_END);
	numbytes = ftell(fp);
	fseek(fp, 0L, SEEK_SET);  
 
	fclose(fp);

	int fd1[2];
	int fd2[2];
	pipe(fd1);
	pipe(fd2);
	pid_t pid=fork();
	if (pid>0){
		fp=fopen("file.txt", "r");
		text = (char*)calloc(numbytes, sizeof(char));   
		if(text == NULL)
			return 1;
		fread(text, sizeof(char), numbytes, fp);
		fclose(fp);
		close(fd1[0]);
		write(fd1[1], text, numbytes*sizeof(char));
		close(fd1[1]);
		wait(NULL);
		close(fd2[1]);
		read(fd2[0], text, numbytes*sizeof(char));
		fp=fopen("file.txt", "w");
		fputs(text, fp);
		fclose(fp);
		close(fd2[0]);

	}
	else if (pid==0){
		wait(NULL);
		char* newText=(char*)calloc(numbytes, sizeof(char));

		close(fd1[1]);
		read(fd1[0], newText, numbytes*sizeof(char));

		for (int i=0;i<numbytes;i++){
			if (newText[i]>='!'&&newText[i]<='/'||newText[i]>=':'&&newText[i]<='@'||newText[i]>='['&&newText[i]<='`'||newText[i]>='{'&&newText[i]<='~'){
				newText[i]=' ';
			}
		}
		close(fd1[0]);
		close(fd2[0]);
		write(fd2[1], newText, numbytes*sizeof(char));
		exit(0);
	}
	return 0;
}