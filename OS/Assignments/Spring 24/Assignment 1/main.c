#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

void tokenizeString(char* arr, const char* delimeter, char* result[], int *i){
    char* curr=strtok(arr, delimeter);
    //tokenizes the str based on delimeter and stores in 2d arr result
    while (curr != NULL) {
        result[(*i)++]=curr;
        // printf("%s\n", result[(*i)-1]);
        curr = strtok(NULL, delimeter);
    }
}

void removeNewLine(char arr[]){
    size_t l=strlen(arr);
    if (l>0 && arr[l-1]=='\n'){
        arr[l-1]='\0';
    }
}


void executeCommand(char* input, char currPath[]){
   char* result[100];
   int size=0;
   tokenizeString(input, " ",result, &size);


   if (strcmp(result[0], "ls")==0){
      if (size>2){
      printf("You cannot pass more than one directory paths.\n");
      }
      else{
      char path[100];
      if (size==1){
          //list the files of the current dir
          strcpy(path, ".");
      }
       else{
          //list given directory files
          strcpy(path, result[1]);
       }
      struct dirent **namelist;
      int n = 0;
      n = scandir(path, &namelist, NULL, alphasort);
      if (n == -1) {
          perror("scandir");
      }
      else{
      while (n-- > 0) { 
          if (strcmp(namelist[n]->d_name,".")!=0 && strcmp(namelist[n]->d_name, "..")!=0){
              printf("%s\n", namelist[n]->d_name); 
          }
          free(namelist[n]);
      }
      free(namelist);
      }
      }
   }
   else if ((strcmp(result[0], "pwd"))==0){
    char *buf;
    buf=(char *)calloc(100,sizeof(char));
    getcwd(buf,100);
    printf("%s\n",buf);
   }
   else if ((strcmp(result[0], "mkdir"))==0){
    if (size==2){
        //mkdir path/Foldername
        //S_IRWXU is the default file mode->grants RW permissions to the user
        int check = mkdir(result[1], S_IRWXU);
        if (check==-1){
            printf("Unable to create directory.\n");
        }
    }
    else if (size==1){
        printf("Directory name not specified.\n");
    }
    else{
        printf("Too many arguements.\n");
    }
   }
   else if ((strcmp(result[0], "rmdir"))==0){
        if (size==2){
        //rmdir path/Foldername
        int check = rmdir(result[1]);
        if (check==-1){
            printf("Unable to remove directory.\n");
        }
    }
    else if (size==1){
        printf("Directory name not specified.\n");
    }
    else{
        printf("Too many arguements.\n");
    }
   }
   else if ((strcmp(result[0], "cp"))==0){
    //cp destFile srcFile
    if (size==3){
    FILE *readFile, *writeFile; 
    char c; 
    // Open file for reading 
    readFile = fopen(result[2], "r"); 
    if (readFile == NULL) 
    { 
        printf("Cannot open file %s \n", result[2]); 
    } 
    // Open file for writing 
    writeFile = fopen(result[1], "w"); 
    if (writeFile == NULL) 
    { 
        printf("Cannot open file %s \n", result[1]); 
    } 
    if (readFile!=NULL && writeFile!=NULL){
    // Read contents from file 
    c = fgetc(readFile); 
    while (c != EOF) 
    { 
        fputc(c, writeFile); 
        c = fgetc(readFile); 
    } 
    }
    if (writeFile){
        fclose(writeFile);
    }
    if (readFile){
        fclose(readFile);
    }
    }
    else{
        printf("Wrong number of arguements.\n");
    }
   }
     else if ((strcmp(result[0], "cd"))==0){
        if (size==1){
            printf("Too few arguements.\n");
        }
        else if (size==2){
            if (strcmp(result[1], "..")==0){
                 char *buf;
                 buf=(char *)calloc(100,sizeof(char));
                 getcwd(buf,100);
                 int totalSize=strlen(buf);
                 //we need to go back one path from the current directory
                 int pSize=0;
                 char* path[20];
                 tokenizeString(buf, "\\", path, &pSize);
                 int n=strlen(path[pSize-1]);
                 //shortcut to reduce the size of the array is to place a null char
                 buf[totalSize-n]='\0'; 
                 int check = chdir(result[1]);
                 if (check!=0){
                    printf("Unable to change the directory.\n");
                 }
                 else{
                    //updates the current directory path
                    getcwd(currPath, 100);
                    // printf("%s\n", currPath);
                 }
            }
            else{
                int check = chdir(result[1]);
                if (check!=0){
                    printf("Unable to change the directory.\n");
                }
                else{
                     //updates the current directory path
                     getcwd(currPath, 100);
                }
            }
        }
        else{
            printf("Too many arguements.\n");
        }
   }
     else if ((strcmp(result[0], "mv"))==0){
        //mv oldName.txt newName.txt ->renames the file
        if (size==3){
            int check=rename(result[1], result[2]);
            if (check!=0){
                printf("Renaming not succesful!\n");
            }
        }
        else{
            printf("Invalid number of arguements.\n");
        }

   }
     else if ((strcmp(result[0], "grep"))==0){
        if (size==1 || size==2){
            printf("Too few arguements.\n");
        }
        else if (size==3){
            //grep wordToBeSearched fileName
            //file needs to be present in the current working directory
            FILE * fp;
            char * line = NULL;
            size_t len = 0;
            ssize_t read;

            fp = fopen(result[2], "r");
            if (fp == NULL){
                printf("Unable to open the file.\n");
            }
            else{
                char* ptr;
                while ((read = getline(&line, &len, fp)) != -1) {
                // printf("Retrieved line of length %zu:\n", read);
                ptr=strstr(line, result[1]);
                if (ptr!=NULL){
                    printf("%s", line);
                }
                }
                fclose(fp);
            }
        }
        else{
            printf("Too many arguements.\n");
        }
   }
    else if ((strcmp(result[0], "touch"))==0){
        //touch filename->creates file in the current directory
        if (size==1){
            printf("No filename entered.\n");
        }
        else if (size==2){
            //create the file
            FILE* p=fopen(result[1], "w");
            if (p==NULL){
                printf("File not created.\n");
            }
            else{
                fclose(p);
            }

         }
        else{
            printf("Too many arguements.\n");
        }    
   }
    else if ((strcmp(result[0], "rm"))==0){
        //deletes the files in the current directory only
        if (size==1){
            printf("No filename entered.\n");
        }
        else if (size==2){
            int check=remove(result[1]);
            if (check!=0){
                printf("File not deleted.\n");
            }
        }
        else{
            printf("Too many arguements.\n");
        }
   }
   else if (strcmp(result[0], "exit")==0){
    //do nothing
   }
   else{
    printf("command not found: %s.\n", result[0]);
   }
}


int main() {
    char input[200] = "init";
    char path[100];
    getcwd(path,100);
    printf("%s\n",path);
   //takes input from the user until enters exit
    while (strcmp(input, "exit")){
        printf("\n%s ", path);
        //input of max 200 chars
        fgets(input, 200, stdin); 
        //removes newline char at the end of input string that is added by default with fgets 
        removeNewLine(input); 
        //tokenizes the instruction and takes appropriate action
        executeCommand(input, path);
    }

    return 0;
}
