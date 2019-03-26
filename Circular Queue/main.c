#include <stdio.h>
#include <stdlib.h>000000000000000000
#define Max 5

int Q[Max], front = -1, rear = -1;


void enqueue(int x){

    //check if the queue is already full
    if(front==0 && rear==Max-1){
        printf("Queue Overflow!");
        exit(0);
    }

    //check if the queue has vacant place

    else if(front== -1 && rear== -1){
        front = 0;
        rear = 0;
    }

    else if(front!=0 && rear==Max-1){
        rear = 0;
    }

    else{
        rear++;
    }

    Q[rear] = x;
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue Underflow!");
        exit(0);
    }

    //if there is only one element in the queue
    else if(front==rear){
        front = rear = -1;
    }

    else if(front==Max-1){
        front = 0;
    }

    else{
        front++;
    }
}

void display(){
    if(front<rear){
        for(int i = front; i<=rear; i++){
            printf("%d ", Q[i]);
        }
    }
    else{
            for(int i = 0; i<=rear; i++){
            printf("%d ", Q[i]);
            }
        for(int i = front; i<Max; i++){
            printf("%d ", Q[i]);
        }

}
    }

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    enqueue(6);
    dequeue();
    enqueue(476);
    display();
    return 0;
}
