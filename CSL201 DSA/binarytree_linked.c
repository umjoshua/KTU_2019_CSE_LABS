/*
Name: Binary tree traversals (Recursive and Interative) using linked list.
Author: Joshua Mathew
email: umjoshua@gmail.com
NB: Tree grows towards right.
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int top=-1;

struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
}; struct node *root=NULL, *stack[MAX];

struct node* search(struct node* ptro,int key){
    struct node *ptr,*temp;
    ptr=ptro;
    if(ptr->data==key)
        return ptr;
    if(ptr->lchild!=NULL){
        temp=search(ptr->lchild,key);
        if(temp!=NULL)
            return temp;
    }
    if(ptr->rchild!=NULL){
        temp=search(ptr->rchild,key);
        if(temp!=NULL)
            return temp;
    }
    else return NULL;
}

void insert(){
    struct node* ptr,*ptr2;
    printf("Enter data to insert and parent: ");
    int d,key,choice; scanf("%d %d",&d,&key);
    ptr=search(root,key);
    if(ptr==NULL){
        printf("\nParent not found.\n");
        return;
    }
    if(ptr->lchild==NULL || ptr->rchild==NULL){
        printf("1. Left 2. Right: ");
        scanf("%d",&choice);
        if(choice==1){
            if(ptr->lchild==NULL){
                ptr2=malloc(sizeof(struct node));
                ptr2->data=d;
                ptr->lchild=ptr2;
                ptr2->lchild=NULL; ptr2->rchild=NULL;
            }
            else{
                printf("\nLeft child is not free.\n");
                return;
            }
        }
        if(choice==2){
            if(ptr->rchild==NULL){
                ptr2=malloc(sizeof(struct node));
                ptr2->data=d;
                ptr->rchild=ptr2;
                ptr2->lchild=NULL; ptr2->lchild=NULL;
            }
            else{
                printf("\nRight child is not free.\n");
                return;
            }
        }
    }
    else{
        printf("\nChild node is not free.\n");
    }

}
struct node *delete(struct node *ptr1, int item){
        if(ptr1 == NULL)  
            return(NULL);
        ptr1->lchild = delete(ptr1->lchild, item);  
        ptr1->rchild = delete(ptr1->rchild, item);  
        if (ptr1->data == item && ptr1->lchild == NULL && ptr1->rchild == NULL)  
            return(NULL);  
        return(ptr1);
}
void display(struct node* ptro,int level){
    int j;
    struct node *ptr;
    ptr = ptro;
    if(ptr->rchild != NULL)
        display(ptr->rchild, level + 1);
    printf("\n");
    for(j = 0; j < level; j++)
        printf("\t");
    printf(" %d", ptr->data);
    if(ptr->lchild != NULL)
        display(ptr->lchild, level + 1);
}

void preorder_recursive(struct node* root) {
    struct node *ptr;
    ptr = root;
    if(ptr!= NULL){
        printf(" %d", ptr->data);
        preorder_recursive(ptr->lchild);
        preorder_recursive(ptr->rchild);
      }
}
void inorder_recursive(struct node* root){
    struct node *ptr;
    ptr = root;
    if(ptr != NULL){
        inorder_recursive(ptr->lchild);
        printf(" %d", ptr->data);
        inorder_recursive(ptr->rchild);
      }
}
void postorder_recursive(struct node* root){
    struct node *ptr;
    ptr = root;
    if(ptr!= NULL){
        postorder_recursive(ptr->lchild);
        postorder_recursive(ptr->rchild);
        printf(" %d", ptr->data);
     }
}
//Stack operations for Iterative Traversals
void push(struct node *item){
        if(top==(MAX-1)){
                printf("Stack Overflow\n");
                return;
        }
        top=top+1;
        stack[top]=item;
}
struct node *pop(){
        struct node *item;
        if(top==-1){
                printf("Stack Underflow....\n");
                exit(1);
        }
        item=stack[top];
        top=top-1;
        return item;
}
int isempty(){
        if(top==-1)
                return 1;
        else
                return 0;
}
struct node * peek(){
      if(isempty()){
            printf("Stack is Empty\n");
            exit(1);
      }
      return stack[top];
}
void preorder_iterative(struct node *root) {
    struct node *ptr = root;
    push(ptr);
    while(!isempty()){
        ptr = pop();
        printf(" %d",ptr->data);
        if(ptr->rchild!=NULL)
            push(ptr->rchild);
        if(ptr->lchild!=NULL)
            push(ptr->lchild);
    }
    printf("\n");
}
void inorder_iterative(struct node *root){
    struct node *ptr=root;
    while(1){
        if(ptr!=NULL){
            push(ptr);
            ptr=ptr->lchild;
        }
        else{
            if(isempty())
                break;
            ptr=pop();
            printf(" %d",ptr->data);
            ptr=ptr->rchild;
        }
    }
        printf("\n");
}
void postorder_iterative(struct node *root){
    struct node *ptr = root,*temp;
    while(ptr!=NULL || isempty()!=1){
        if(ptr!=NULL){
            push(ptr);
            ptr=ptr->lchild;
        }
        else{
            temp=peek()->rchild;
            if(temp==NULL){
                temp=pop();
                printf(" %d",temp->data);
                while(isempty()!=1 && temp==peek()->rchild){
                    temp=pop();
                    printf(" %d",temp->data);
                }
            }
            else{
                ptr=temp;
            }
        }
    }
    printf("\n");
}
void traversal_recursive(){
    printf("\nRecursive Traversal:\n");
    printf("1. Preoroder 2. Inorder 3. Postorder: ");
    int choice; scanf("%d",&choice);
    switch(choice){
        case 1: printf("\nPreorder Traversal: "); preorder_recursive(root);
                printf("\n"); break;
        case 2: printf("\nInorder Traversal: "); inorder_recursive(root);
                printf("\n"); break;
        case 3: printf("\nPostorder Traversal: "); postorder_recursive(root);
                printf("\n"); break;
    }
}
void traversal_iterative(){
    printf("\nIterative Traversal:\n");
    printf("1. Preoroder 2. Inorder 3. Postorder: ");
    int choice; scanf("%d",&choice);
    switch(choice){
        case 1: printf("\nPreorder Traversal: "); preorder_iterative(root);
                printf("\n"); break;
        case 2: printf("\nInorder Traversal: "); inorder_iterative(root);
                printf("\n"); break;
        case 3: printf("\nPostorder Traversal: "); postorder_iterative(root);
                printf("\n"); break;
    }
}
void main(){
    printf("\n***Binary Treee using linked list***\n");
    printf("\nEnter root node data: ");
    root=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&root->data);
    root->lchild=NULL;
    root->rchild=NULL;
    int choice;
    do{
    printf("\n\n1.Insert 2.Search 3.Display 4.Delete a node");
    printf("\n5.Recursive Traversals 6.Iterative Traversals 7.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
        switch(choice){
            case 1: insert(); display(root,1); break;
            case 2: {struct node* temp;
                    printf("Enter element to search: ");
                    int d; scanf("%d",&d);
                    temp=search(root,d);
                    if(temp==NULL)
                        printf("\nElement %d not found.\n",d);
                    else
                        printf("\nElement %d found.\n",d);}
                    display(root,1);
                    break;
            case 3: display(root,1); break;
            case 4: printf("\nEnter element to delete: ");
                    int item;scanf("%d",&item);
                    delete(root,item);
                    display(root,1);
                    break;
            case 5: traversal_recursive(); break;
            case 6: traversal_iterative(); break;
            case 7: printf("\nExiting..\n");
                    exit(0);
        }
    }while(choice!=7);
}
