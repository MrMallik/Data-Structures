#include <stdio.h>
#include <math.h>


/**
* No Duplicate elements are allowed in this implementation of Binary Heap
*/

int heap[100], idx = 0;

void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int getParentIndex(int x){
    int i;
    for(i=0; heap[i]!=x && i<100; i++);
    i--;
    return floor( (i-1) / 2 );
}

int getLeftChildIndex(int x){
    int i;
    for(i=0; i<100 && heap[i]!=x; i++);
    i--;
    return (2 * i + 1);
}

int getRightChildIndex(int x){
    int i;
    for(i=0; i<100 && heap[i]!=x; i++);
    i--;
    return (2 * i + 2);
}

void insert(int x){

    if(idx==99){
        printf("Heap is full, insertion not possible\n");
    }

    heap[idx++] = x;
    reheapUp(x);
}

void reheapUp(int x){

    int parentIdx = getParentIndex(x);

    if(parentIdx < 0)
        return;
    else if(x > heap[parentIdx]){
        swap(&heap[x], &heap[parentIdx]);
        reheapUp(heap[parentIdx]);
    }
}

void writeHeap(){
    for(int i = 0; i < idx; i++)
        printf("%d ", heap[i]);
}



int main()
{
    insert(96);
    insert(34);
    insert(24);
    insert(25);
    writeHeap();
    return 0;
}
