#include <stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

void removeNonAlphabetChars(char* iFile, char* oFile){
    int fdInput=open(iFile, O_RDONLY | O_CREAT);
    int fdOutput=open(oFile, O_WRONLY | O_CREAT);
    char* buffer=(char*)calloc(100, sizeof(char));
    int bytesRead=read(fdInput, buffer, 100*sizeof(char));
    printf("%d bytes read from inFile.txt.\n", bytesRead);
    int currSize=0;
    for (int i=0;i<bytesRead;i++){
        if ((buffer[i]>='a' && buffer[i]<='z') || (buffer[i]>='A' && buffer[i]<='Z')){
            //if it is an alphabet character, add it into the updated buffer
            buffer[currSize++]=buffer[i];
        }
        //Note that space is also removed as it is a non-alpahbet character
    }
    buffer[currSize]='\0'; //null char at the end to make it work woth string functions
    printf("%s\n", buffer);
    int bytesWritten=write(fdOutput, buffer, currSize*sizeof(char));
    printf("%d bytes wriiten into outFile.txt\n", bytesWritten);
    close(fdInput);
    close(fdOutput);
    free(buffer); //deallocates the memory
}

int main(){
    removeNonAlphabetChars("inFile.txt", "outFile.txt");
    
    return 0;
}
