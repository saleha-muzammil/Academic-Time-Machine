#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void swap(char *xp, char *yp)
{
    int temp = *xp;
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
    char curStr[40];
    char temp[]="temp.txt";
    int count = 0;
    char *filename=argv[1];
    
    strcat(filename, ".txt");
    fp1= fopen(filename, "r");
    fp2=fopen(temp, "w");

    
    
    while (fscanf(fp1, "%39s", curStr)==1){
        reverseExceptVowels(curStr);
        printf(curStr);
        fprintf(fp2, "%s", curStr);
        fputc(' ', fp2);

    }
    fclose(fp1);
    fclose(fp2);
    remove(filename);  		// remove the original file 
    rename(temp, filename); 	// rename the temporary file to original name

    return 0;
   
}