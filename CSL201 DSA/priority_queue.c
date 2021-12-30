#include <stdio.h>
#include<stdlib.h>

#define MAX 100

int rear = -1, front = -1;

struct pqueue {
    int data;
    int priority;
}
priorityque[MAX];

void enQueue(int item, int priority) {
    int i;
    if (front == 0 && rear == MAX - 1) {
        printf("\nQueue overflow!\n");
        return;
    }
    if (front == -1)
        front = 0;
    i=rear;
    rear++;

    while((priorityque[i].priority<=priority) && (i>=0)){
        priorityque[i+1].data = priorityque[i].data;
        priorityque[i+1].priority = priorityque[i].priority;
        i--;
    }
    priorityque[i+1].data = item;
    priorityque[i+1].priority = priority;
}

void deQueue() {
    if (front == -1 || front > rear) {
        printf("\nQueue underflow!\n");
        return;
    }
    printf("\nDeleted element : %d | priority: %d\n", priorityque[front].priority, priorityque[front].data);
    front++;
}

void display() {
    int i;
    printf("\nThe queue is:\n");
    printf("\nPriority Data\n");
    for(i=front;i<=rear;i++){
        printf("  %d\t  %d\n",priorityque[i].priority,priorityque[i].data);
    }
    printf("\n");
}


void main() {
    int choice;
    printf("\nPriority Queue");
    while(choice!=4){
        printf("\n1. Enqueue 2. Dequeue 3. Display 4.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:int item, pri;
                printf("Enter data: "); scanf("%d",&item);
                printf("Enter priority: "); scanf("%d",&pri);
                enQueue(item,pri);
                display();
                break;
            case 2:
                deQueue();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting\n");
                exit(0);
        }
    }
}
