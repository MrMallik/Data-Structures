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

    }
}

void display(int arr[], int n){
    for(int i=0; i < n; i++)
        printf("%d ",arr[i]);

}

int main()
{
    //int arr[] = {5,4,2,3,1};
    int arr[50];
    int size;

    printf("Enter no. of elements : ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++){
        scanf("%d",&arr[i]);
    }

    sort(arr, size);

    return 0;
}
