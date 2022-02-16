#include "5a.h"

static Node* create_Node(int data, Node* link)
 {
     Node *new_node = (Node*)malloc(sizeof(Node));
     new_node->data = data;
     new_node->link = link;
     return new_node;
}


void list_initialize(List* ptr_list) 
{
    ptr_list->head = NULL;
    ptr_list->number_of_Nodes = 0;
}


void list_insert_front(List* ptr_list, int data) 
{
    Node *temp_head = ptr_list->head;
    struct Node *new_node = create_Node(data,temp_head);
    ptr_list->head = new_node;
    ptr_list->number_of_Nodes++;
}


const int Node_get_data(Node *Node_ptr) 
{
    return (Node_ptr->data);
}


void list_delete_front(List* ptr_list) 
{
    Node *to_delete = ptr_list->head;
    ptr_list->head = ptr_list->head->link;
    free(to_delete);
    ptr_list->number_of_Nodes--;
}


void list_destroy(List* ptr_list) 
{
    free(ptr_list);
}

void Stack_initialize(Stack *ptr_Stack) 
{
    ptr_Stack->ptr_list = malloc(sizeof(struct List));
    list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack *ptr_Stack, int key) 
{
    list_insert_front(ptr_Stack->ptr_list,key);
}

void Stack_pop(Stack *ptr_Stack) 
{
    list_delete_front(ptr_Stack->ptr_list);
}

int Stack_is_empty(Stack *ptr_Stack) 
{
    if (ptr_Stack->ptr_list->number_of_Nodes != 0)
        return 0;
    else
        return 1;
}

const int Stack_peek(Stack *ptr_Stack) 
{
    int first = ptr_Stack->ptr_list->head->data;
    return first;
}

void Stack_destroy(Stack *ptr_Stack)
 {
     free(ptr_Stack);
}

int match_parenthesis(const char* string)
{
    Stack paranthesis_stack;
    Stack_initialize(&paranthesis_stack);
    while ( ((*string))!='\0')
    {
        switch (*string)
        {
            case '(': Stack_push(&paranthesis_stack,1);
                break;
            case '{': Stack_push(&paranthesis_stack,2);
                break;
            case '[': Stack_push(&paranthesis_stack,3);
                break;
            case ')':
                if (Stack_is_empty(&paranthesis_stack) == 1)
                    return 0;
                if (Stack_peek(&paranthesis_stack) ==1)
                    Stack_pop(&paranthesis_stack);
                else
                    return 0;
                break;
            case '}':
                if (Stack_is_empty(&paranthesis_stack) == 1)
                    return 0;
                if(Stack_peek(&paranthesis_stack) == 2)
                    Stack_pop(&paranthesis_stack);
                else
                    return 0;
                break;
            case ']':
                if (Stack_is_empty(&paranthesis_stack) == 1)
                    return 0;
                if(Stack_peek(&paranthesis_stack) == 3)
                    Stack_pop(&paranthesis_stack);
                else
                    return 0;
                    break;
            default : break;
        }
        string++;
    }
    
    
    int final_value = Stack_is_empty(&paranthesis_stack);
    if (final_value == 0)
        return 0;
    return 1;
}


 

