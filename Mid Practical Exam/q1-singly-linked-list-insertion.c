// Program to perform singly linked list insertions (insertion at start, end, and at given index value)
// Wrote the display_nodes() function on my own to test the code on execution

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *head;

void insert_start() {
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node *));
	if(ptr == NULL)
		printf("Node not created! No memory available!\n");
	else {
		int val;
		printf("Enter data: ");
		scanf("%d", &val);
		ptr -> data = val;
		ptr -> next = head;
		head = ptr;
	}
}

void insert_end() {
	struct node *ptr, *temp;
	ptr = (struct node *)malloc(sizeof(struct node *));
	if(ptr == NULL)
		printf("Node not created! No memory available!\n");
	else {
		int val;
		printf("Enter data: ");
		scanf("%d", &val);
		ptr -> data = val;
		if(head == NULL) {
			head = ptr;
			ptr -> next = NULL;
			printf("Node inserted at first, as there were no existing nodes!\n");
		}
		else {
			temp = head;
			while(temp -> next != NULL) {
				temp = temp -> next;
			}
			temp -> next = ptr;
			ptr -> next = NULL;
			printf("Node inserted at end!\n");
		}
	}
}

void insert_index() {
	struct node *ptr, *temp;
	ptr = (struct node *)malloc(sizeof(struct node *));
	if(ptr == NULL)
		printf("Node not created! No memory available!\n");
	else {
		int index, val, i=0;
		printf("Enter index at which you want to insert node: ");
		scanf("%d", &index);
		printf("Enter data: ");
		scanf("%d", &val);
		ptr -> data = val;
		if(head == NULL) {
			head = ptr;
			ptr -> next = NULL;
			printf("Node inserted at first, as there were no existing nodes!\n");
		}
		else {
			temp = head;
			while((i != index-1) && (temp -> next != NULL)) {
				temp = temp -> next;
				i++;
			}
			if(temp -> next == NULL) 
				printf("Node inserted at last, as index given was greater than existing no. of nodes!\n");
			else
				printf("Node inserted at index %d.\n", index);
			ptr -> next = temp -> next;
			temp -> next = ptr;
		}
	}
}

void display_nodes() {
	struct node *ptr;
	ptr = head;
	if(head == NULL) 
		printf("Linked List Empty! No nodes created!\n");
	else {
		printf("The Nodes are:-\n");
		while(ptr != NULL) {
			printf("%d\t", ptr -> data);
			ptr = ptr -> next;
		}
		printf("\n");
	}
	
}

int main() {
	int ch;

	do {
		printf("\nEnter 1 for Insertion at Start.\nEnter 2 for Insertion at End.\nEnter 3 for Insertion at given index. \nEnter 4 to display. \nEnter 0 to exit.\n");
    	printf("Enter choice: ");
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
    			display_nodes();
    			break;

    		case 0:
    			printf("\nExited the program succesfully!");
    			break;

    		default:
    			printf("Enter correct choice.\n");
    			break;
    	}
	} while(ch != 0);
    
    return 0;
}
