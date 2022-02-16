#include "6a.h"

static Node* create_Node(int data, Node* link) {
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data; 
	temp -> link = link;
	return temp;
}

void List_initialize(List* ptr_List) 
{
	ptr_List->head = NULL;
	ptr_List->number_of_Nodes = 0;	
}

void List_insert_front(List* ptr_List, int data) 
{
	Node *temp_head = ptr_List->head;
	Node *new_node = create_Node(data,temp_head);
	ptr_List->head = new_node;
	ptr_List->number_of_Nodes++;

}

const int Node_get_data(Node *Node_ptr) 
{
	return (Node_ptr->data);
}

void List_delete_front(List* ptr_List)
{
	Node *to_delete = ptr_List->head;
	ptr_List->head = ptr_List->head->link;
	free(to_delete);
	ptr_List->number_of_Nodes--;
}

void List_destroy(List* ptr_List) 
{
	free(ptr_List);
}


void stack_initialize(Stack *ptr_stack) 
{
	ptr_stack->ptr_List = malloc(sizeof(List));
	List_initialize(ptr_stack->ptr_List);
}

void stack_push(Stack *ptr_stack, int key)
{
	List_insert_front(ptr_stack->ptr_List,key);
}

void stack_pop(Stack *ptr_stack) 
{
	List_delete_front(ptr_stack->ptr_List);
}

int stack_is_empty(Stack *ptr_stack) 
{
	if (ptr_stack->ptr_List->number_of_Nodes != 0)
		return 0;
	else 
		return 1;
	
}

const int stack_peek(Stack *ptr_stack)
{
	int first = ptr_stack->ptr_List->head->data;
	return first;
}

void stack_destroy(Stack *ptr_stack) 
{
	free(ptr_stack);
}

int postfix_eval(const char* expression) 
{
    Stack *current_val=(Stack*)malloc(sizeof(Stack));
    stack_initialize(current_val);
    
    for(int flag = 0; expression[flag] != '\0'; flag++)
    {
        char current = expression[flag];
        if (current=='+' || current=='-' || current=='*' || current=='/' || current=='$')
        {
            int operand2 = (int) current_val->ptr_List->head->data;
            stack_pop(current_val);
            int operand1 = (int) current_val->ptr_List->head->data;
            stack_pop(current_val);
            
            int val;
            switch (current)
            {
                case '+': val = operand1 + operand2;
                    stack_push(current_val,val);
                    break;
                case '-': val = operand1 - operand2;
                    stack_push(current_val,val);
                    break;
                case '*': val = operand1*operand2;
                    stack_push(current_val,val);
                    break;
                case '/': val = operand1/operand2;
                    stack_push(current_val,val);
                    break;
                case '$':
                    for (int exp=1; exp<=operand2; exp++)
                    {
                        val*=operand1;
                    }
                    stack_push(current_val,val);
                    break;
            }
        }
        else
        {
            stack_push(current_val,(int) current - '0');
        }
    }
    return ((int) current_val->ptr_List->head->data);
}
