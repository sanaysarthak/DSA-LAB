// Program in C to implement Stack operations using Array

#include <stdio.h>
#define MAX 5

int stack[MAX];
int TOP = -1;

void push();
void pop();
void peep();
void display();

int main() {
    int ch;
    printf("Enter choice to perform operations:-");
    do {
        printf("\nEnter 1 for PUSH.\nEnter 2 for POP.\nEnter 3 for PEEP.\nEnter 4 for DISPLAY.\nEnter 0 to EXIT.\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peep();
            break;
        
        case 4:
            display();
            break;
        
        case 0:
            printf("Exited the program successfully.\n");
            break;

        default:
            printf("Enter correct choice.\n");
            break;
        }

    } while(ch!=0);
    return 0;
}

void push() {
    if(TOP == MAX-1)
        printf("Stack Overflow!\n");
    else {
        TOP++;
        int ele;
        printf("Enter element to be inserted: ");
        scanf("%d", &ele);
        stack[TOP] = ele;
    }
}

void pop() {
    if(TOP == -1)
        printf("Stack Underflow!\n");
    else {
        printf("Popped Element: %d\n", stack[TOP]);
        TOP--;
    }
}

void peep() {
    if(TOP == -1)
        printf("Stack Underflow! There are no elements.\n");
    printf("%d\n", stack[TOP]);
}

void display() {
    if(TOP == -1)
        printf("Stack Underflow! No elements to display.\n");
    int n = TOP;
    while(n >= 0) {
        printf("%d\n", stack[n]);
        n--;
    }
}
