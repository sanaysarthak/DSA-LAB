// Program in C to implement Circular Queue Operations (Enqueue, Dequeue, and Display)

#include <stdio.h>

// Global Variables
#define MAX 5
int circ_queue[MAX];
int front = -1;
int rear = -1;

void enqueue() {
	if((rear == MAX-1 && front == 0) || front == rear + 1)
		printf("Circular Queue Overflow!\n");
	else {
		int ele;
		printf("Enter element: ");
		scanf("%d", &ele);
		if(front == -1 && rear == -1)
			front = rear = 0;
		else if(rear == MAX-1 && front != 0)
			rear = 0;
		else 
			rear++;
		circ_queue[rear] = ele;
	}
}

void dequeue() {
	if(rear == -1 || front - rear == 1)
		printf("Queue Underflow!\n");
	else {
		printf("Dequeued element is: %d\n", circ_queue[front]);
		if(front == rear) // condition when all the elements are deleted.
			front = rear = -1;
		else if(front == MAX-1)
			front = 0;
		else
			front++;
	}
}

void display() {
	if(rear == -1)
		printf("Queue Underflow!\n");
	else {
		printf("Elements of the circular queue are:-\n");
		if(rear > front) {
			for(int i=front; i<=rear; i++) {
				printf("%d\t", circ_queue[i]);
			}
		}
		else {
			for(int i=front; i<=MAX-1; i++) {
				printf("%d\t", circ_queue[i]);
			}
			for(int i=0; i<=rear; i++) {
				printf("%d\t", circ_queue[i]);
			}
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
