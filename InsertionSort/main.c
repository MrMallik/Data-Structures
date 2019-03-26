#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n){
    int idx,temp,k;

    for(idx = 0; idx < n; idx++){

            temp = arr[idx];
            k = idx - 1;

        while(k >= 0 && arr[k] > temp){
            arr[k + 1] = arr[k];
            k--;
        }

        arr[k+1] = temp;
    }
}

void display(int arr[], int n){
    int i;

    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}


int main()
{
    int list[30];
    int size,i;

    printf("Enter size of array!\n");
    scanf("%d", &size);

    printf("Start entering elements\n");

    for(i = 0; i < size; i++){
        scanf("%d", &list[i]);
    }

    sort(list, size);
    printf("\n");
    display(list, size);

    return 0;
}
