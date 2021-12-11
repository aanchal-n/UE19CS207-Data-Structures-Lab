#include"dll.h"
int count_nodes(List* dll)
{
	if (dll->head==NULL)
	{
		return 0;
	}
	
	else
	{
		Node *temp_struct=(dll->head);
		int count=0;
		while(temp_struct!=NULL)
		{
			count++;
			temp_struct=temp_struct->next;
		}
		return count;	
	}
}

void insert_front(List* dll, int data)
{
	Node *temp_struct=(dll->head);
	Node *new_struct=(Node *)malloc(sizeof(Node));
	new_struct->data=data;
	new_struct->next=temp_struct;
	new_struct->prev=NULL;
	
	if (temp_struct!=NULL)
		dll->head->prev=new_struct;
		
	dll->head=new_struct;
	dll->number_of_nodes++;
}


void dllist_delete_beginning(List* list)
{
    Node *temp_struct=(Node *)malloc(sizeof(Node));
    
    if (list->head==NULL)
    {
    	return ;
    }
    else if (list->head->next==NULL)
    {
    	list->head=NULL;
    	free(list->head);
    	list->number_of_nodes--;
    }
    else
    {
    	temp_struct=list->head;
    	list->head=list->head->next;
    	list->head->prev=NULL;
    	free(temp_struct);
    	list->number_of_nodes--;
    }
}


void position_delete(List* dll, int pos)
{
    Node *current_struct=dll->head;
    int cur_pos;
    
    if (pos==0)
    {
    	dllist_delete_beginning(dll);
    }
    else if (pos == ((dll->number_of_nodes)-1))
    {
    	Node *to_delete=dll->head;
    	while (to_delete->next!=NULL)
    	{
    		to_delete=to_delete->next;
    	}
    	to_delete->prev->next=NULL;
    	free(to_delete);
    	dll->number_of_nodes--;
    }
    else if (pos>0 && pos<((dll->number_of_nodes)-1))
    {
	for (cur_pos = 0; cur_pos <= pos; cur_pos++) 
	{
		if (cur_pos == pos - 1) 
		{
			current_struct->prev->next=current_struct->next;
			current_struct->next->prev=current_struct->prev;
			free(current_struct);
			dll->number_of_nodes--;
			break;
		}
		
		current_struct = current_struct->next;
	}
    }
}

int search_list(List* dll,int key)
{
    Node *temp_struct=dll->head;
    int flag=0;
    while (temp_struct!=NULL)
    {
    	if (temp_struct->data == key)
    	{
    		return flag;
    	}
    	else if (temp_struct->next==NULL)
    	{
    		return -1;
    	}
    	flag++;
    	temp_struct=temp_struct->next;
    }
}


void reverse_list(List* dll)
{
	Node *current_struct,*temp_struct;
	current_struct=dll->head;
	if (dll->head==NULL)
    	{
    		return;
    	}
    	
    	while (current_struct!=NULL)
    	{
    		temp_struct=current_struct->prev;
    		current_struct->prev=current_struct->next;
    		current_struct->next=temp_struct;
    		current_struct=current_struct->prev;
    	}
    	
    	if (temp_struct!=NULL)
    	{
    		dll->head=temp_struct->prev;
    	}
}


