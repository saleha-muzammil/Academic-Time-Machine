#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    pid_t child1, child2, child3;
    int pipes[3][2];
    pipe(pipes[0]);
    pipe(pipes[1]);
    pipe(pipes[2]);
    printf("Start\n");
    //sleep(1) added as cannot ensure which task start execution first
    //Hence, to ensure parent process is able to show initial output, delay is added.
    if (!(child1 = fork())) 
    {
        // first child
        sleep(1);
        char* readBuffer = (char*) malloc(1024);
        int fd = open("file1.txt", O_RDONLY);
        if (fd < 0)
        {
            printf("file did not open\n");
            exit(-1);
        }
        read(fd, readBuffer, 1024);
        int* array = (int*) malloc(100);
        int x = 0;

        char* temp = strtok(readBuffer, " ");
        while (temp != NULL)
        {
            array[x++] = atoi(temp);
            temp = strtok(NULL, " ");
        }

        if (x == 0)
        {
            printf("File empty\n");
            exit(-1);
        }

        int max = array[0];
        for (int i = 1; i < x; i++)
        {
            if (max < array[i])
            {
                max = array[i];
            }
        }
        printf("Max in file1.txt is: %d\n", max);
        char* parse = malloc(8);
        sprintf(parse, "%d", max);
        close(pipes[0][0]);
        write(pipes[0][1], parse, 8);
        close(pipes[0][1]);
        free (parse);
        free (temp);
        free (array);
        free (readBuffer);
        exit(0);
    } 
    else 
    {
        if (!(child2 = fork())) 
        {
            // second child
            sleep(1);
            char* readBuffer = (char*) malloc(1024);
            int fd = open("file2.txt", O_RDONLY);
            if (fd < 0)
            {
                exit(-1);
            }
            read(fd, readBuffer, 1024);
            int* array = (int*) malloc(100);
            int x = 0;
            
            char* temp = strtok(readBuffer, " ");
            while (temp != NULL)
            {
                array[x++] = atoi(temp);
                temp = strtok(NULL, " ");
            }

            if (x == 0)
            {
                printf("File empty\n");
                exit(-1);
            }

            int max = array[0];
            for (int i = 1; i < x; i++)
            {
                if (max < array[i])
                {
                    max = array[i];
                }
            }
            printf("Max in file2.txt is: %d\n", max);
            char* parse = malloc(8);
            sprintf(parse, "%d", max);
            close(pipes[1][0]);
            write(pipes[1][1], parse, 8);
            close(pipes[1][1]);

            free (parse);
            free (temp);
            free (array);
            free (readBuffer);
            exit(0);
        } 
        else 
        {
            if (!(child3 = fork()))
            {
                // third child
                sleep(1);
                char* readBuffer = (char*) malloc(1024);
                int fd = open("file3.txt", O_RDONLY);
                if (fd < 0)
                {
                    exit(-1);
                }
                read(fd, readBuffer, 1024);
                int* array = (int*) malloc(100);
                int x = 0;
                
                char* temp = strtok(readBuffer, " ");
                while (temp != NULL)
                {
                    array[x++] = atoi(temp);
                    temp = strtok(NULL, " ");
                }

                if (x == 0)
                {
                    printf("File empty\n");
                    exit(-1);
                }

                int max = array[0];
                for (int i = 1; i < x; i++)
                {
                    if (max < array[i])
                    {
                        max = array[i];
                    }
                }
                printf("Max in file3.txt is: %d\n", max);
                char* parse = malloc(8);
                sprintf(parse, "%d", max);
                close(pipes[2][0]);
                write(pipes[2][1], parse, 8);
                close(pipes[2][1]);

                free (parse);
                free (temp);
                free (array);
                free (readBuffer);
                exit(0);
            }
            else
            {
                // parent
                printf("Program has 3 file names hardcoded\n");
                printf("file1.txt, file2.txt, file3.txt\n");
                printf("execute accordingly\n\n");
                wait(&child1);
                wait(&child2);
                wait(&child3);
                
                printf("\nAll files executed properly\nCalculating max from all now\n");
                close(pipes[0][1]);
                close(pipes[1][1]);
                close(pipes[2][1]);
                char* max = (char*) malloc(8);
                int finalMax;
                read(pipes[0][0], max, 8);
                finalMax = atoi(max);
                read(pipes[1][0], max, 8);
                if (finalMax < atoi(max))
                    finalMax = atoi(max);
                read(pipes[2][0], max, 8);
                if (finalMax < atoi(max))
                    finalMax = atoi(max);
                printf("max value amongst all three files is: %d\n", finalMax);
            }
        }
    }
    
    return 0;
}