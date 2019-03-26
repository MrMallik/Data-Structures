#include <stdio.h>
#include <stdlib.h>

/*Code selects the last element as the pivot*/



void swap(int *a, int *b){
    int t = *a;
        *a = *b;
        *b = t;
}

void Qsort(int arr[], int low, int high){
  if(low < high){
    int pi = partition(arr, low, high);
    printf("\n");
    Qsort(arr, low, pi-1);
    Qsort(arr, pi+1, high);
  }
}

int partition(int arr[], int low, int high){
    int i = low - 1, j = 0;
    int pivot = arr[high];

    for(j = low; j < high; j++){
        if(arr[j] <= pivot){
                i++;
            swap(&arr[i], &arr[j]);
            display(arr, sizeof(arr)/sizeof(arr[0]));
        }
    }
        swap(&arr[i + 1], &arr[high]);
        return (i+1);
}

void display(int arr[], int n){
    int idx;

    for(idx=0; idx < n; idx++){
        printf("%d ", arr[idx]);
    }
}

int main()
{
    int arr[40], size, idx;

    printf("Enter size of array : ");
    scanf("%d", &size);

    printf("Enter the elements now\n");
    for(idx = 0; idx < size; idx++){
        scanf("%d", &arr[idx]);
    }

    Qsort(arr, 0, size-1);
    printf("Sorted Array : ");
    display(arr, size);

    return 0;
}
