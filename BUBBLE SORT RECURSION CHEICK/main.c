#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[50], arrayLength, continu;

    printf("PROGRAM TO PERFORM BUBBLE SORT USING RECURSION\n");
    printf("----------------------------------------------\n");
    printf("INITIALIZATION OF THE ARRAY \n");
    do{
        printf("\nENTER THE ARRAY LENGTH: ");
        scanf("%d", &arrayLength);

        InitializeArray(array, arrayLength);
        printf("\nGIVEN ARRAY: ");
        printArray(array, arrayLength, arrayLength);
        printf("\n\nBUBBLE SORT\n");

        bubbleSort(array, arrayLength);
        printf("\n\nANOTHER OPERATION?\nYES => 1\nNO  => 0 (or) ANY OTHER KEY\n");
        scanf("%d", &continu);

    }while(continu == 1);

    return 0;
}

void InitializeArray(int *arr, int length){
    int i;
    printf("\nENTER ELEMENT N\n");
    for(i = 0; i < length; i++){
        printf("\t\t %d: ", i+1);
        scanf("%d",(arr + i));
    }
}

void printArray(int *arr, int length){
    int i;
    for(i = 0; i < length; i++)
        printf(" %d ", *(arr+i));

}

void swap(int *nb1, int * nb2){
    *nb1 += *nb2;
    *nb2 = *nb1 - *nb2;
    *nb1 -= *nb2;
}

void bubbleSort(int *arr, int length, int fixedLen){
    if(length > 1)
    {
        int i, j;
        for(i = 0, j = i+1; i <length; i++, j++){
            if(arr[i] > arr[j])
                swap((arr+i),(arr+j));
        }
        printf("\nPASS %d: ",(fixedLen - length)+1);
        printArray(arr, fixedLen);

        bubbleSort(arr, length-1, fixedLen);
    }

}
