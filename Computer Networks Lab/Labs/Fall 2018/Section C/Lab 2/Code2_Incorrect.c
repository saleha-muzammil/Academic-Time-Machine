/*This code reads the file.txt which was create by Code1 and then appends another string with it.
  It then displays the entire string onto the terminal*/

#include <stdio.h>
#include <string.h>

int main()              
{
        FILE *pFile;
        char str[100];
        char buffer[100];
        char append[100];
        int i; 

        
        pFile=fopen("file.txt", "w"); 

        if(pFile!=NULL) {       
            printf("Error opening file.\n");
        }

        else
        {
            while(fgets(buffer, 5, pFile));     
            
        }
        
        while(i<strlen(buffer))
        {
                strcpy(str[i],buffer[i]);  
        }
        

        strcpy(&append," Computer Networks Quiz 1");
        
        strcat(&str,&append);
        
        printf("Final String: %c\n",str);        
        
        fclose(pFile);

        return 0;
}
