#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void insert_at_end(List *list, int data) {
	Node *new_struct=(Node *)malloc(sizeof(Node));
	new_struct->data=data;
	new_struct->link=NULL;
	
	if(list->head==NULL)
	{
		list->head=new_struct;
	}
	else
	{
		Node *temp_struct=list->head;
		while(temp_struct->link!=NULL)
		{
			temp_struct=temp_struct->link;
			}
			temp_struct->link=new_struct;
			list->number_of_nodes++;
		
	}
}

void list_delete_front(List* list) {
	Node *head_ptr=list->head;
	Node *temp_struct=(Node *)malloc(sizeof(Node));
	temp_struct=head_ptr;
	(list->head)=head_ptr->link;
	free(temp_struct);
	list->number_of_nodes--;
}

void list_insert_at (List *list, int data, int position)
{
	if (position<0 || position>(++(list->number_of_nodes)))
	{
		return;
	}
	else
	{
		if (position==0)
		{
			Node *new_struct=(Node *)malloc(sizeof(Node));
    			new_struct->data = data;
			new_struct->link = list->head;
			list->head = new_struct;
			list->number_of_nodes += 1;
		}
		else
		{
			Node *new_struct = (Node *)malloc(sizeof(Node));
    			new_struct->data = data;
			Node *temp_struct= list->head;
			for (int index = 0; index <= position; index++) 
			{
				if (index == position - 1) 
				{
					new_struct->link = temp_struct->link;
					temp_struct->link = new_struct;
					list->number_of_nodes += 1;
				}
				temp_struct = temp_struct->link;
			}
				
		}
	}

}

void list_reverse(List* list)
{
 	Node *previous=NULL,*current=(list->head),*next;
	while(current)
	{
		next=current->link;
		current->link=previous;
		previous=current;
		current=next;
	}
	list->head=previous;
}


