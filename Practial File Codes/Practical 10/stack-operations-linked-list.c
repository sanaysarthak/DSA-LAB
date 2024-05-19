// Program in C to implement stack operations using Linked List

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head;

void push() {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("Memory Overflow!\n");
    else {
        int val;
        printf("Enter the value: ");
        scanf("%d", &val);
        ptr -> data = val;
        if(head == NULL) 
            ptr -> next = NULL;
        else
            ptr -> next = head;
        head = ptr;
    }
}

void pop() {
    int item;
    struct node *ptr;
    if(head == NULL)
        printf("Underflow!\n");
    else {
        item = head -> data;
        ptr = head;
        head = head -> next;
        free(ptr);
        printf("Popped Element: %d\n", item);
    }
}

void peep() {
    struct node* ptr = head;
    if(ptr == NULL)
        printf("Stack is empty! Underflow!\n");
    else {
        while(ptr -> next != NULL) {
            ptr = ptr -> next;
        }
        printf("Peeped Element: %d\n", ptr -> data);
    }
}

void display() {
    struct node* ptr = head;
    if(ptr == NULL) 
        printf("Stack is empty! Underflow!\n");
    else {
        printf("Elements in the stack are:- \n");
        while(ptr != NULL) {
            printf("%d\t", ptr -> data);
            ptr = ptr -> next;
        }
        printf("\n");
    }
}

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
            printf("\nExited the program successfully.\n");
            break;

        default:
            printf("Enter correct choice.\n");
            break;
        }

    } while(ch!=0);
    return 0;
}
