#include <stdio.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
	//argv[0] is Read. argv[1] is Write.
    //ftok generates unique key
    key_t key = ftok("shmfile",65);
    int process = fork();
    if (process < 0)
    {  
        printf("Fork failed\n");
        exit(-1);
    }
    if (process == 0)
    {
        //Child process
        //shmget associates shared mem id
        int shmid = shmget(key,1024, 0666 | IPC_CREAT | IPC_PRIVATE);
        //shmat attaches process to shared memory
        char *str = (char*) shmat(shmid, (void*)0, 0);
        printf("%s\n", argv[1]);
        int fd = open(argv[1], O_RDONLY, 0);
        if (fd < 0)
        {
            printf("File failed\n");
            exit(-1);
        }
        read(fd, str, 1024);
        close(fd);
        //detach from shared memory 
        shmdt(str);
        return 0;
    }
    //Parent
    wait(NULL);
    // shmget returns an identifier in shmid
    int shmid = shmget(key, 1024, 0);
    // shmat to attach to shared memory
    char *Newstr = (char*) shmat(shmid, (void*)0, 0);
    
    //Converting all characters and removing numbers.
    for (int i = 0; Newstr[i] != '\0'; i++)
    {
        if (Newstr[i] >= 65 && Newstr[i] <= 90)
            Newstr[i]+=32;
        else
        if (Newstr[i] >= 97 && Newstr[i] <= 121)
            Newstr[i]-=32;
        else
        {
            //Loop till not number.
            int j = i;
            while (Newstr[j] >= 48 && Newstr[j] <= 57)
            {
                j++;
            }
            int k = 0;
            //Move all chars back till number.
            for (k = i; Newstr[j] != '\0'; k++)
            {
                Newstr[k] = Newstr[j++];
            }
            Newstr[k] = '\0';
        }
    }
    int fd = open(argv[2], O_CREAT | O_RDWR);
    write(fd, Newstr, strlen(Newstr));
    close(fd);
    //detach from shared memory
    shmdt(Newstr);
    //destroy the shared memory
    shmctl(shmid,IPC_RMID,NULL);
}
