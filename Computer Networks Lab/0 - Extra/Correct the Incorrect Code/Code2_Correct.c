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
        int i=0; //int i

        memset(str,'\0',sizeof(str)); //remove it
        
        pFile=fopen("file.txt", "r"); //pFile=fopen("file.txt", "w");

        if(pFile==NULL) {       //(pFile!=NULL)
            printf("Error opening file.\n");
        }

        else
        {
            while(fgets(buffer, sizeof(buffer), pFile)); //while(fgets(buffer, 5, pFile))    
            
        }
        printf("%s\n",buffer);
        
        while(i<strlen(buffer))
        {
                str[i]=buffer[i];//strcpy(str[i],buffer[i]);  
                i++;   //remove i++
        }
        
        printf("%s\n",str);

        strcpy(append," Computer Networks Quiz 1"); //strcpy(&append," Computer Networks Quiz 1");
        
        strcat(str,append); //strcat(&str,&append);
        
        printf("Final String: %s\n",str); //printf("Final String: %c\n",str);        
        
        fclose(pFile);

        return 0;
}
