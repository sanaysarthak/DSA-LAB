#include <stdio.h>
#include <stdli.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

void insert_start_and_last() {
    struct node *ptr, *temp;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL) 
        printf("Memory Overflow!\n");
    else {
        int val;
        printf("Enter the data: ");
        scanf("%d", &val);
        ptr -> data = val;
        // this is the first node, which we are inserting at beginning
        if(head == NULL) {
            head = ptr;
            ptr -> next = head;
        }
        // there are existing nodes, and we are inserting at beginning
        else {
            temp = head;
            while(temp -> next != head) {
                temp = temp -> next;
            }
            ptr -> next = head;
            temp -> next = ptr; 
            head = ptr;
        }
        printf("Node inserted.");
    }
} 

void insert_index() {
    struct node *ptr, *temp;
    ptr = (struct node*)malloc(sizeof(struct node));
    int index, flag = 0;
    printf("Enter index at which you want to perform insertion: ");
    scanf("%d", &index);
    temp = head;
    // write your own logic
    for(int i=0; i<=index; i++) {
        temp = temp -> next;
        if(temp == head) 
            break;
        ptr -> next = temp;
        temp -> next = ptr;
    }
}

void delete_first() {
    if(head == NULL)
        printf("Linked list is empty.\n");
    else {
        struct node *ptr, *temp;
        ptr = head;
        temp = head;
        while(temp -> next != head) {
            temp = temp -> next;
        } 
        temp -> next = ptr -> next;
        free(ptr);
        head = temp -> next;
        printf("Node deleted.\n");
    }
}

void delete_index() {

}

void delete_last() {
    if(head == NULL) 
        printf("Linked list is empty.\n");
    else if(head -> next == head) {
        free(head);
        printf("Node deleted.")
    }
    else {
        struct node *ptr, *temp;
        ptr = head;
        while(ptr -> next != head) {
            temp = ptr;
            ptr = ptr -> next;
        }
        temp -> next = ptr -> next;
        free(ptr);
        return head;
    }
}

void search() {
    struct node *ptr = head;
    int val, flag=0, i=0;
    if(ptr == NULL)
        printf("linked list is empty.\n");
    else {
        printf("Enter the data which you want to search: ");
        scanf("%d", &val);
        while(ptr -> next != head) {
            if(ptr -> data == val) {
                printf("Item found at node index %d.", i);
                flag = 1;
                i++;
            }
            ptr = ptr -> next;
        }
        if(flag == 0)
            printf("Item not found.\n");
    }
}

void traversal() {
    struct node *ptr = head;
    while(ptr -> next != head) {
        printf("%d\t", ptr -> data);
        ptr = ptr -> next;
    }
}

int main() {
    printf("Circular Linked List Operations.\n\n");
    int ch;
    do {
        printf("\nEnter 1 for Insertion at Start.\nEnter 2 for Insertion at End.\nEnter 3 for Insertion at given index. 
        Enter 4 for Deletion at End.\nEnter 5 for Deletion at End.\nEnter 6 for Deletion at given index. 
        \nEnter 7 for searching element.\nEnter 8 to display nodes.\nEnter 0 to exit.\n");
    	printf("Enter choice: ");
    	scanf("%d", &ch);
 
        switch(ch) {
            case 1:
                insert_start_and_last();
                break;

            case 2:
                insert_start_and_last();
                break;

            case 3:
                insert_index();
                break;

            case 4:
                delete_first();
                break;

            case 5:
                delete_last();
                break;

            case 6:
                delete_index();
                break;

            case 7:
                search();
                break;

            case 8:
                traversal();
                break;
        }
    } while(ch != 0);
    return 0;
}
