#include "et.h"

int isoper(char ch)
{
    if (ch=='+' || ch== '-' || ch=='*' || ch=='/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(Node **stk,int *top,Node *temp)
{
    ++*top;
    stk[*top]=temp;
}

Node *pop(Node **stk,int *top)
{
    Node *dummy = stk[*top];
    --*top;
    return dummy;
}

Node *createExpressionTree(char* a,int len)
{
    char current;
    Node *stack[100];
    
    int top_of_stack = -1;
    int cur_position = 0;
    Node *temp_node;
    
    while(a[cur_position]!='\0')
    {
        current = a[cur_position];
        
        temp_node = (Node*)malloc(sizeof(Node));
        temp_node->data = current;
        temp_node->left = NULL;
        temp_node->right = NULL;
        temp_node->prev = NULL;
        
        if (isoper(current))
        {
            temp_node->right = pop(stack,&top_of_stack);
            temp_node->left = pop(stack,&top_of_stack);
            push(stack,&top_of_stack,temp_node);
        }
        else
        {
            push(stack,&top_of_stack,temp_node);
        }
        cur_position++;
    }
    return (pop(stack,&top_of_stack));
}


void inorder(Node *root)
{
 if (root!=NULL)
 {
     inorder(root->left);
     printf("%c",root->data);
     inorder(root->right);
 }
  
}

void Preorder(Node *root)
{
 if (root!=NULL)
 {
     printf("%c",root->data);
     Preorder(root->left);
     Preorder(root->right);
 }
}

void Postorder(Node *root)
{
 if(root!=NULL)
 {
     Postorder(root->left);
     Postorder(root->right);
     printf("%c",root->data);
 }
   
}

void freeTree(Node *root)
{
    if (root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}




