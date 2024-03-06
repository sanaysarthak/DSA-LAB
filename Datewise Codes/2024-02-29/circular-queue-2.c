// Program in C to perform insertion, deletion and display operations on a circular queue

#include <stdio.h>
#define MAX 5

int front = -1;
int rear = -1;
int circ_queue[MAX];

void enqueue() {

    if(rear == MAX-1 && front == 0 || front == rear+1) {
        printf("Queue Overflow!");
    }

    else {
        int insert_element;
        printf("Enter element to be inserted: ");
        scanf("%d", &insert_element);
        if(front == -1 && rear == -1) {
            front = rear = 0;
        }
        else if(rear == MAX-1 && front!=0) {
            rear = 0;
        }
        else {
            rear++;
        }
        circ_queue[rear] = insert_element;
    }

}

void dequeue() {
    
    if(rear == -1 || front-rear == 1) {
        printf("Queue Underflow!");
    }

    else {
        printf("Deleted element is %d", circ_queue[front]);
        if(front == rear) {
            front = rear - 1;
        }
        else if(front == MAX-1) {
            front = 0;
        }
        else {
            front++;
        }
    }

}

void display() {

    if(rear == -1) {
        printf("Queue Underflow!");
    }

    else {
        if(rear > front) {
            for(int i=front ; i<=rear ; i++) {
                printf("%d\n", circ_queue[i]);
            }
        }
        else {
            for(int i=front; i<=MAX-1; i++) {
                printf("%d\n", circ_queue[i]);
            }
            for(int i=0; i<=rear; i++) {
                printf("%d\n", circ_queue[i]);
            }
        }
    }

}

int main() {

    int ch;
    printf("Enter choice to perform operations:-");

    do 
    {
        printf("\nEnter 1 for ENQUEUE.\nEnter 2 for DEQUEUE.\nEnter 3 for DISPLAY.\nEnter 0 to EXIT.\n");
        scanf("%d", &ch);
        
        switch(ch) 
        {
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
                printf("Exited the program successfully.\n");
                break;

            default:
                printf("Enter correct choice.\n");
                break;    
        }
    } while(ch!=0);

    return 0;
}
