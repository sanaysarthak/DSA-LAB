#include <stdio.h>

// Global Variables
#define MAX 5
int stack[MAX];
int top = -1;

void push() {
	if(top == MAX-1) 
		printf("Stack Overflow!\n");
	else {
		int ele;
		printf("Enter element: ");
		scanf("%d", &ele);
		top++;
		stack[top] = ele;
		printf("Element %d pushed!\n", ele);
	}
}

void pop() {
	if(top == -1) 
		printf("Stack Underflow!\n");
	else {
		printf("Popped element: %d\n", stack[top]);
		top--;
	}
}

void peek() {
	if(top == -1)
		printf("Stack Underflow!\n");
	else
		printf("Peek element: %d\n", stack[top]);
}

void display() {
	if(top == -1)
		printf("Stack Underflow!\n");
	else {
		printf("\nElements in stack are:-\n");
		for(int i=top; i>=0; i--) {
			printf("%d\n", stack[i]);
		}
	}
}

int main() {
	int ch;
	
	do {
		printf("\nEnter 1 to PUSH. \nEnter 2 to POP. \nEnter 3 to PEEK. \nEnter 4 to DISPLAY. \nEnter 0 to EXIT. \nEnter Choice:\n");
		scanf("%d", &ch);

		switch(ch) {

			case 1:
				push();
				break;

			case 2:
				pop();
				break;

			case 3:
				peek();
				break;

			case 4:
				display();
				break;

			case 0:
				printf("\nExited the program successfully.");
				break;

			default:
				printf("Enter correct choice.\n");
				break;

		}
	} while(ch != 0);
	
	return 0;
}
