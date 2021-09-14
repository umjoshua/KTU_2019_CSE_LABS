/*Name: Stack using queue - Using linked list
Author: Joshua Mathew
email: umjoshua@gmail.com
*/
#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue* next;
};
struct queue *front1=NULL,*rear1=NULL,*front2=NULL,*rear2=NULL;

void display_queue();
void enqueue1(int d);
void enqueue2(int d);
int dequeue1();
int dequeue2();


void push(int data){
    while(front1!=NULL)
        enqueue2(dequeue1());
    enqueue1(data);
    while(front2!=NULL)
        enqueue1(dequeue2());
}
void pop(){
    if(front1!=NULL)
        dequeue1();
}

void enqueue1(int d){
    struct queue* temp;
    temp=(struct queue*)malloc(sizeof(struct queue));
    temp->data=d;
    if(front1==NULL)
        front1=temp;
    else
        rear1->next=temp;
    rear1=temp;
}
int dequeue1(){
    if(front1!=NULL){
        struct queue* temp;
        temp=front1;
        front1=front1->next;
        return temp->data; 
        free(temp);
    }
}
void enqueue2(int d){
    struct queue* temp;
    temp=(struct queue*)malloc(sizeof(struct queue));
    temp->data=d;
    if(front2==NULL)
        front2=temp;
    else
        rear2->next=temp;
    rear2=temp;
}
int dequeue2(){
    if(front2!=NULL){
        struct queue* temp;
        temp=front2;
        front2=front2->next;
        return temp->data; 
        free(temp);
    }
}
void display_stack(){
    struct queue* ptr;
    ptr=front1;
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
    printf("1. Push 2. Pop 3. Display 4. Exit : ");
    scanf("%d",&choice);
    switch (choice){
        case 1:printf("Enter data: ");
                scanf("%d",&n);
                push(n); display_stack(); break;
        case 2: pop(); display_stack(); break;
        case 3: display_stack(); break;
        case 4: printf("Exiting..\n"); exit(0);
        default: printf("Invalid choice\n");
    }
    }while(choice!=4);
}
