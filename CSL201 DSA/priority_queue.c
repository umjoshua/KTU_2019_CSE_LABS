#include <stdio.h>

#include<stdlib.h>

#define MAX 100

int rear = -1, front = -1;

struct pqueue {
    int data;
    int priority;
}
pq[MAX], flag;

void sort();
void display();

void enQueue() {
    int n, p;
    if (front == 0 && rear == MAX - 1) {
        printf("\nQueue overflow!\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    printf("Enter the number and priority: ");
    scanf("%d %d", & n, & p);
    pq[rear].data = n;
    pq[rear].priority = p;
    sort();
}
void sort() {
    int i, j;
    for (i = front; i <= rear - 1; i++)
        for (j = front; j <= rear - 1 - (i - front); j++)
            if (pq[j].priority > pq[j + 1].priority) {
                flag = pq[j];
                pq[j] = pq[j + 1];
                pq[j + 1] = flag;
            }
}
void deQueue() {
    if (front == -1 || front > rear) {
        printf("\nQueue underflow!\n");
        return;
    }
    printf("\nDeleted element : %d | priority: %d\n", pq[front].priority, pq[front].data);
    front++;
    sort();
    display();
}
void display() {
    int i;
    printf("\nThe queue is:\n");
    printf("\nPriority Data\n");
    for(i=front;i<=rear;i++){
        printf("  %d\t  %d\n",pq[i].priority,pq[i].data);
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
            case 1:
                enQueue();
                display();
                break;
            case 2:
                deQueue();
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
