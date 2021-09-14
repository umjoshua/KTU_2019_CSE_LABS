/*
Name: Stack using queue : array
Author: Joshua Mathew
email: umjoshua@gmail.com
*/
#include<stdio.h>
#include<stdlib.h>

#define max 100
int front1=-1,rear1=-1;
int front2=-1,rear2=-1;
int queue1[max],queue2[max];

void enqueue1(int data){
    if(front1==-1)
        front1=0;
    queue1[++rear1]=data;
}
int dequeue1(){
    return queue1[front1++];
}
int isEmpty1(){
    if(front1==-1 || front1>rear1)
        return 1;
    else return 0;
}
void enqueue2(int data){
    if(front2==-1)
        front2=0;
    queue2[++rear2]=data;
}
int dequeue2(){
    return queue2[front2++];
}
int isEmpty2(){
    if(front2==-1 || front2>rear2)
        return 1;
    else return 0;
}

void push(int data){
    if(isEmpty1()==1)
        enqueue1(data);
    else{
        while(isEmpty1()!=1)
            enqueue2(dequeue1());
        enqueue1(data);
        while(isEmpty2()!=1)
            enqueue1(dequeue2());
    }
}
void pop(){
    dequeue1();
}

void display_stack(){
    printf("\nStack is: \n");
    for(int i=front1;i<=rear1;i++){
        printf("%d ",queue1[i]);
    }
    printf("\n");
}

int main(){
    int choice,data;
    do{
        printf("\nEnter your choice:\n");
        printf("1. Push 2. Pop 3. Display 4. Exit : ");
        scanf("%d",&choice);
        switch (choice){
            case 1: printf("Enter the element: ");
                scanf("%d",&data);
                push(data);
                display_stack();
                break;
            case 2: pop();
                    display_stack();
                break;
            case 3: display_stack();
                break;
            case 4: printf("Exiting..\n");
        }
    }while(choice!=4);
}
