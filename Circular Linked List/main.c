#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;

void insert(int x){

    struct node *new_node;

    new_node = (struct node*)malloc(sizeof(struct node));

    if(start==NULL){
       start = new_node;
       (*start).data = x;
       (*start).next = new_node;
       return;
    }

    struct node *ptr;
    ptr = start;

    while(ptr->next!=start)
        ptr = (*ptr).next;

    ptr->next = new_node;
    new_node->data = x;
    new_node->next = start;
}

//Get data of (n+1)th element
int getNext(int n){
    int ctr = 1;
    struct node *ptr = start;

    while(ctr!=n){
        ctr++;
        ptr = ptr->next;
    }

    ptr = ptr->next; //going to (n+1)th node

    return(ptr->data);
}


void traverse(){
    if(start==NULL){
        printf("Linked List is Empty!\n");
    }
    else{
        struct node *ptr;

        ptr = start;

        printf("\n\nLinked List is : \n");

        while((*ptr).next!=start){
            printf("%d-->", (*ptr).data);
            ptr = (*ptr).next;
        }
        //Print the data item of last node. Cos the last node points to NULL
        printf("%d ", (*ptr).data);
    }
}


int main()
{
    insert(1);
    insert(2);
    insert(3);
    traverse();
    printf("\n%d",getNext(3));
    return 0;
}
