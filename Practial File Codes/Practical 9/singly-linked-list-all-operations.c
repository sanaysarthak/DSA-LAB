/* Write a C program to implement Singly Linked List operations:-
Insert at Begin, Insert at End, Insert at Index, 
Delete at Begin, Delete at End, Delete at Index, Display. */

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head;

void insert_start() {
  struct node *ptr;
  ptr = (struct node*)malloc(sizeof(struct node*));
  if(ptr == NULL)
    printf("Node not created! No memory available!\n");
  else {
    int val;
    printf("Enter data: ");
    scanf("%d", &val);
    ptr -> data = val;
    ptr -> next = head;
    head = ptr;
    printf("Node inserted at start!\n");
  }
}

void insert_end() {
  struct node *ptr, *temp;
  ptr = (struct node*)malloc(sizeof(struct node*));
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
  ptr = (struct node*)malloc(sizeof(struct node*));
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

void delete_start() {
  if(head == NULL) 
    printf("Linked List is empty! No nodes exist!\n");
  else {
    struct node *temp = head;
    head = head -> next;
    free(temp);
    printf("Node deleted from the start!\n");
  }
}

void delete_end() {
  struct node *ptr, *ptr1;
  if(head == NULL) 
    printf("Linked List is empty! No nodes exist!\n");
  else if(head -> next == NULL) {
    head = NULL;
    free(head);
    printf("The only node of the Linked List is deleted!\n");
  }
  else {
    ptr = head;
    while(ptr -> next != NULL) {
      ptr1 = ptr;
      ptr = ptr -> next;
    }
    ptr1 -> next = NULL;
    free(ptr);
    printf("Node deleted from the end!\n");
  }
}

void delete_index() {
  struct node *ptr, *ptr1;
  if(head == NULL)
    printf("Linked List Empty! No nodes exist!\n");
  ptr = head;
  int index, flag = 0;
  printf("Enter index of the node to be deleted: ");
  scanf("%d", &index);
  for(int i=0; i<index; i++) {
    ptr1 = ptr;
    ptr = ptr -> next;
    if(ptr == NULL) {
      printf("Cannot Delete! The given index is greater than no. of existing nodes!\n");
      flag = 1;
      break;
    }
  }
  if(flag == 0) {
    ptr1 -> next = ptr -> next;
    free(ptr);
    printf("Node deleted at index %d.\n", index);
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

int main() {
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
    };
  } while(ch != 0);
  return 0;
}
