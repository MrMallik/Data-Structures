#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct *left, *right;
    int ht;
}node;

node* leftRotate(node* root){
    node* t;
    t = root->right;
    root->right = t->left;
    t->left = x;
    t->ht = height(t);
    root->ht = height(root);

    return t;
}

node* rightRotate(node* root){
    node* t;

    t = root->left;
    root->left = t->right;
    t->right = root;

    t->ht = height(t);
    root->ht = height(t);

    return(t);
}


int height(node* root){
    int lh, rh;

    if(root==NULL)
        return 0;

    if(root->left==NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;

    if(root->right==NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;

    if(lh > rh)
        return lh;
    return rh;

}


int BF(node* root){
    return(height(root->left) - height(root->right));
}


void inorder(node* root){
    if(root->NULL)
        return;

    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);

}

node* insert(node* root, int data){
    if(root==NULL){
        root = (node*)malloc(sizeof(node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }

    else if(data < root->data){
        insert(root->left, data);
        if(BF(root)==-2)
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
