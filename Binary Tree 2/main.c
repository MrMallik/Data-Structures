#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node *create_node(int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
};

void insert_left(struct node *root, int data){
    struct node *ptr;
    if(root==NULL){
     ptr = create_node(data);
    }
    else{
        insert_left(root->left, data);
    }
}

void insert_right(struct node *root, int data){
    struct node *ptr;
    if(root==NULL){
        ptr = create_node(data);
    }
    else{
        insert_left(root->right, data);
    }
}

void traverse(struct node *root){
    printf("Root node : %d", root->data);
    printf("\nLeft Subtreee : ");
    printLeft(root->left);
    printf("\nRight Subtree : ");
    printRight(root->right);
}

void printLeft(struct node *root){
    if(root==NULL){
        return;
    }
    else{
        printf("%d ",root->data);
    }

    printLeft(root->left);
}

void printRight(struct node *root){
    if(root==NULL){
        return;
    }
    else{
        printf("%d ",root->data);
    }

    printRight(root->right);
}

int main()
{
    struct node *root, *ptr;

    root = create_node(35);
    /*root->left = create_node(25);
    root->right = create_node(45);
    root->left->left = create_node(15);
    root->right->right = create_node(55);
    root->left->left->left = create_node(5);
    root->right->right->right = create_node(65);*/
    insert_left(root->left, 25);
    insert_right(root->right, 45);
    traverse(root);
    printf("\n");
    return 0;
}
