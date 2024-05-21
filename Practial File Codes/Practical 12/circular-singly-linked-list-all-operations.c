// Program in C to implement a circular singly linked list which performs all the operations (insertion -> at start, at end, and at index), (deletion -> at start, at end, and at index), and display

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head;

void insert_start() {
    struct node* ptr, *temp;
    int val;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("Linked List is empty! No nodes created!\n");
    else {
        printf("Enter data: ");
        scanf("%d", &val);
        ptr -> data = val;
        if(head == NULL) {
            head = ptr;
            ptr -> next = head;
        }
        else {    
            temp = head;  
            while(temp -> next != head) {
                temp = temp->next;  
            }
            ptr -> next = head;  
            temp -> next = ptr;  
            head = ptr;  
        }  
        printf("Node inserted at start.\n");    
    }
}

void insert_end() {
    struct node *ptr, *temp;  
    int val;  
    ptr = (struct node*)malloc(sizeof(struct node));  
    if(ptr == NULL)
        printf("Linked List is empty! No nodes created!\n");
    else {
        printf("Enter data: ");  
        scanf("%d", &val);  
        ptr -> data = val;  
        if(head == NULL)
            head = ptr;
        else {
            temp = head;
            while(temp -> next != head)
                temp = temp -> next;
            temp -> next = ptr;  
        }
        ptr -> next = head;
        printf("Node inserted at end.\n");  
    }  
}

void insert_index() {
    struct node *ptr, *temp;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL) {
        printf("Node not created! No memory available!\n");
        return;
    }
    int index, val;
    printf("Enter index at which you want to insert node: ");
    scanf("%d", &index);
    printf("Enter data: ");
    scanf("%d", &val);
    ptr -> data = val;
    if(index == 0) {
        ptr->next = head;
        head = ptr;
        printf("Node inserted at index %d.\n", index);
        return;
    }
    temp = head;
    for(int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Cannot insert at index %d. Index out of range.\n", index);
        free(ptr);
        return;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    printf("Node inserted at index %d.\n", index);
}

void delete_start() {
    struct node *ptr;  
    if(head == NULL)
        printf("Linked List is empty! No nodes exist!\n");
    else if(head->next == head) {  
        head = NULL;  
        free(head);  
        printf("First node deleted.\n");  
    }  
    else {
        ptr = head;  
        while(ptr -> next != head) {
            ptr = ptr -> next;  
        }
        ptr -> next = head->next;  
        free(head);  
        head = ptr -> next;  
        printf("First Node deleted\n");  
    }  
}

void delete_end() {
    if(head == NULL) {
        printf("Linked List is empty! No nodes exist!\n");
        return;
    }
    struct node *ptr, *preptr;
    ptr = head;
    while(ptr->next != head) {
        preptr = ptr;
        ptr = ptr->next;
    }
    if(ptr == head) {
        free(ptr);
        head = NULL;
    } else {
        preptr->next = ptr->next;
        free(ptr);
    }
    printf("Last node deleted.\n");
}

void delete_index() {
    struct node *ptr, *prev;
    if(head == NULL) {
        printf("Linked List Empty! No nodes exist!\n");
        return;
    }
    int index;
    printf("Enter index of the node to be deleted: ");
    scanf("%d", &index);
    if (index == 0) {
        ptr = head;
        while(ptr->next != head) {
            ptr = ptr->next;
        }
        if (ptr == head) {
            free(head);
            head = NULL;
        } else {
            ptr->next = head->next;
            free(head);
            head = ptr->next;
        }
        printf("Node deleted at index %d.\n", index);
        return;
    }
    ptr = head->next;
    prev = head;
    for(int i = 1; i < index; i++) {
        if (ptr == head) {
            printf("Cannot Delete! The given index is greater than no. of existing nodes!\n");
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    free(ptr);
    printf("Node deleted at index %d.\n", index);
}

void display_nodes() {
    struct node* ptr;
    ptr = head;
    if(head == NULL)
        printf("Linked List is empty! No nodes exist!\n");
    else {
        printf("Nodes in the Linked List are:-\n");
        while(ptr -> next != head) {
            printf("%d\t", ptr -> data);
            ptr = ptr -> next;
        }
        printf("%d\n", ptr -> data);
    }
}

int main() {
    printf("Circular linked list operations:-\n");
    int ch;
    printf("\nEnter 1 for Insertion at Start. \nEnter 2 for Insertion at End. \nEnter 3 for Insertion at given index. \nEnter 4 for Deletion at Start. \nEnter 5 for Deletion at End. \nEnter 6 for Deletion at given index. \nEnter 7 to display. \nEnter 0 to exit.\n");
    do {
        printf("\nEnter choice:-\n");
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
