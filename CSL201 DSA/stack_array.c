/*
Name: Stack using array.
Author: Joshua Mathew
email: umjoshua@gmail.com
*/

#include<stdio.h>
#include<stdlib.h>

int top=-1;
void display_stack(int stack[],int max);

int isEmpty(int max){
    if(top==-1)
        return 1;
    else
        return 0;
}
int isFull(int max){
    if(top==max-1)
        return 1;
    else
        return 0;
}

void push(int stack[],int max,int n){
    if(isFull(max)){
        printf("\nStack is full\n");
        return;
    }
    else stack[++top]=n;
    display_stack(stack,max);
}
void pop(int stack[],int max){
    if(isEmpty(max)){
        printf("\nStack is empty.\n");
        return;
    }
    printf("\nPopped element: %d \n",stack[top]);
    top--;
    display_stack(stack,max);
}
void display_stack(int stack[],int max){
    if(isEmpty(max)){
        printf("\nStack is empty.\n");
        return;
    }
    printf("\nStack is : \n");
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main(){
    int choice,n;
    printf("Enter the size of stack: ");
    int max; scanf("%d",&max);
    int stack[max];
    do{
        printf("\nEnter your choice:\n");
        printf("1. Push 2. Pop 3. Display 4. Exit : ");
        scanf("%d",&choice);
        switch (choice){
            case 1: printf("Enter the element: ");
                scanf("%d",&n);
                push(stack,max,n);
                break;
            case 2: pop(stack,max);
                break;
            case 3: display_stack(stack,max);
                break;
            case 4: printf("Exiting..\n");
                exit(0);
            default: printf("Invalid choice\n");
        }
    }while(choice!=4);
}
