#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
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

void DeleteAtFrnt(){
    if(start==NULL){
        printf("Operation not possible!");
        return;
    }
    else{
        start = (*start).next;
        ctr--;
    }
}

void DeleteAtEnd(){
    if(start==NULL){
        printf("Operation is not possible!");
        return;
    }

    struct node *prev, *currnt;

    prev = start;
    currnt = start->next;

    while(currnt->next!=NULL){
        currnt = currnt->next;
        prev = prev->next;
    }

    prev->next = NULL;
    ctr--;
}

void DeleteAtN(int n){

    if(n==1){
        DeleteAtFrnt();
    }

    else if(n==ctr){
        DeleteAtEnd();
    }

    else{
            struct node *prev, *nxt;

        prev = start;
        nxt = start->next;

        for(int i=1; i<=n-2; i++){
            nxt = nxt->next;
            prev = prev->next;
        }
        nxt = nxt->next;
        prev->next = nxt;
    }
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

int main()
{
    int ch,x,n;

    while(1){

        printf("1 : Insert At Front\n");
        printf("2 : Delete At Front\n");
        printf("3 : Insert At End\n");
        printf("4 : Delete At End\n");
        printf("5 : Insert At N\n");
        printf("6 : Delete At N\n");
        printf("7 : Traverse Linked List\n");
        printf("8 : Exit\n");

        scanf("%d", &ch);
        if(ch==1 || ch==3 || ch==5){
            printf("\nEnter data : ");
            scanf("%d", &x);

            if(ch==5 || ch==6){
                printf("\nEnter position : ");
                scanf("%d", &n);
            }
        }

        switch(ch){
            case 1 : insertAtFrnt(x);   break;
            case 2 :  DeleteAtFrnt();   break;
            case 3 : insertAtEnd(x);    break;
            case 4 : DeleteAtEnd();     break;
            case 5 : insertAtN(n,x);    break;
            case 6 : DeleteAtN(n);      break;
            case 7 : traverse();        break;
            case 8 : exit(0);
        }

        printf("\n\n\n");
    }


    return 0;
}
