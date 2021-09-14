/*
Name: Queue using array
Author: Joshua Mathew
email: umjoshua@gmail.com
*/
#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1;

void display_queue();

int isEmpty(int max){
    if (front==-1 || front>rear)
        return 1;
    else return 0;
}
int isFull(int max){
    if (rear==max-1)
        return 1;
    else return 0;
}

void enqueue(int queue[],int max,int num){
    if(isFull(max)){
        printf("\nQueue is full\n");
        display_queue(queue,max);return;
    }
    if(front==-1)
        front=0;
    queue[++rear]=num;
    display_queue(queue,max);
}
void dequeue(int queue[],int max){
    if(isEmpty(max)){
        printf("\nQueue is empty\n");
        return;
    }
    front=front+1;
    display_queue(queue,max);
}
void display_queue(int queue[],int max){
    if(isEmpty(max)){
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nQueue is: \n");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int main(){
    int choice,n;
    printf("Enter size of queue: ");
    int max; scanf("%d",&max);
    int queue[max];
    do{
        printf("\nEnter your choice:\n");
        printf("1. Enqueue 2. Dequeue 3. Display 4. Exit : ");
        scanf("%d",&choice);
        switch (choice){
            case 1: printf("Enter the element: ");
                scanf("%d",&n);
                enqueue(queue,max,n);
                break;
            case 2: dequeue(queue,max);
                break;
            case 3: display_queue(queue,max);
                break;
            case 4: printf("Exiting..\n");
                exit(0);
            default: printf("Invalid choice\n");
    }
    }while(choice!=4);
}
