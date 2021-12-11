#include "poly.h"
void insert_at_end(List *list, int data) 
{
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

long long int evaluate(List *list, int x)
{
    Node *temp_struct=(Node *)malloc(sizeof(Node));
    temp_struct=list->head;
    int cur=1;
    long long int answer=0;
    
    for (int position=0;position<=(list->number_of_nodes);position++)
    {
    	answer+=((temp_struct->data)*cur);
    	temp_struct=temp_struct->link;
    	cur*=x;
    }
    
    return answer;

}
