#include <stdio.h>
#include <stdlib.h>

#define MAX 5

/**
*Implementation of a Linear Queue
*@author - Pritabrata Mallik
*/


int queue[MAX], frnt = -1, rer = -1;


int isEmpty(){
    return(frnt==-1 && rer==-1);
}

int isFull(){
    return(rer==MAX-1);
}

void enqueue(int x){
    if(isFull()){
        printf("Queue is full!");
    }
    else{
        queue[++rer] = x;
    }
}

void dequeue(){
    if(frnt==-1)
        frnt++;

    if(isEmpty()){
        printf("Queue is Empty!");
    }
    else{
        frnt++;
    }
}

void display(){
    printf("\n");
    for(int i = frnt; i <= rer; i++){
        printf("%d ", queue[i]);
    }
}


int main()
{

    enqueue(35);
    enqueue(48);
    enqueue(102);
    enqueue(536);
    enqueue(432);
    display();

    return 0;
}
