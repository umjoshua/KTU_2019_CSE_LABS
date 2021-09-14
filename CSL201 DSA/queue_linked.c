/*
Name: Queue using linked list.
Author: Joshua Mathew
email: umjoshua@gmail.com
*/

#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue* next;
};struct queue* front=NULL,*rear=NULL;

void display_queue();

int isEmpty(){
    if(front==NULL)
        return 1;
    else return 0;
}
void enqueue(){
    struct queue* temp;
    temp=(struct queue*)malloc(sizeof(struct queue));
    printf("Enter data: ");
    int d; scanf("%d",&d);
    temp->data=d;
    if(front==NULL)
        front=temp;
    else
        rear->next=temp;
    rear=temp;
    display_queue();
}
void dequeue(){
    if(isEmpty()){
        printf("\nQueue is empty.\n");
        return;
    }
    struct queue* temp;
    temp=front;
    front=front->next;
    free(temp);
    display_queue();
}
void display_queue(){
    if(isEmpty()){
        printf("\nQueue is empty.\n");
        return;
    }
    struct queue* ptr;
    ptr=front;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        if(ptr->next!=NULL)
            printf("->");
        ptr=ptr->next;
    }
    printf("\n");
}
int main(){
    int choice,n;
    do{
    printf("\nEnter your choice:\n");
    printf("1. Enqueue 2. Dequeue 3. Display 4. Exit : ");
    scanf("%d",&choice);
    switch (choice){
        case 1: enqueue(); break;
        case 2: dequeue(); break;
        case 3: display_queue(); break;
        case 4: printf("Exiting..\n"); exit(0);
        default: printf("Invalid choice\n");
    }
    }while(choice!=4);
}
