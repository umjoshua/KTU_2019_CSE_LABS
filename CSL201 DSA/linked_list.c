/*
Name: Linked List Operations.
Author: Joshua Mathew
email: umjoshua@gmail.com
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};struct node *start=NULL;

void insert_first();
void insert_end();
void insert_position();
void display_list();

void create_list(){
    printf("Enter the number of nodes: ");
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++){
        if(start==NULL)
            insert_first();
        else
            insert_end();
        display_list();
    }
}

void insert_first(){
    struct node *ptr;
    printf("Enter data: ");
    int d; scanf("%d",&d);
    struct node* temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(start==NULL){
        start=temp;
        start->data=d;
        start->next=NULL;
    }
    else{
        temp->data=d;
        temp->next=start;
        start=temp;
    }
    display_list();
}

void insert_end(){
    if(start==NULL)
        insert_first();
    printf("Enter data: ");
    int d; scanf("%d",&d);
    struct node* temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    ptr=start;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=temp;
    temp->data=d;
    temp->next=NULL;
    display_list();
}
void insert_position(){
    printf("Enter position: ");
    int d,p; scanf("%d",&p);

    if(p==1)
        insert_first();
    
    printf("Enter data: ");
    scanf("%d",&d);
    
    struct node* temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    ptr=start;

    for(int i=1;i<p-1;i++)
        ptr=ptr->next;
    
    temp->next=ptr->next;
    ptr->next=temp;
    temp->data=d;

    display_list();
}
void delete_first(){
    if(start==NULL){
        printf("List is empty!\n");
        return;
    }
    struct node* temp=start;

    start=start->next;
    free(temp);
    display_list();
}
void delete_end(){
    struct node *ptr,*temp;
    if(start==NULL){
        printf("\nList is empty!\n");
        return;
    }
    ptr=start;
    while(ptr->next!=NULL){
        temp=ptr; 
        ptr=ptr->next;
    }
    if(ptr==start){
        delete_first(); return;
    }
    else{
        temp->next=NULL;
        free(ptr);
        display_list();
    }
}
void delete_pos(){
    printf("Enter position: ");
    int d,p; scanf("%d",&p);

    if(p==1)
        delete_first();
    
    struct node* temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    ptr=start;

    for(int i=1;i<p-1;i++)
        ptr=ptr->next;
    
    temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
    display_list();

}
void display_list(){
   if(start==NULL){
        printf("\nThe linked list is empty");
        return;
    }
    struct node *ptr;
    printf("\nThe linked list : "); 
    ptr=start;
    while(ptr!=NULL){  
        printf("%d",ptr->data);
        if(ptr->next!=NULL)
            printf("->");   
        ptr=ptr->next;
    }
    printf("\n");
}
int main(){
    int choice;
    do{
    printf("\n1. Create List 2. Insert at beginning 3. Insert at end\n");
    printf("4. Insert at position 5. Delete from beginning 6. Delete from end\n");
    printf("7. Delete from position 8. Display 9. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch (choice){
        case 1: create_list(); break;
        case 2: insert_first(); break;
        case 3: insert_end(); break;
        case 4: insert_position(); break;
        case 5: delete_first(); break;
        case 6: delete_end(); break;
        case 7: delete_pos(); break;
        case 8: display_list();break;
        case 9: printf("Exiting..\n");
            exit(0);
        default: printf("Invalid choice\n");
    }
    }while(choice!=9);
}