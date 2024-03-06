#include <stdio.h>

struct stack {

}

int precedence() {
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else 
        return 0;
}

int isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}

int isEmpty(struct stack *ptr) {
    return ptr -> top == -1;
}

int isFull(struct stack *ptr) {
    return ptr -> top == ptr -> size-1;
}

int stackTop(struct stack *sp) {
    return sp -> arr(sp->top);
}

void push(struct stack *ptr, char val) {
    if(isFull(ptr))
        printf("Stack Overflow!");
    else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

void pop(struct stack *ptr) {
    if(isEmpty(ptr)) {
        printf("Stack Underflow!");
    return -1;
    }
} 

int main()
{
    return 0;
}
