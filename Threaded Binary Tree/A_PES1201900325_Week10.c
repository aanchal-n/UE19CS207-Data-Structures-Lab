#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree)
{
    tree = (Tree*)malloc(sizeof(Tree));
    tree->root =NULL;
}
void tree_insert(Tree *tree, int data)
{
    Node *current_node = tree->root;
    
    Node *temp_node = (Node*)malloc(sizeof(Node));
    temp_node->data = data;
    temp_node->left = NULL;
    temp_node->right = NULL;
    temp_node->leftThread = 1;
    temp_node->rightThread = 1;
    
    Node *dummy_tree = tree->root;
    Node *dummy = NULL;
    
    while (current_node!=NULL)
    {
        dummy = current_node;
        if (data < current_node->data)
        {
            if (current_node->leftThread == 0)
            {
                current_node=current_node->left;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (current_node->rightThread == 0)
            {
                current_node = current_node->right;
            }
            else
            {
                break;
            }
        }
    }
    
    if (dummy_tree==NULL)
    {
        tree->root = temp_node;
        return;
    }
    if(data < current_node->data)
    {
        temp_node->left = dummy->left;
        temp_node->right = dummy;
        dummy->leftThread = 0;
        dummy->left = temp_node;
    }
    else
    {
        temp_node->right = dummy->right;
        temp_node->left = dummy;
        dummy->right = temp_node;
        dummy->rightThread = 0;
    }
    
}

Node *inorder_predecessor(Node *ptr)
{
   if (ptr->leftThread == 1)
   {
       return ptr->left;
   }
    ptr = ptr->left;
   while (ptr->rightThread == 0)
   {
       ptr=ptr->right;
   }
   return ptr;
}

Node *inorder_successor(Node *ptr)
{
   if (ptr->rightThread == 1)
   {
       return ptr->right;
   }
   else
   {
       ptr=ptr->right;
       while (ptr->leftThread== 0)
       {
           ptr=ptr->left;
       }
       return ptr;
   }
}

void print_ascending(Tree *tree)
{
    Node *current_node = tree->root;
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }

    while (current_node->leftThread == 0)
    {
        current_node=current_node->left;
    }

    while(current_node!=NULL)
    {
        printfun(current_node->data);
        current_node = inorder_successor(current_node);
    }
    nextline();
}

void print_descending(Tree *tree)
{
    Node *current_node = tree->root;
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    
    while(current_node->rightThread == 0)
    {
        current_node=current_node->right;
    }

    while(current_node!=NULL)
    {
        printfun(current_node->data);
        current_node = inorder_predecessor(current_node);
    }
    nextline();
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
