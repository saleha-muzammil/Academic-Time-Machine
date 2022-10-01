#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
int main (){

    int i;
    int arr[10];
    int fd[2];

    pipe(fd);

    int pid=fork();
    if (pid>0){
		for(i=0; i<10; i++){
			arr[i]=i+1;
        
		}
		close(fd[0]);
        write(fd[1], arr, 10*sizeof(int));
    }
    else if (pid==0){
		int val[10];
		close(fd[1]);	
		read(fd[0], val, 10*sizeof(int));
		int min=val[0], max=val[0];
		float sum=val[0];
		printf("%d ", val[0]);
		for(i=1; i<10; i++){
			printf("%d ", val[i]);
			sum+=val[i];
			if (max<val[i])
				max=val[i];
			if (min>val[i])
				min=val[i];
		}
		float avg=sum/10;
		printf("\nMax value in array is %d", max);
	    printf("\nMin value in array is %d", min);
	    std::cout<<"\nAverage value of array is "<<avg<<std::endl;
		
		
	}
	return 0;
}