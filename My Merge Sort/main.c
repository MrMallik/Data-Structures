/*My Merge Sort Implementation*/

#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int l, int r){

    int m = (r + l) / 2;

    if(l < r){
            //Sort first half
        sort(arr, l, m);
            //Sort second half
        sort(arr, m+1, r);
            //Merge both halves
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r){

    int i,j,k;

    int n1 = m - l;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    //Initialise pointers

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2){

        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }

        else{
            arr[k] = R[i];
            j++;
        }

        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void printArray(int arr[], int n){
    int i;

    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int size, i;
    int arr[30];

    printf("Enter size of array : ");
    scanf("%d", &size);

    printf("Enter %d elements\n", size);
    for(i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

        printf("\nOriginal Array : ");
    printArray(arr, size);
    printf("\nSorted Array : ");
    sort(arr, 0, size - 1);
    printArray(arr, size);


    return 0;
}
