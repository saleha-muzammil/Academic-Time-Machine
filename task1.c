#include <stdio.h>
#include <string.h>

int main (int argc, char** argv) {
    FILE* fp;
    char cur;
    int count = 0;
    char *filename=argv[1];
    
    strcat(filename, ".txt");
    fp= fopen(filename, "r");
    
    while (1){
        cur=fgetc(fp);
        if (cur==EOF){
            break;
        }
        else {
            if (cur>='0'&& cur<='9'){
                count++;
            }
        }
    }
    printf("Number of digits is %d", count);
    fclose(fp);
    return 0;
   
}