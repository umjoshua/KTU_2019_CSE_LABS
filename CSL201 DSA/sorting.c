/*
Name: Insertion sort, quick sort, selection sort,merge sort
Author: Joshua Mathew
email: umjoshua@gmail.com
*/


#include<stdio.h>
#include<stdlib.h>

int Partition(int A[],int left,int right);
void Quicksort(int A[],int first,int last);
int SelectMin(int A[], int L, int R);
void SelectionSort(int A[], int n);
void InsertionSort(int A[], int n);
void MergeSort(int A[], int l,int r);
void Merge(int A[], int l, int mid, int r);
void display(int A[], int n);
void Swap(int *x, int *y);
void CreateHeap(int A[], int n, int b[]);
void RemoveMax(int b[], int i);
void RebuildHeap(int b[], int i);
void HeapSort(int A[], int n, int b[]);

void main(){
    int n,i,choice,choice1;
    do{
        printf("\nEnter the size of the array: ");
        scanf("%d",&n);
        int A[n],b[n];
        printf("Enter the elements of the array: ");
        for(i=1;i<=n;i++)
            scanf("%d",&A[i]);
        printf("\n1.Insertion Sort 2.Selection Sort 3.Quick Sort 4.Merge Sort 5.Heap Sort 6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: InsertionSort(A,n); break;
            case 2: SelectionSort(A,n);
                    display(A,n); break;
            case 3: Quicksort(A,1,n);
                    display(A,n); break;
            case 4: MergeSort(A,1,n);
                    display(A,n); break;
            case 5: HeapSort(A, n, b);
                    display(b,n); break;
            case 6: printf("Exiting...");
                    exit(0);
            default: printf("Invalid choice!");
        }
        printf("\n1.Continue 2.Exit: ");
        scanf("%d", &choice1);
    } while(choice1==1);
}
// Insertion sort
void InsertionSort(int A[], int n){
    int B[n],j,i,k,flag,p;
    B[1]=A[1];
    for(j=2;j<=n;j++){
        k=A[j];
        flag=1;
        i=j-1;
        while(flag==1){
            if(k<B[i]){
                i=i-1;
            }
            else
                flag=0;
        }
        p=j;
        while(p>i+1){
            B[p]=B[p-1];
            p--;
        }
        B[i+1]=k;
    }
    printf("\nThe sorted array is: ");
    for(i=1;i<=n;i++)
        printf("%d ",B[i]);
    printf("\n");
}
// Selection sort
int SelectMin(int A[], int L, int R){
    int i,min=A[L], loc=L;
    for(i=L+1; i<=R; i++)
        if(min>A[i]){
            min=A[i];
            loc=i;
        }
    return loc;
}
void SelectionSort(int A[], int n){
    int i,j;
    for(i=1; i<n-1; i++){
        j=SelectMin(A,i,n);
        if(i!=j)
            Swap(&A[i],&A[j]);
    }
}
//Quick sort
int Partition(int A[],int left,int right){
    int loc=left;
    while(left<right){
        while(A[loc]<=A[right] && loc<right)
            right--;
        if(A[loc]>A[right]){
            Swap(&A[loc],&A[right]);
            loc=right;
            left++;
        }
        while(A[loc]>=A[left] && loc>left)
            left++;
        if(A[loc]<A[left]){
            Swap(&A[loc],&A[left]);
            loc=left;
            right--;
        }
    }
    return loc;
}
void Quicksort(int A[],int first,int last){
    int p;
    if(first<last){
        p=Partition(A,first,last);
        Quicksort(A,first,p-1);
        Quicksort(A,p+1,last);
    }
    return;
}
//Merge sort
void MergeSort(int A[], int l,int r){
    if (r<=l)
        return;
    else{
        int mid=(l+r)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,r);
        Merge(A,l,mid,r);
    }
}
void Merge(int A[], int l, int mid, int r){
    int C[r], m;
    int i=l, j=mid+1,k=l;
    while(i<=mid && j<=r){
        if (A[i]<=A[j]){
           C[k]=A[i];
           i++;k++;
        }
        else{
           C[k]=A[j];
           j++;k++;
        }
    }
    if(i>mid && j<=r)
        for(m=j;m<=r;m++){
            C[k]=A[m];
            k++;
        }
    else if(i<=mid && j>r)
        for(m=i;m<=mid;m++){
            C[k]=A[m];
            k++;
        }
    for(m=l;m<=k-1;m++)
        A[m]=C[m];
}
void Swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
//Heap sort
void CreateHeap(int A[], int n, int b[]) {
    int i = 1,j, temp;
    while(i <= n) {
        b[i] = A[i];
        j = i;
        while(j > 1) {
            if(b[j] > b[j / 2]) {
                temp = b[j];
                b[j] = b[j / 2];
                b [j / 2] = temp;
                j = j / 2;
            }
            else
                j = 1;
        }
        i = i + 1;
    }
}

void RemoveMax(int b[], int i) {
    int temp = b[i];
    b[i] = b[1];
    b[1] = temp;
}

void RebuildHeap(int b[], int i) {
    if(i == 1)
        return;
    int j = 1, flag = 1;
    while(flag == 1) {
        int lchild = 2 * j;
        int rchild = 2 * j + 1;
        if(rchild <= i) {
            if(b[j] <= b[lchild]) {
                if(b[lchild] <= b[rchild]) {
                    int temp = b[j];
                    b[j] = b[rchild];
                    b[rchild] = temp;
                    j = rchild;
                }
                else {
                    int temp = b[j];
                    b[j] = b[lchild];
                    b[lchild] = temp;
                    j = lchild;
                }
            }
            else if (b[j] <= b[rchild]) {
                int temp = b[j];
                b[j] = b[rchild];
                b[rchild] = temp;
                j = rchild;
            }
            else
                flag = 0;
        }
        else if(lchild <= i) {
            if (b[j] <= b[lchild]) {
                int temp = b[j];
                b[j] = b[lchild];
                b[lchild] = temp;
                j = lchild;
            }
            else
                flag = 0;
        }
        else
            flag = 0;
    }
}
void HeapSort(int A[], int n, int b[]) {
    CreateHeap(A, n, b);
    for(int i = n; i > 1; i--) {
        RemoveMax(b, i);
        RebuildHeap(b, i - 1);
    }
}
void display(int A[], int n){
    int i;
    printf("\nThe sorted array is: ");
    for(i=1;i<=n;i++)
        printf("%d ",A[i]);
    printf("\n");
}
