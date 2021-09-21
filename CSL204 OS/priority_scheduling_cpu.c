#include<stdio.h>
int n,i,tot=0,m,j,k,d,greatprio,changemade=0,top=-1,past=0,tt,wt;
float ttt=0,twt=0;
int stack[20];
struct process{
    int at;
    int bt;
    int btstat;
    int pri;
    int stat;
    int comple;
}p[20];
void push(int m){
    top++;
    stack[top]=m;
}
int pop(){
    int y=stack[top];
    top--;
    return y;
}
void nonpre(){
    printf("\tP%d",greatprio);
    p[greatprio].stat=0;
    j=j+p[greatprio].bt;
    p[greatprio].comple=j;
}

void main()
{
    printf("\nEnter the total number of process: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter AT, BT, Priority for PROCESS P%d: ",i);
        scanf("%d",&p[i].at);
        scanf("%d",&p[i].bt);
        p[i].btstat=p[i].bt;
        scanf("%d",&p[i].pri);
        p[i].stat=1;
        tot=tot+p[i].bt;
    }

    for(j=0;j<=tot;j++){
        for(k=1;k<=n;k++){
            if(p[k].at<=j&&p[k].stat==1){
                push(k);
                changemade=1;
            }
        }
        if(changemade==1){
            greatprio=pop();
            int y=pop();
            while(top!=-2){
                if(p[y].pri<p[greatprio].pri){
                    greatprio=y;
                }
                else if(p[y].pri==p[greatprio].pri){
                    if(p[y].at<p[greatprio].at){
                        greatprio=y;
                    }
                }
                y=pop();
            }
            if(top==-2)
                top=-1;
            
            nonpre();
            j--;
            changemade=0;
        }
    }
    printf("\nTABLE");
    printf("\nPROCESS\tAT\tBT\tCT\tTT\tWT");
    for(i=1;i<=n;i++){
        tt=p[i].comple-p[i].at;
        wt=tt-p[i].bt;
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",i,p[i].at,p[i].bt,p[i].comple,tt,wt);
        ttt=ttt+tt;
        twt=twt+wt;
    }
    printf("\nTHE AVERAGE TURNAROUND TIME IS %f",ttt/n);
    printf("\nTHE AVERAGE WAITING TIME IS %f\n",twt/n);
}