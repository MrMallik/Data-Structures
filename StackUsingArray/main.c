#include <stdio.h>
#include <stdlib.h>

int stack[30], size = 0, top = -1;

void peek(){
    if(!isEmpty())
    printf("%d ",stack[top]);
    else{
        printf("Stack is EMPTY!");
    }
}

int isEmpty(){
    return(top < 0);
}

int isFull(){
    return(top==size-1);
}

int push(int x){
    if(isFull())
        printf("Stack is full. Can't perform operation!");
    else{
        stack[++top] = x;
    }
}

int pop(){
    if(isEmpty())
        printf("Stack is empty. Can't perform operation!");
    else{
        top--;
    }
}

int putStack(){

    printf("---------STACK---------\n");

    if(!isEmpty()){
    for(int i = top; i>=0; i--){
        printf("%d\n", stack[i]);
        }
    }
    else{
        printf("Stack is EMPTY!");
    }

    printf("\n");
}

int main()
{
    int ch,x;

    printf("Enter size of stack : ");
    scanf("%d", &size);

    printf("\n");

    do{

    printf("1 : Push\n");
    printf("2 : Pop\n");
    printf("3 : Peek\n");
    printf("4 : isEmpty?\n");
    printf("5 : isFull?\n");
    printf("6 : Display Stack\n");
    printf("7 : Exit\n\n");
    scanf("%d", &ch);
    if(ch!=7 && (ch > 6 || ch < 1))
        printf("Invalid Choice. Try Again!\n");

    printf("\n");
    switch(ch){
    case 1 : printf("\nEnter element : ");
             scanf("%d",&x);
             push(x);
             break;

    case 2 : printf("\nEnter element : ");
             scanf("%d",&x);
             pop(x);
             break;

    case 3 : peek();
             break;

    case 5 : if(isFull()){
                printf("Stack is Full!");
            }
            else{
                printf("Stack is not yet full!");
            }
            break;

    case 4 : if(isEmpty()){
                printf("Stack is empty!");
            }
            else{
                printf("Stack is not yet empty!");
            }
            break;

    case 6 : putStack();
             break;
    }
    printf("\n\n");
  }
  while(ch!=7);

    return 0;
}
