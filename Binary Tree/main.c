#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node* create_node(int data){

    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

void traverse(struct node *root){
    printf("Root : %d\n",root->data);
    printf("Left subtree : ");
    printLeft(root->left);
    printf("\nRight subtree : ");
    printRight(root->right);
}

void printLeft(struct node *root){
    if(root==NULL)
        return;
    else
        printf("%d ",root->data);
    printLeft(root->left);
}

void printRight(struct node *root){
    if(root==NULL)
        return;
    else
        printf("%d ",root->data);
    printLeft(root->right);
}

void insertData(struct node *root, int data, char c){
    if(c=='L'||c=='l'){
        if(root==NULL){
            root = create_node(data);
        }
        else{
                insertData(root->left, data, c);
        }
    }
    else if(c=='R' || c=='r'){
        if(root==NULL){
            root = create_node(data);
        }
        else{
                insertData(root->right, data, c);
        }
    }
    else
        return;
}


int main()
{
    struct node *root;
    root->left=root->right=root=NULL;
    int data,ch;

    do{
        if(root==NULL){
        printf("\nEnter root data : ");
        scanf("%d", &data);
        root = create_node(data);
        }

        printf("\n\nWhere would you like to enter the data?\n");
        printf("1. Left Subtree\n");
        printf("2. Right Subtree\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        scanf("%d" ,&ch);

        if(ch!=3 && ch!=4){
            printf("\n\nEnter data to enter in subtree : ");
            scanf("%d", &data);
        }

        switch(ch){
            case 1 : insertData(root->left, data, 'L'); break;
            case 2 : insertData(root->right, data, 'R'); break;
            case 3 : traverse(root); break;
            case 4 : exit(0); break;
            default : printf("Invalid choice, try again!\n\n");
        }
    }
    while(ch > 0 || ch < 5);

    return 0;
}
