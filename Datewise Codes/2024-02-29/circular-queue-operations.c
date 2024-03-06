/* Add similar operations like a normal queue.
i.e have functions which perform the insertion operation, deletion operation and display the elements of the queue.
*/

#include <stdio.h>

#define MAX 6
int queue[MAX];
int front = -1;
int rear = -1;

// function to insert an element into the queue
void enqueue(int ele)
{
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = ele;
    }
    else if((rear+1)%MAX == front)
    {
        printf("Queue Overflow!");
    }
    else
    {
        rear = (rear+1)%MAX;
        queue[rear] = int size, ele;
    }
}

// function to remove an element from the queue
int dequeue()
{
    if((front == -1) && (rear == -1))
    {
        printf("\nQueue Underflow!");
    }
    else if(front == rear)
    {
        printf("\nThe dequeued element is %d", queue[front]);
        front = -1;
        rear = -1;
    } 
    else
    {
        printf("\nThe dequeued element is %d", queue[front]);
        front = (front+1)%MAX;
    }
}

// function to display the elements of the queue
void display() 
{
    int i = front;
    if(front == 1 && rear == -1)
    {
        printf("\nQueue Underflow!");
    }
    else
    {
        printf("\nElements in the Queue are :-");
        while(i <= rear)
        {
            printf("%d", queue[i]);
            i = (i+1)%MAX;
        }
    }
}

int main() 
{
    int x, ch;
    printf("Enter choice to perform operations:-");

    do 
    {
        printf("\nEnter 1 for ENQUEUE.\nEnter 2 for DEQUEUE.\nEnter 3 for DISPLAY.\nEnter 0 to EXIT.\n");
        scanf("%d", &ch);
        
        switch(ch) 
        {
            case 1:
                printf("Element element to be inserted: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;
            
            case 3:
                display();
                breakl
            
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