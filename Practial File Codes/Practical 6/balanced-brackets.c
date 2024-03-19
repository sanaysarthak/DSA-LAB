#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct stack
{
    char ele[MAX];
    int top;
} s;

void push(char item)
{
    if(s.top == (MAX - 1))
        printf("Stack Overflow!\n");
    else
    {
        s.top++;
        s.ele[s.top] = item;
    }
}

void pop() {
    if(s.top == -1)
    {
        printf("Stack Underflow!\n");
        exit(0);
    }
    else
        s.top--;
}

int checkPair(char c1, char c2)
{
    return ((c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}'));
}

int checkBalanced(char *expr, int len)
{
    for(int i=0; i<len; i++)
    {
        if(expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            push(expr[i]);
        }
        else if(expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
        {
            if (s.top == -1)
                return 0;
            else if (checkPair(s.ele[s.top], expr[i]))
            {
                pop();
            }
            else
                return 0;
        }
        else
            continue;
    }
}

int main()
{
    s.top = -1;
    char exp[MAX];
    printf("Enter an expression : ");
    scanf("%s", exp);
    int len = strlen(exp);
    if(checkBalanced(exp, len))
        printf("Expression is balanced.");
    else
        printf("Expression is unbalanced.");
    return 0;
}
