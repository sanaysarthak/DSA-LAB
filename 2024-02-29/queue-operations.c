#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
    if(rear >= MAX-1)
        printf("Queue Overflow!");
    else {
        int insert_element;
        printf("Enter element to insert it: ");
        scanf("%d", &insert_element);
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = insert_element;
    }
}

void dequeue()
{
    if(rear == -1 || front > rear)
        printf("Queue Underflow!");
    else {
        printf("Deleted element is = %d", queue[front]);
        if(front == rear) // condition when all elements are deleted
            front = rear = -1;
        else
            front++;
    }
}

void display()
{
    if(rear == -1)
        printf("Queue Underflow!");
    else
    {
        printf("The queue contains the following elements: ");
        for(int i=front; i<=rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch;
    printf("Enter choice to perform operations:-");
    do {
        printf("\nEnter 1 for ENQUEUE.\nEnter 2 for DEQUEUE.\nEnter 3 for DISPLAY.\nEnter 0 to EXIT.\n");
        scanf("%d", &ch);

        switch (ch)
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
