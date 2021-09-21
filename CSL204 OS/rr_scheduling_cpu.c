#include<stdio.h>
int n,i,tot=0,m,j,k,d,greatprio,changemade=0,front=-1,rear=-1,y,q,z,tt,wt;
float ttt=0,twt=0;
int que[20];
struct process{
    int at;
    int bt;
    int btstat;
    int inque;
    int comple;
}p[20];
void enque(int m){
    if(front==-1){
        front=0;
        rear=0;
    }
    else
        rear++;
    que[rear]=m;
}
int deque(){
    y=que[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else
        front++;
    return y;
}
void main(){
    printf("\nTotal number of process: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter AT & BT for PROCESS P%d: ",i);
        scanf("%d",&p[i].at);
        scanf("%d",&p[i].bt);
        p[i].btstat=p[i].bt;
        p[i].inque=0;
        tot=tot+p[i].bt;
    }
    printf("\nEnter the time quantum: ");
    scanf("%d",&q);
    j=0;
    while(j<=tot){
        for(k=1;k<=n;k++){
            if(p[k].at<=j&&p[k].inque==0){
                enque(k);
                p[k].inque=1;
            }
        }
        if(p[z].btstat!=0)

            enque(z);
        else
            p[z].comple=j;
        y=deque();
        if(y!=0){
            if(p[y].btstat>=q){
                p[y].btstat=p[y].btstat-q;
                j=j+q;
            }
            else{
                j=j+p[y].btstat;
                p[y].btstat=0;
            }
            z=y;
        }
        else
            break;
        
    }
    printf("\nTABLE");
    printf("\nPROCESS\tAT\tBT\tCT\tTT\tWT");
    for(i=1;i<=n;i++)
    {
        tt=p[i].comple-p[i].at;
        wt=tt-p[i].bt;
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",i,p[i].at,p[i].bt,p[i].comple,tt,wt);
        ttt=ttt+tt;
        twt=twt+wt;
    }
    printf("\nAVERAGE TURNAROUND TIME IS %f",ttt/n);
    printf("\nAVERAGE WAITING TIME IS %f\n",twt/n);
}