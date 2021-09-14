#include<stdio.h>
#include<stdlib.h>
struct poly{
    int coeff;
    int expo;
} p1[10],p2[10],sum[10];

int acceptpoly(struct poly p[10]){
    printf("Enter size of polynomial: ");
    int size; scanf("%d",&size);
    for(int i=0;i<size;i++){
        printf("\nEnter the coeff of term %d: ",i+1);
        scanf("%d",&p[i].coeff);
        printf("\nEnter the expo of term %d: ",i+1);
        scanf("%d",&p[i].expo);
    }
    return size;
}
void display_poly(struct poly p[10],int n){
    for(int i=0;i<n;i++){
        if(p[i].coeff==0)
            continue;
        if(p[i].expo==0)
            printf("%d",p[i].coeff);
        else
            printf("%dx^%d",p[i].coeff,p[i].expo);
        if(i==n-1)
            break;
        else
            printf(" + ");
    }
    printf("\n");
}
void sort_poly(struct poly p[10], int n) {
    int i, j;
    struct poly temp;

    for (j = 1; j < n; j++) {
        for (i = 0; i < n-j; i++) {
            if (p[i+1].expo > p[i].expo) {
                temp = p[i+1];
                p[i+1] = p[i];
                p[i] = temp;
            }
        }
    }
}
int add_poly(int n1,int n2){
    int i=0,j=0,k=0;
    while(i!=n1 && j!=n2){
        if(p1[i].expo>p2[j].expo){
            sum[k].coeff = p1[i].coeff;
            sum[k].expo = p1[i].expo;
            i++;k++;
        }
        if(p1[i].expo<p2[j].expo){
            sum[k].coeff = p2[j].coeff;
            sum[k].expo = p2[j].expo;
            j++;k++;
        }
        else{
            sum[k].expo = p1[i].expo;
            sum[k].coeff = p1[i].coeff + p2[j].coeff;
            i++;j++;k++;
        }
    }
    if(i==n1 && j!=n2){
        while(j!=n2){
            sum[k].coeff = p2[j].coeff;
            sum[k].expo = p2[j].expo;
            j++;k++;
        }
    }
    if(i!=n1 && j==n2){
        while(i!=n1){
            sum[k].coeff = p1[i].coeff;
            sum[k].expo = p1[i].expo;
            i++;k++;
        }
    }
    return k;
}
void main(){
    printf("\n***Polynomial addition using array***\n");
    int n1; n1=acceptpoly(p1);
    sort_poly(p1,n1);
    printf("\nPolynomial 1: \n");
    display_poly(p1,n1);
    int n2; n2=acceptpoly(p2);
    printf("\nPolynomial 2: \n");
    sort_poly(p2,n2);
    display_poly(p2,n2);
    printf("\nThe sum of polynomial is : \n");
    int n3; n3=add_poly(n1,n2);
    sort_poly(sum,n3);
    display_poly(sum,n3);
}