#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void swap(char *xp, char *yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}
bool checkIfVowel(char chr){
    if (chr!='a'&&chr!='e'&&chr!='i'&&chr!='o'&&chr!='u'&&chr!='A'&&chr!='E'&&chr!='I'&&chr!='O'&&chr!='U'){
        return true;
    }
    return false;
}
char* reverseExceptVowels(char* str){
    int len=strlen(str)-1;
    for (int i=0; i<len/2;i++){
        if (checkIfVowel(str[i])&&checkIfVowel(str[len-i])){
            swap(&str[i], &str[len-i]);
        }
    }
}
int main (int argc, char** argv) {
    FILE *fp1, *fp2;
    char curStr[65536];
    char qStr[]="q3_";
    char temp[]="temp.txt";
    char txtStr[]=".txt";

    int count = 0;

    char *fileStr=argv[1];
    char *filename=qStr;
    char *fileText=txtStr;

    strcat(filename, fileStr);
    strcat(filename, fileText);

    char fname[50];
    strcpy(fname, filename);
    
    fp1= fopen(filename, "r");
    fp2=fopen(temp, "w");

    while (fgets(curStr, 65535, fp1)!=NULL){

        reverseExceptVowels(curStr);
        fprintf(fp2, "%s", curStr);
    }

    fclose(fp1);
    fclose(fp2);
    remove(fname);  		// remove the original file 
    rename(temp, fname); 	// rename the temporary file to original name
    return 0;
   
}