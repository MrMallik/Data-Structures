#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;
int ctr=0;

void insertAtEnd(int x){

    struct node *new_node;

    new_node = (struct node*)malloc(sizeof(struct node));
    ctr++;

    if(start==NULL){
       start = new_node;
       (*start).data = x;
       (*start).next = NULL;
       return;
    }

    struct node *ptr;
    ptr = start;

    while(ptr->next!=NULL)
        ptr = (*ptr).next;

    ptr->next = new_node;
    new_node->data = x;
    new_node->next = NULL;
}

/*InsertAtFrnt is throwing Segmentation error. Correct this before submission*/

void insertAtFrnt(int x){
    struct node *new_node;

    new_node = (struct node*)malloc(sizeof(struct node));
    ctr++;

    if(start==NULL){
        start = new_node;
        start->data = x;
        start->next = NULL;
        return;
    }


    new_node->data = x;
    new_node->next = start;
    start = new_node;

}

/*Prototype to insert a node at nth position from the start*/
void insertAtN(int n, int x){
    if(n > ctr){
        printf("Operation not possible!\n");
        return;
    }

    else if(n==1){
        insertAtFrnt(x);
    }

    else if(n==ctr+1){
        insertAtEnd(x);
    }

    //Middle case
    else{

    struct node *prev = start, *new_node, *nxt;

    new_node = (struct node*)malloc(sizeof(struct node));

     for(int i = 1;i<=n-2;i++){
          prev = (*prev).next;
     }
     nxt = (*prev).next;
     prev->next = new_node;
     new_node->next = nxt;
     new_node->data = x;
    }
    ctr++;
}

void traverse(){
    if(start==NULL){
        printf("Linked List is Empty!\n");
    }
    else{
        struct node *ptr;

        ptr = start;

        printf("\n\nLinked List is : \n");

        while((*ptr).next!=NULL){
            printf("%d-->", (*ptr).data);
            ptr = (*ptr).next;
        }
        //Print the data item of last node. Cos the last node points to NULL
        printf("%d ", (*ptr).data);
    }
}


void reverse(){
    struct node *ptr;
    ptr = start;
    ptr->prev = NULL;


    while(ptr->next!=NULL){
        ptr = ptr->next;
    }

    //Now we'll start reversing
    start = curr;
    curr->next = prev;

    while(curr->next!=NULL)
}

int main()
{
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    return 0;
}
