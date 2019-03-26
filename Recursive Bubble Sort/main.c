
/* Recursive Bubble Sort*/

#include <stdio.h>
#include <stdlib.h>


int ctr = 0;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int arr[], int n){
    if(n==1)
        return;

    for(int j = 0; j < n - 1; j++){
        if(arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
    }
    printf("Pass %d : ", ctr++);
    display(arr, n);
    printf("\n");

    sort(arr, n-1);
}


void display(int arr[], int n){

    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[] = {5,2,3,4,1};
    int size = 5;

    printf("Original Array : ");
    display(arr, size);
    printf("\n");
    sort(arr, size);
    printf("\n");
    printf("Sorted Array : ");
    display(arr, size);
    return 0;
}
