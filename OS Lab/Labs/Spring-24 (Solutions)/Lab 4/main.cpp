#include "header.h"

int main(int argc, char* argv[]){
    int* arr=(int*)calloc((argc-1), sizeof(int));
    for (int i=1;i<argc;i++){
        arr[i-1]=atoi(argv[i]);
    }
    cout << "Array elements: ";
    print(arr, argc-1);
    sort(arr, argc-1, true);
    cout << "Sorted elements: ";
    print(arr, argc-1);
    int x;
    findHighest(arr, argc-1, x);
    cout << "The highest value in the array is " << arr[x] <<  " at index " << x << endl;

    free(arr);
    return 0;
}