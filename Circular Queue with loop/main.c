#include <stdio.h>
#include <stdlib.h>
#define Max 5

char Q[Max];
int front = -1, rear = -1;


void enqueue(char x){

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
            printf("%c", Q[i]);
        }
    }
    else{
            for(int i = 0; i<=rear; i++){
            printf("%c", Q[i]);
            }
        for(int i = front; i<Max; i++){
            printf("%c", Q[i]);
        }

}
    }

int main()
{
    int i = 1;

    for(; i<=5; i++){
        enqueue('a');
        enqueue('b');
        enqueue('+');
        dequeue();
        display();
    }
    return 0;
}
