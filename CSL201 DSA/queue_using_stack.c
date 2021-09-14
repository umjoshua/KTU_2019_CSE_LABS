/*
Name: Queue using stack : array
Author: Joshua Mathew
email: umjoshua@gmail.com
*/

#include<stdio.h>
#define max 100
int top1=-1;
int top2=-1;
int stack1[max];
int stack2[max];

void push1(int data){
    stack1[++top1]=data;
}
void push2(int data){
    stack2[++top2]=data;
}
int pop1(){
    if(top1==-1)
        return -1;
    else
        return stack1[top1--];
}
int pop2(){
    if(top2==-1)
        return -1;
    else
        return stack2[top2--];
}

void enqueue(int data){
    while(top1!=-1)
        push2(pop1());
    push1(data);
    while(top2!=-1)
        push1(pop2());
}
void dequeue(){
    pop1();
}
void print_queue(){
    for(int i=0;i<=top1;i++)
        printf("%d ",stack1[i]);
    printf("\n");
}
void main(){
    int choice;
    print_queue();
    do{
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter data: ");
                    int data; scanf("%d",&data);
                    enqueue(data); print_queue();
                    break;
            case 2: dequeue(); print_queue(); break;
            case 3: print_queue(); break;
            case 4: break;
        }
    }while(choice!=4);
}
