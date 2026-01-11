#include "header.h"

void sort(int arr[], int n,bool order){
    if (order==true){
        sort(arr, arr + n);
    }
    else{
        sort(arr, arr + n, greater<int>());
    }
}

void findHighest(int arr[], int n, int& position){
    int maxVal=0;
    for (int i=1;i<n;i++){
        if (arr[maxVal]<arr[i]){
            maxVal=i;
        }
    }
    position=maxVal;
}

void print(int arr[], int n){
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}