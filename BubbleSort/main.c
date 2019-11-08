#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int n){
    int i,j;

    for(i=0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);

        }
        printf("\n");
        printf("Pass %d : ",i+1);
                display(arr, n);
    }
}

void display(int arr[], int n){
    for(int i=0; i < n; i++)
        printf("%d ",arr[i]);

}


int main()
{
    int arr[] = {5,4,3,2,1};
    int n = 5;
    sort(arr, n);

    return 0;
}
