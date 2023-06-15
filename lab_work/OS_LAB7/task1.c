#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

long numbytes;

int *replace_duplicate(int *list)
{

  	int *arr=(int*)calloc(numbytes, sizeof(int));
	int count = 0;
	int i,j;
	for(i = 0; i<numbytes/4; i++){
	   int valid = 1;
	   for(j = 0; j < count; j++){
		  if(list[i]==arr[j]){
		      valid = 0;
		  }    
	   }
	   if(valid == 1){
		   //printf("%d ", list[i])
		   arr[count]=list[i];
		   count++;
	   }
	   else 
	   {
	   		arr[count]=0;
	   		count++;
	   }
	}
	return arr;

}

void *thread_function(void *arg){

	char *filename;
	filename=(char *)arg;
	//printf("%s", filename);
	FILE *fp=fopen(filename, "r");
	
	fseek(fp, 0L, SEEK_END);
	numbytes = ftell(fp);
	fseek(fp, 0L, SEEK_SET); 
	char valStr[10]; 
	int val;
	int *arr=(int*)calloc(numbytes, sizeof(int));
	int i=0;
	while (fscanf(fp, "%s", valStr)!=EOF){
		val=atoi(valStr);
		if (val<0){
			arr[i]=0;
			//printf("Negative ");
		}
		else{
			arr[i]=val;
			//printf(" %d", arr[i]);
		}
		i++;
	}
	arr=replace_duplicate(arr);
	pthread_exit(arr);
	
	
}

int main(){
	int sum_result=0;
	pthread_t a_thread;
	char *f1="f1.txt";
	pthread_create(&a_thread, NULL, thread_function, (void *)f1);
	int *arr=(int*)calloc(numbytes, sizeof(int));
	//int *arr;
	pthread_join(a_thread, (void **)&arr);
	int i;
	for (i=0;i<numbytes/4;i++){
		sum_result+=arr[i];
		//printf(" %d",arr[i]);
	}
	
	printf("Result of file f1.txt is %d\n", sum_result);
	char *f2="f2.txt";
	pthread_create(&a_thread, NULL, thread_function, (void *)f2);
	arr=(int*)calloc(numbytes, sizeof(int));
	//int *arr;
	pthread_join(a_thread, (void **)&arr);
	for (i=0;i<numbytes/4;i++){
		sum_result+=arr[i];
		//printf(" %d",arr[i]);
	}
	printf("Result of file f2.txt is %d\n", sum_result);
	return 0;
}
