#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int n){
    int i,j,minLoc;

    for(i=0; i < n-1; i++){
            minLoc = i;
        for(j = i + 1; j < n; j++)
            if(arr[j] < arr[minLoc])
                minLoc = j;
            
            swap(&arr[minLoc], &arr[i]);

        printf("\n");
        printf("Pass %d : ",i+1);
        display(arr, n);
        printf("  minLoc : %d",minLoc);

    }
}

void display(int arr[], int n){
    for(int i=0; i < n; i++)
        printf("%d ",arr[i]);

}

int main()
{
    //int arr[] = {5,4,2,3,1};
    int arr[] = {5,4,2,3,1};
    int n = 5;
    sort(arr, n);

    return 0;
}
