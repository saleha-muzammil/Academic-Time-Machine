#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>

struct param
{
    int* arr1;
    int* arr2;
    int* result;
    int size;
};
void* mergeTwo(void* arg)
{

    struct param* MyArg = (struct param*) arg;
    int i = 0, j = 0 , k = 0;

    for(; i < MyArg->size && j < MyArg->size;)
    {
        if(MyArg->arr1[i] > MyArg->arr2[j])
        {
            MyArg->result[k++] = MyArg->arr2[j++];
        }
        else
        {
             MyArg->result[k++] = MyArg->arr1[i++];
        }
    }
    while(i < MyArg->size)
    {
         MyArg->result[k++] = MyArg->arr1[i++];
    }
    while(j < MyArg->size)
    {
         MyArg->result[k++] = MyArg->arr2[j++];
    }
    pthread_exit(MyArg);
}
void mergeFour(int* arr1, int* arr2, int* arr3, int* arr4, int size)
{
    struct param arguments, arguments2;
    arguments.arr1 = malloc(size * sizeof(int));
    arguments.arr2 = malloc(size * sizeof(int));
    arguments.result = malloc(2 * size * sizeof(int));
    arguments.size = size;

    arguments2.arr1 = malloc(size * sizeof(int));
    arguments2.arr2 = malloc(size * sizeof(int));
    arguments2.result = malloc(2 * size * sizeof(int));
    arguments2.size = size;

    for(int i = 0 ; i < size; i++)
    {
        arguments.arr1[i] = arr1[i];
        arguments.arr2[i] = arr2[i];
    }

    for(int i = 0 ; i < size; i++)
    {
        arguments2.arr1[i] = arr3[i];
        arguments2.arr2[i] = arr4[i];
    }

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, mergeTwo, &arguments);  //  merging 1st and 2nd array
    pthread_create(&thread2, NULL, mergeTwo, &arguments2);  //  merging 3rd and 4th array

    struct param* ans;
    struct param* ans2;

    pthread_join(thread1, (void**) &ans);
    pthread_join(thread2, (void**) &ans2);

    free(arguments.arr1); //  we only need 1 struct now for last step
    free(arguments.arr2);
    
    arguments.arr1 = malloc(size * 2 * sizeof(int));
    arguments.arr2 = malloc(size * 2 * sizeof(int));
    arguments.size = size * 2;
   
    for(int i = 0 ; i < size * 2; i++)
    {
        arguments.arr1[i] = ans->result[i];
         arguments.arr2[i] = ans2->result[i];
        
    }

    pthread_create(&thread1, NULL, mergeTwo, &arguments);

    pthread_join(thread1, (void*) ans);

    for(int i = 0 ; i < 20; i++)
    {
        printf("%d ", ans->result[i]);  //  final ans
    }
    printf("\n");


}
int main(int argc, char* argv[])
{

    int s = 5;

    int array1[5] = {1,2,4,5,7};
    int array2[5] = {3,6,8,9,10};
    int array3[5] = {21,22,23,24,25};
    int array4[5] = {11,12,13,14,26};
    
    mergeFour(array1, array2, array3, array4, s);


    return 0;

}