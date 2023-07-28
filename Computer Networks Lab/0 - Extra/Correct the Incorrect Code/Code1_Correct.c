/* First this code gets a string, replaces the vowels from that input string with the '*' chracter and writes this string to file.txt*/

#include <stdio.h>
#include <string.h>

int main()              
{

        FILE *pFile;
        char str[100];
        int i=0;        //int i;

        pFile=fopen("file.txt", "w");

        if(pFile==NULL) {       //pFile!=NULL
            printf("Error opening file.\n");
            return -1;
        }

        else {
        
                printf("Enter your string: ");
                gets(str);        //scanf("%s",str);
 
                while(i<strlen(str))
                {
                          if(str[i]=='a' || str[i]=='e'  || str[i]=='i' || str[i]=='o' || str[i]=='u'|| 
                             str[i]=='A' || str[i]=='E'  || str[i]=='I' || str[i]=='O' || str[i]=='U')
                          {
                                  str[i]='*'; //strcpy(str,'*');
                                  //i++;
                          }
                          i++;
                }
         
                fputs(str, pFile);
                fclose(pFile);
         }
         
        return 0;
}
