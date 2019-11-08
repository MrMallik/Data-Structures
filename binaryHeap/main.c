#include <stdio.h>
#include <math.h>
#define MAX 20

int heap[MAX];
int ptr = -1; //ptr keeps track where to insert the element

void insert(int x){

    int curr = ptr;
    //Signalling the root node with a parent node at -1
    int parent = (curr==0)?-1 : floor((curr-1) / 2);
    //Signalling terminal left node with a child node at -1
    int left  = ( (2 * curr + 1) < MAX) ? (2 * curr + 1) : -1;
    //Signalling terminal right node with a child node at -1
    int right = ( (2 * curr + 2) < MAX) ? (2 * curr + 2) : -1;

    if(parent==-1 || heap[curr] < heap[parent])
        heap[++ptr] = x;

    //if child is larger, then swap. Also the node shouldn't be the root node
    while(parent!=-1 && heap[curr] > heap[parent]){

        swap(&heap[parent], &heap[curr]);
        curr = parent;
        parent = (curr==0)?-1 : floor((curr-1) / 2);
    }
}

void delete(){
    //First delete the root node and replace with last element
    heap[0] = heap[ptr];
    ptr--; //Delete the last element

    int curr = 0;
    int left = 2 * curr + 1;
    int right = 2 * curr + 2;

    int pos = (heap[left] > heap[right]) ? heap[left] : heap[right];

    while(heap[pos] > heap[curr]){
        swap(&heap[curr], &heap[pos]);
        curr = (heap[left] > heap[right]) ? left : right;
        left = 2 * curr + 1;
        right = 2 * curr + 2;
        pos = (heap[left] > heap[right]) ? heap[left] : heap[right];
    }

}


void swap(int* num1, int* num2){
    *num1+=(*num2);
    *num2 = *num1 - *num2;
    *num1-=(*num2);
}

void printHeap(){

    for(int i = 0; i <= ptr; i++)
        printf("%d ", heap[i]);
}


int main()
{
    int x,i=0;
    int arr[] = {106,72,12,13,95,-1};

    //printf("Enter data, to exit enter -1 : ");

    while(1){
        //scanf("%d", &x);
        x = arr[i++];
        if(x==-1) break;
        insert(x);
    }

    printf("Heap Data is : ");
    printHeap();
    printf("\nptr = %d", ptr);
    printf("\n\n");


    return 0;
}
