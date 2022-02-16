#include<stdio.h>
#include "bst.h"
void tree_initialize(Tree *tree)
{
    tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
}

void tree_insert(Tree *tree, int data)
{
    Node *dummy_root = tree->root;
    Node *dummy = NULL;
    
    Node *temp_node = (Node*)malloc(sizeof(Node));
    temp_node->data = data;
    temp_node->right = NULL;
    temp_node->left = NULL;
    
    while (dummy_root!=NULL)
    {
        dummy = dummy_root;
        if (data < dummy_root->data)
        {
            dummy_root = dummy_root->left;
        }
        else
        {
            dummy_root = dummy_root->right;
        }
    }
    
    
    if (dummy == NULL)
    {
        tree->root = temp_node;
    }
    else if (data < dummy->data)
    {
        dummy->left = temp_node;
    }
    else
    {
        dummy->right = temp_node;
    }
    
}
void tree_delete(Tree *tree, int element)
{
    Node *temp_node,*current_node,*previous_node;
    previous_node = NULL;
    current_node = tree->root;
    
    while ((current_node!=NULL) && (current_node->data!=element))
    {
        previous_node = current_node;
        if (element < current_node->data)
        {
            current_node = current_node->left;
        }
        else
        {
            current_node = current_node->right;
        }
    }
    
    if (current_node==NULL)
    {
        return;
    }
    
    if ((current_node->left == NULL) || (current_node->right == NULL))
    {
        Node *dummy=NULL;
        
        if (current_node->left == NULL)
        {
            dummy = current_node->right;
        }
        else
        {
            dummy = current_node->left;
        }
        
        if (previous_node == NULL)
        {
            free(current_node);
            tree->root = dummy;
            return;
        }
        
        if (current_node == previous_node->left)
        {
            previous_node->left = dummy;
        }
        else
        {
            previous_node->right = dummy;
        }
        
        free(current_node);
    }
    
    else
    {
        Node *dummy = NULL;
        temp_node = current_node->right;
        
        while(temp_node->left!=NULL)
        {
            dummy = temp_node;
            temp_node = temp_node->left;
        }
        
        current_node->data = temp_node->data;
        if (dummy!=NULL)
        {
            dummy->left = temp_node->right;
        }
        else
        {
            current_node->right = temp_node->right;
        }
        
        current_node->data = temp_node->data;
        free(temp_node);
    }
    
    return;
}

void tree_inorder(Node *r)
{
 	if (r!=NULL)
    {
        tree_inorder(r->left);
        printf("%d ",r->data);
        tree_inorder(r->right);
    }
}

void tree_preorder(Node *r)
{
    if (r!=NULL)
    {
        printf("%d ",r->data);
        tree_preorder(r->left);
        tree_preorder(r->right);
    }
}

void tree_postorder(Node *r)
{
    if (r!=NULL)
    {
        tree_postorder(r->left);
        tree_postorder(r->right);
        printf("%d ",r->data);
    }
}

void postorder(Tree *t)
{
    tree_postorder(t->root);
    printf("\n");
}

void preorder(Tree *t)
{
    tree_preorder(t->root);
    printf("\n");
}

void inorder(Tree *t)
{
    tree_inorder(t->root);
    printf("\n");
}

void destroy(Node *r)
{
   if (r!=NULL)
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
