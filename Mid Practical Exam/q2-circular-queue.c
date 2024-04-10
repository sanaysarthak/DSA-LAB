// Program in C to implement Circular Queue Operations
// fix enqueue, when element is already is 
#include <stdio.h>

// Global Variables
#define MAX 5
int circ_queue[MAX];
int front = -1;
int rear = -1;

void enqueue() {
	if(rear >= MAX-1)
		printf("Circular Queue Overflow!\n");
	else {
		int ele;
		printf("Enter element: ");
		scanf("%d", &ele);
		if(front == -1)
			front = 0;
		rear++;
		circ_queue[rear] = ele;
	}
}

void dequeue() {
	if(rear == -1 || front > rear)
		printf("Queue Underflow!\n");
	else {
		printf("Dequeued element is: %d", circ_queue[front]);
		if(front == rear) // condition when all the elements are deleted.
			front = rear = -1;
		else
			front++;
	}
}

void display() {
	if(rear == -1)
		printf("Queue Underflow!\n");
	else {
		printf("The queue contains the following elements:- \n");
		for(int i=front; i>=0; i--) {
			printf("%d\t", circ_queue[i]);
		}
		printf("\n");
	}
}

int main() {

	int ch;
	do {
		printf("\nEnter 1 for ENQUEUE operation. \nEnter 2 for DEQUEUE operation. \nEnter 3 for DISPLAY operation. \nEnter 0 to EXIT. \nEnter Choice:\n");
		scanf("%d", &ch);

		switch(ch) {
			case 1:
				enqueue();
				break;

			case 2:
				dequeue();
				break;

			case 3:
				display();
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
