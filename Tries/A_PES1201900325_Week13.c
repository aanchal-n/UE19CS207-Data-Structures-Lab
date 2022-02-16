#include<stdio.h>
#include "trie.h"
struct trienode *getnode()
  {
    struct trienode *new_node=(struct trienode*)malloc(sizeof(struct trienode));
    for (int j=0;j<256;j++)
    {
      new_node->child[j]=NULL;
    }
    new_node->endofword=0;
    return new_node;
  }

  void insert(struct trienode *root, char *key)
  {
    struct trienode *current_node = root;
    int dummy;

    for (int i=0;key[i]!='\0';i++)
    {
      dummy=key[i];
      if (current_node->child[dummy]==NULL)
      {
        current_node->child[dummy]=getnode();
      }
      current_node=current_node->child[dummy];
    }
    current_node->endofword=1;
  }
void display(struct trienode *curr)
  {
    int index,i;
    for (i=0;i<256;i++)
    {
      if(curr->child[i]!=NULL)
      {
        word[length++]=i;
        if (curr->child[i]->endofword ==1)
        {
          printnewline();
          for (index=0;index<length;index++)
          {
            printfun(word[index]);
          }
        }
        display(curr->child[i]);
      }
    }
    length--;
    return;
 }

  int search(struct trienode * root,char *key)
  {
    struct trienode *current_node = root;
    int dummy;
    for (int i=0;key[i]!='\0';i++)
    {
      dummy=key[i];
      if (current_node->child[dummy]==NULL)
      {
        return 0;
      }
      current_node=current_node->child[dummy];
    }
    if(current_node->endofword==1)
    {
      return 1;
    }
    return 0; 
  }


 void delete_trie(struct trienode *root,char *key)
  {
    struct stack dummy;
    struct trienode *current_node=root;
    int index;
    for (int i=0;key[i]!='\0';i++)
    {
      index=key[i];
      if (current_node->child[index]==NULL)
      {
        return;
      }
      push(current_node,index);
      current_node=current_node->child[index];
    }
    current_node->endofword=0;
    push(current_node,-1);
    int flag;
    while (1)
    {
      dummy=pop();
      if (dummy.index!=-1)
      {
        dummy.m->child[dummy.index]=NULL;
      }
      if(dummy.m==root)
      {
        break;
      }
      flag=check(dummy.m);
      if((flag>=1)||(dummy.m->endofword==1))
      {
        break;
      }
      else
      {
        free(dummy.m);
      }
    }
    return;
  }

  int check(struct trienode *x)
  {
    int count =0;
    for (int i=0;i<255;i++)
    {
      if(x->child[i]!=NULL)
      {
        ++count;
      }
    }
    return count;
 }

  void push(struct trienode *x,int k)
  {
    ++top;
    s[top].m=x;
    s[top].index=k;
  } 

  struct stack pop()
  {
    struct stack temp_stack;
    temp_stack=s[top--];
    return temp_stack;
  }
