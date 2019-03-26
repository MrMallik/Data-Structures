#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int key, int n){

    if(n < 0)
        return -1;
    else if(arr[n]==key)
        return n;
    else
        return search(arr, key, n-1);

}

int main()
{
    int n = 5;
    int list[n],i, key;

    printf("Enter %d numbers \n", n);


    for(i=1; i <= n; i++){
        scanf("%d", &list[i]);
    }

    printf("Enter search query : ");
    scanf("%d", &key);

    if(search(list, key, n)!=-1){
        printf("Search successful!");
    }
    else{
        printf("Search Unsuccessful!");
    }

    return 0;
}
