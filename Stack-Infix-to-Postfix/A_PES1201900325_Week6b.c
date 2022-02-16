#include "6b.h"

stack* stack_initialize(int size)
{
    stack *new_stack = (stack*)malloc(sizeof(stack));
    new_stack->arr = (int*)malloc(size*sizeof(int));
    new_stack->top = -1;
    return new_stack;
}

void stack_push(stack *ptr_stack, int key) 
{
    if (ptr_stack->top == 1999)
    {
        exit(1);
    }
    else
    {
        ptr_stack->top++;
        ptr_stack->arr[ptr_stack->top] = key;
    }
}

void stack_pop(stack *ptr_stack)
{
    if (!stack_is_empty(ptr_stack))
    {
        ptr_stack->top--;
    }
}

int stack_is_empty(stack *ptr_stack)
{
    return (ptr_stack->top == -1);
}

int stack_peek(stack *ptr_stack) 
{
    return (ptr_stack->arr[ptr_stack->top]);
}

void stack_destroy(stack *ptr_stack) 
{
    while (!stack_is_empty(ptr_stack))
    {
        free(ptr_stack->arr);
        ptr_stack->top--;
    }
    free(ptr_stack);
}

int input_precedence(char ch)
{
     switch(ch)
     {
    case '+':
    case '-': return 1;
             break;
    case '*':
    case '/': return 3;
             break;
    case '^': return 6;
             break;
    case '[':
    case '{':
    case '(': return 9;
             break;
    case ']':
    case '}':
    case ')': return 0;
             break;
    default : return 7;
         }
}

int operand_stack_precedence(char test)
{
    switch(test)
    {
        case '+':
        case '-': return 2;
            break;
        case '*':
        case '/': return 4;
            break;
        case '^': return 5;
            break;
        case '(':
        case '[':
        case '{': return 0;
            break;
        case '#': return -1;
            break;
        default: return 8;
    }
}

int match_parenthesis(const char* string)
{
    stack *paranthesis_stack = stack_initialize(strlen(string));
    
    while ( ((*string))!='\0')
    {
        switch (*string)
        {
            case '(': stack_push(paranthesis_stack,1);
                break;
            case '{': stack_push(paranthesis_stack,2);
                break;
            case '[': stack_push(paranthesis_stack,3);
                break;
            case ')':
                if (stack_is_empty(paranthesis_stack) == 1)
                    return 0;
                if (stack_peek(paranthesis_stack) ==1)
                    stack_pop(paranthesis_stack);
                else
                    return 0;
                break;
            case '}':
                if (stack_is_empty(paranthesis_stack) == 1)
                    return 0;
                if(stack_peek(paranthesis_stack) == 2)
                    stack_pop(paranthesis_stack);
                else
                    return 0;
                break;
            case ']':
                if (stack_is_empty(paranthesis_stack) == 1)
                    return 0;
                if(stack_peek(paranthesis_stack) == 3)
                    stack_pop(paranthesis_stack);
                else
                    return 0;
                    break;
            default : break;
        }
        string++;
    }
    
    
    int final_value = stack_is_empty(paranthesis_stack);
    if (final_value == 0)
        return 0;
    return 1;
}

void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
{
    stack *operand_stack = stack_initialize(strlen(source_infix));
    stack_push(operand_stack,'#');
    char current;
    int postfix_flag=0;
    int match_test = match_parenthesis(source_infix);
    if (match_test==0)
        exit(0);
    
    for(int infix_flag=0; source_infix[infix_flag]!='\0'; infix_flag++)
    {
        current = source_infix[infix_flag];
    
        while(operand_stack_precedence(stack_peek(operand_stack)) > input_precedence(current))
        {
            target_postfix[postfix_flag++]=stack_peek(operand_stack);
            stack_pop(operand_stack);
        }
         
        if(operand_stack_precedence(stack_peek(operand_stack)) != input_precedence(current))
        {
            stack_push(operand_stack,current);
        }
        
        else
        {
            stack_pop(operand_stack);
        }
    }
    
    while(stack_peek(operand_stack)!='#')
    {
        target_postfix[postfix_flag++]=stack_peek(operand_stack);
        stack_pop(operand_stack);
    }
        
    target_postfix[postfix_flag]='\0';
}
