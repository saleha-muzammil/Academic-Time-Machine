#include <stdio.h>

int main () {
    FILE* fp;
    char cur;
    int count = 0;

    fp= fopen("data1.txt", "r");
    
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

    return 0;
   
}