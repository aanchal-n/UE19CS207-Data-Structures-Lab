#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree)
{
    tree->root=NULL;
}

void tree_insert(Tree *tree, int data)
{
    Node* temp;
    Node *p,*curr;
    curr=tree->root;
    p=NULL;
    while(curr!=NULL)
    {
        p=curr;
        if(data<curr->data)
        {
            if(curr->leftThread==0)
                curr=curr->left;
            else
                break;
        }
        else
        {
            if(curr->rightThread==0)
                curr=curr->right;
            else
                break;
        }
    }
    temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->leftThread=1;
    temp->rightThread=1;
    if(tree->root==NULL)
    {
        tree->root=temp;
        return;
    }
    if(data<curr->data)
    {
        temp->left=p->left;
        temp->right=p;
        p->leftThread=0;
        p->left=temp;
    }
    else
    {
        temp->right=p->right;
        temp->left=p;
        p->right=temp;
        p->rightThread=0;
    }
}

Node *inorder_predecessor(Node *ptr)
{
    if(ptr->leftThread==1)
        return ptr->left;
    ptr=ptr->left;
    while(ptr->rightThread==0)
        ptr=ptr->right;
    return ptr;
}

Node *inorder_successor(Node *ptr)
{
   if(ptr->rightThread==1)
        return ptr->right;
    else
    {
    ptr=ptr->right;
    while(ptr->leftThread==0)
        ptr=ptr->left;
    return ptr;
    }
}

void print_ascending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    Node *temp;
    temp=tree->root;
    while(temp->leftThread==0)
        temp=temp->left;
    while(temp!=NULL)
    {
        printfun(temp->data);

        temp=inorder_successor(temp);
    }
    nextline();
}

void print_descending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    Node *temp;
    temp=tree->root;
    while(temp->rightThread==0)
        temp=temp->right;
    while(temp!=NULL)
    {
        printfun(temp->data);
        temp=inorder_predecessor(temp);
    }
    nextline();
// TODO : Use printf() specified in tbtmain.c. Dont use printf statement
}

void destroy(Node *r)
{
    if(r!=NULL)
    {
        destroy(r->left);
        destroy(r->right);
        free(r);
    }
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}
