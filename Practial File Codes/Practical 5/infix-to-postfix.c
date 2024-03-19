#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    return ptr->top == -1;
}

int isFull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

int stackTop(struct stack* sp)
{
    return sp->arr[sp->top];
}

void push(struct stack* ptr, char val)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}


char pop(struct stack* ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch)
{
    if(ch=='^')
        return 3;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    else
        return 0;
}

int isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'|| ch=='^')
        return 1;
    else
        return 0;
}

char* infixToPostfix(char* infix)
{
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));
    char* postfix = (char*)malloc((strlen(infix)+1) * sizeof(char));
    int i = 0;
    int j = 0;

    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if(precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while(!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[100];
    printf("Enter an infix expression : ");
    scanf("%s", infix);
    printf("Postfix conversion is = %s", infixToPostfix(infix));
    return 0;
}
