#include "6b.h"

int input_prec(char ch)
{
	switch(ch)
	{
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^': return 6;
        case '[':
        case '{':
        case '(': return 9;
        case '}':
        case ']':
        case ')': return 0;
        default : return 7;
	}
}

int stack_prec(char ch)
{
	switch(ch)
	{
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 5;
        case '{':
        case '[':
        case '(': return 0;
        case '#': return -1;
        default : return 8;
	}
}


stack* stack_initialize(int size)
{
    stack *stk = (stack *)malloc(sizeof(stack));
    stk->arr = (int *)malloc(sizeof(int) * size);
    stk->top = -1;
    return stk;
}

void stack_push(stack *ptr_stack, int key) 
{
    ptr_stack->top++;
    ptr_stack->arr[ptr_stack->top] = key;
}

void stack_pop(stack *ptr_stack)
{
    if(stack_is_empty(ptr_stack))
    {
        return;
    }
    ptr_stack->top--;
}

int stack_is_empty(stack *ptr_stack)
{
    return (ptr_stack->top == -1);
}

int stack_peek(stack *ptr_stack) 
{
    return ptr_stack->arr[ptr_stack->top];
}

void stack_destroy(stack *ptr_stack) 
{
    while(stack_is_empty(ptr_stack) == 0)
    {
        free(ptr_stack->arr + ptr_stack->top);
        ptr_stack->top--;
    }
    free(ptr_stack);
}

void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
{
    stack *s = stack_initialize(strlen(source_infix));
	char check;
	int i=0,j=0;
	stack_push(s, '#');

	while(source_infix[i]!='\0')
	{
        check = source_infix[i];
        
        while(stack_prec(stack_peek(s))>input_prec(check))
        {
            target_postfix[j++]=stack_peek(s);
            stack_pop(s);
        }
        
        if(stack_prec(stack_peek(s))!=input_prec(check))
        {
            stack_push(s, check);
        }
        else 
        {
            stack_pop(s);
        }
        i++;
    }
	
	while(stack_peek(s)!='#')
    {
		target_postfix[j++]=stack_peek(s);
        stack_pop(s);
    }
    target_postfix[j]='\0';
}