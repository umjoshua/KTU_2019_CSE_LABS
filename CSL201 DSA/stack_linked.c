/*
Name: Stack using linked list.
Author: Joshua Mathew
email: umjoshua@gmail.com
*/

#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *next;
};struct stack* top=NULL;

void display_stack();

int isEmpty(){
    if(top==NULL)
        return 1;
    else return 0;
}
void push(){
    printf("Enter the element: ");
    int d; scanf("%d",&d);
    struct stack* temp;
    temp=(struct stack *)malloc(sizeof(struct stack));
    if(top==NULL){
        temp->data=d;
        temp->next=NULL;
        top=temp;
    }
    else{
        temp->data=d;
        temp->next=top;
        top=temp;
    }
    display_stack();
}
void pop(){
    if(isEmpty()){
        printf("\nStack is empty.\n");
        return;
    }
    struct stack* temp;
    temp=(struct stack *)malloc(sizeof(struct stack));

    printf("\nPopped element: %d",top->data);
    temp=top;
    top=top->next;
    free(temp);
    display_stack();
}
void display_stack(){
    if(isEmpty()){
        printf("\nStack is empty.\n");
        return;
    }
    struct stack* ptr;
    ptr=top;
    printf("\nStack is: \n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        if(ptr->next!=NULL)
            printf("->");
        ptr=ptr->next;
    }
}
int main(){
    int choice,n;
    do{
    printf("\nEnter your choice:\n");
    printf("1. Push 2. Pop 3. Display 4. Exit : ");
    scanf("%d",&choice);
    switch (choice){
        case 1:push(); break;
        case 2: pop(); break;
        case 3: display_stack(); break;
        case 4: printf("Exiting..\n"); exit(0);
        default: printf("Invalid choice\n");
    }
    }while(choice!=4);
}
