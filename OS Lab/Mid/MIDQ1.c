#include<pthread.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>

struct arg{
	char srch;
	char rep;
	char * win;
};

void * func( void * ptr)
{
	struct arg *temp = (struct arg *) ptr;
	for ( int j=0;j<4096;j++)
	{
		if (temp->win[j]==temp->srch)
		{
			temp->win[j]=temp->rep;		
		}
	}
	free(temp);
	return NULL;
}

int main(int argc, char** argv)
{
	int fd = open(argv[3],O_RDWR);
	struct stat temp;
	fstat(fd,&temp);
	int num_t = temp.st_size/4096 + 1;
	char * data = mmap (NULL, temp.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	pthread_t tid[num_t];
	struct arg *targ;
	for (int i=0;i<num_t;i++)
	{
			targ = malloc (sizeof(struct arg));
			targ->srch=argv[1][0];
			targ->rep=argv[2][0]; 
			targ->win=data+i*4096;
			pthread_create(&tid[i],NULL,func,(void *)targ);
	
	}
	for (int i=0;i<num_t;i++)
	{
		pthread_join(tid[i],NULL);
	}	
	munmap(data,temp.st_size);
	close(fd);
	return 0;
}
