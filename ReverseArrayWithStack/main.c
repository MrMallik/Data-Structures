#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int st[30], arr[10];
int top = -1;

void push(int x){
    st[++top] = x;
}

void reverse(){
    int i;

    for(i = 0; i < MAX; i++){
        push(arr[i]);
    }

    for(i = top; i >=0; i--){
        arr[top - i] = st[i];
    }
}

void display(){
    int i;

    for(i = 0; i < MAX; i++){
        printf("%d ",arr[i]);
    }
}

int main()
{
    int i;

    printf("Enter 5 array elements\n");

    for(i = 0; i < MAX; i++){
        scanf("%d", &arr[i]);
    }

    printf("Array Before Operation : ");
    display();
    printf("\n\n");
    printf("Array After Operation : ");
    reverse();
    display();

    return 0;
}
