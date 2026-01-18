#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>


int main(){
	char arr[1000], buffer[1000];
	char* fileName= "inputFile.txt";
	int fd=open(fileName, O_RDONLY);
	int bytesRead=read(fd, arr, sizeof(char)*1000);

	printf("File contents:\n%s\n\n", arr);
	int currSize=0;
	for (int i=0;i<(bytesRead/sizeof(char));i++){
		if (arr[i]>='0' && arr[i]<='9'){
			buffer[currSize++]=arr[i];
		}
	}
	buffer[currSize]='\n';
	if (currSize>0){
		int fd1=open("outFile.txt", O_WRONLY|O_CREAT, 0777);
		int bytesWritten=write(fd1, buffer, currSize*sizeof(char));
		printf("The content of outfile is:\n%s\n\n", buffer);
		close(fd1);
	}
	else{
		printf("No integers found!\n");
	}
	close(fd);
	
	return 0;
}
