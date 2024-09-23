#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <sys/wait.h>

char dir [100];

void * copyfile (void * arg)
{
	
	char * buf = (char *)arg;
	int total=0;
	char abs_addr [512];
	strcpy(abs_addr,dir);
	strcat(abs_addr, buf);
	int fd_in = open(buf,O_RDONLY);
	int fd_out = open(abs_addr,O_CREAT|O_WRONLY|O_TRUNC,0666);
	//printf("fd_in %d, fd_out %d\n, original is %s, path is %s", fd_in, fd_out, buf,abs_addr);
	int rc_rd,rc_wt; char read_ch;
	while (1)
	{
		int rc_rd= read (fd_in, &read_ch,1);
		if (rc_rd>0)
		{
			int rc_wt = write (fd_out, &read_ch,1);
			if (rc_wt == -1)
			{
				printf("Write failed.");
				close(fd_out);
				close(fd_in);	
			}
			total++;	
		}	
		
		if (rc_rd==0)
		{
			break;		
		}	
	}		
	printf("Copied file:%s and wrote %d bytes in total.\n",abs_addr,total);
	close(fd_in);
	close(fd_out);	
	return NULL;

	
}

int main(int argc, char*argv[]){

	//char dir [100] = "/home/ahsan/Desktop/test2";
	int rc;
	int fd_input = open("input.txt",O_RDONLY);
	char null_str[] = {'\0'};
	char rdch;	
	char buf [100] = {};
	int i=0;
	int eof = 0;
	strcpy(dir,argv[1]);
	if (!fork())
	{
		printf("Creating Directory:%s\n",argv[1]);
		execlp("mkdir","mkdir",argv[1],NULL);
	}
	wait(NULL);
	pthread_t tid;
	while(1)
	{
		while(1)
		{
			rc=read(fd_input, &rdch,1);
		//	printf("%s and rc is %d\n", buf, rdch);
			if (rdch == '\n'|| rdch =='\0' || rdch == 10 )
				break;
			if (rc==0)
			{
				eof=1;break; 
			}
			if (rc>0)
				buf[i++]=rdch;
			//sleep(2);
		
		}
		buf[i]='\0';
		//printf("%s and len is%d\n",buf , strlen(buf));
		i=0;
		if(!strcmp(buf,null_str))
		{
			/*printf("NUll string.\n");*/break;
		}
		int x = pthread_create(&tid, NULL, copyfile, buf);
		if (x)
		{
			printf("Unable to create thread(s).\n Exiting.\n");
			_exit(1);
		}
		//printf("Created thread -> %d\n",(int)tid);
		pthread_join(tid, NULL);
		if(eof) break;
	}
	close(fd_input);
	pthread_exit(0);
	 
}

