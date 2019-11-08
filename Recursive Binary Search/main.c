#include <stdio.h>
#include <stdlib.h>

int search(int start, int end, int arr[], int key){

    int mid = (start + end) / 2;

    if(start > end)
        return -1;

    else if(arr[mid] < key)
        return search(mid + 1, end, arr, key);

    else if(arr[mid] > key)
        return search(start, mid - 1, arr, key);

    else if(arr[mid]==key)
        return mid;

}

int main()
{
    int n = 5;
    int list[n],i=1, key;

    printf("Enter %d numbers \n", n);


    for(i=1; i <= n; i++){
        scanf("%d", &list[i]);
    }

    printf("Enter search query : ");
    scanf("%d", &key);

    if(search(0, n, list, key)!=-1){
        printf("Search successful!");
    }
    else{
        printf("Search Unsuccessful!");
    }

    return 0;
}
