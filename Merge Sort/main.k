#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int n){
    if(n < 0)
        return;
    else{
        if(arr[n] < arr[n-1]){
            swap(&arr[n], &arr[n-1]);
        }
        sort(arr, n-1);
    }
}

void putArray(int arr[], int n){
    int i;

    for(i = 0; i< n; i++){
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[30], n, i;

    printf("Enter size of array : ");
    scanf("%d", &n);

    printf("Enter elements\n");

    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Original Array : ");
    putArray(arr, n);
    printf("\n");
    sort(arr, n);
    printf("Sorted Array : ");
    putArray(arr, n);


    return 0;
}
