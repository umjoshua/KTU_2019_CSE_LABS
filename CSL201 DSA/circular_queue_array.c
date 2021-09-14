/*
Name: Circular Queue using array
Author: Joshua Mathew
email: umjoshua@gmail.com
*/

#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1;

void display_queue(int queue[],int max);

int isEmpty(int max){
    if (front==-1)
        return 1;
    else return 0;
}
int isFull(int max){
    if((front==0 &&rear==max-1) || (front==rear+1))
        return 1;
    else return 0;
}

void enqueue(int queue[],int max,int num){
    if(isFull(max)){
        printf("\nQueue is full\n");
        return;
    }
    if(front==-1){
        front=0;
        rear=0;
    }
    else{
        if(rear==max-1)
            rear=0;
        else
            rear=rear+1;
    }
    queue[rear]=num ;
    display_queue(queue,max);
}
void dequeue(int queue[],int max){
    if(front==-1){
        printf("\nQueue is empty\n");
        return;
    }
    if(front==rear){
        front=-1;rear=-1;
    }
    else{
        if(front==max-1)
            front=0;
        else
            front=front+1;
    }
    display_queue(queue,max);
}
void display_queue(int queue[],int max){
    if(isEmpty(max)){
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nQueue is: \n");
    if(front<=rear){
        for(int i=front;i<=rear;i++)
            printf("%d ",queue[i]);
    }
    if(front>rear){
        for(int i=front;i<=max-1;i++)
            printf("%d ",queue[i]);
        for(int i=0;i<=rear;i++)
            printf("%d ",queue[i]);
    }
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
