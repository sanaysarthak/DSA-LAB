/* Write a C program to implement Doubly Linked List operations:-
Insert at Begin, Insert at End, Insert at Index, 
Delete at Begin, Delete at End, Delete at Index, Display. */

// Program in C to implement doubly linked list operations

// write index based delete_index() function

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

struct node* head;

void insert_start() {
    struct node* ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("Node not created! No memory available!\n");
    else {
        int val;
        printf("Enter data: ");
        scanf("%d", &val);

        ptr -> data = val;
        if(head == NULL) {
            ptr -> next = NULL;
            ptr -> prev = NULL;
        }
        else {
            ptr -> prev = NULL;
            ptr -> next = head;
            head -> prev = ptr;
        }
        head = ptr;
        printf("Node inserted at start.\n");
    }
}

void insert_end() {
    struct node* ptr, *temp;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL) 
        printf("Node not created! No memory available!\n");
    else {
        int val;
        printf("Enter data: ");
        scanf("%d", &val);
        
        ptr -> data = val;
        if(head == NULL) {
            ptr -> next = NULL;
            ptr -> prev = NULL;
            head = ptr;
        }
        else {
            temp = head;
            while(temp -> next != NULL) {
                temp = temp -> next;
            }
            temp -> next = ptr;
            ptr -> prev = temp;
            ptr -> next = NULL;
        }
        printf("Node inserted at end.\n");
    }
}

void insert_index() {
    struct node* ptr, *temp;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL) 
        printf("Node not created! No memory available!\n");
    else {
        int index, val, flag = 0;
        printf("Enter index at which you want to insert node: ");
        scanf("%d", &index);
        printf("Enter data: ");
        scanf("%d", &val);
        temp = head;
        for(int i=0; i<=index; i++) {
            temp = temp -> next;
            if(temp == NULL) {
                printf("Cannot insert node at given index.\n");
                flag = 1;
            }
        }
        ptr -> data = val;
        ptr -> next = temp -> next;
        ptr -> prev = temp;
        temp -> next = ptr;
        temp -> next -> prev = ptr;
        printf("Node inserted at index %d.\n", index);
    }
}

void delete_start() {
    struct node* ptr;
    if(head == NULL)
        printf("Linked List is empty! No nodes exist!\n");
    else if(head -> next == NULL) {
        head = NULL;
        free(head);
        printf("First node deleted.\n");
    }
    else {
        ptr = head;
        head = head -> next;
        head -> prev = NULL;
        free(ptr);
        printf("First node deleted.\n");
    }
}

void delete_end() {
    struct node* ptr;
    if(head == NULL) 
        printf("Linked List is empty! No nodes exist!\n");
    else if(head -> next == NULL) {
        head = NULL;
        free(head);
        printf("Only one node in linked list deleted.\n");
    }
    else {
        ptr = head;
        if(ptr -> next != NULL) 
            ptr = ptr -> next;
        ptr -> prev -> next = NULL;
        free(ptr);
        printf("Last node deleted.\n");
    }
}

void delete_index() {
    struct node *ptr, *temp;  
    int val;  
    printf("Enter the data after which the node is to be deleted: ");  
    scanf("%d", &val);  
    ptr = head;  
    while(ptr -> data != val)  {
        ptr = ptr -> next;
    }  
    if(ptr -> next == NULL)
        printf("Cannot delete.\n");  
    else if(ptr -> next -> next == NULL)  
        ptr ->next = NULL;  
    else {
        temp = ptr -> next;  
        ptr -> next = temp -> next;  
        temp -> next -> prev = ptr;  
        free(temp);  
        printf("Node deleted.\n");  
    }     
}

void display_nodes() {
  struct node *ptr;
  ptr = head;
  if(head ==  NULL) 
    printf("Linked List is empty! No nodes created!\n");
  else {
    printf("The nodes are:-\n");
    while(ptr != NULL) {
      printf("%d\t", ptr -> data);
      ptr = ptr -> next;
    }
    printf("\n");
  }
}

int main() 
{
    printf("Doubly Linked List Operations:-\n");
    int ch;
    do {
        printf("\nEnter 1 for Insertion at Start. \nEnter 2 for Insertion at End. \nEnter 3 for Insertion at given index. \nEnter 4 for Deletion at Start. \nEnter 5 for Deletion at End. \nEnter 6 for Deletion at given index. \nEnter 7 to display. \nEnter 0 to exit. \nEnter choice:-\n");
        scanf("%d", &ch);
        switch(ch) {
        case 1:
            insert_start();
            break;
        
        case 2:
            insert_end();
            break;

        case 3:
            insert_index();
            break;

        case 4:
            delete_start();
            break;

        case 5:
            delete_end();
            break;

        case 6:
            delete_index();
            break;

        case 7:
            display_nodes();
            break;

        case 0:
            printf("\nExited the program successfully!");
            break;

        default:
            printf("Enter correct choice.\n");
            break;
        }
    } while(ch != 0);
    return 0;
}
