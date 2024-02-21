/*      printf("\n-----------------------------");
        printf("\nSTACK IMPLEMENTATION PROGRAM\n");
        printf("-----------------------------");
        printf("\n     1. Push\n     2. Pop\n     3. Display\n     4. Peep\n     5. Change\n     6. Exit\n");
        printf("-----------------------------\n");
        printf("\n  Enter your choice: ");
        scanf("%d", &choice); */


#include <stdio.h>
#define N 5

int stack[N];
int top = -1;

void push();
void pop();
void peep();
void display();

int main() 
{
    int ch;
    printf("Enter your choice:-\nEnter 1 for push operation.\nEnter 2 for pop operation.\nEnter 3 for peek operation.\nEnter 4 for display operation.\nEnter 0 to exit.\n");
    scanf("%d", &ch);
    do {
        switch (ch)
        {
            case 1: push();
                    break;

            case 2: pop();
                    break;

            case 3: peep();
                    break;

            case 4: display();
                    break;

            default: printf("Invalid choice.");
                    break;
        }
    } while(ch!=0);
    return 0;
}

void push() {
    if (top == N-1)
        printf("Stack Overflow!");
    else {
        int ele;
        printf("Enter element: ");
        scanf("%d", &ele);
        top++;
        stack[top] = ele;
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow!");
    else {
        printf("%d", stack[top]);
        top--;
    }
}


void peep() {
    printf("Code coming soon!");
}

void display() {
    if(top == -1)
        printf("Stack Underflow!");
    else {
        printf("Elements in the stack are:- \n");
        while (top >= 0)
        {
            printf("%d\n", stack[top]);
            top--;
        }
    }  
}
