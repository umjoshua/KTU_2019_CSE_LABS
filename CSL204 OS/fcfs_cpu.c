#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct fcfs{
    int id;
    int arrival;
    int burst;
    int completion;
    int waiting_time;
    int turnaround_tme;
}process[20];

float average_wt=0, average_tt=0;
int wt_sum=0,tt_sum=0;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(process[j].arrival>process[j+1].arrival){
                swap(&process[j].id,&process[j+1].id);
                swap(&process[j].arrival,&process[j+1].arrival);
                swap(&process[j].burst,&process[j+1].burst);
            }
        }
    }
}
int is_available(int i,int t){
    if(process[i].arrival<=t)
        return 1;
    else
        return 0;
}
void calculate_fcfs(int n){
    for(int i=0;i<n;i++){
        if(i==0){
            if(is_available(i,0)==1)
                process[i].completion=process[i].burst;
            else
                process[i].completion=process[i].arrival+process[i].burst;
        }
        else{
            if(is_available(i,(process[i-1].completion))==1)
                process[i].completion=process[i-1].completion+process[i].burst;
            else{
                process[i].completion=process[i].arrival+process[i].burst;
            }
        }
        process[i].turnaround_tme=process[i].completion-process[i].arrival;
        process[i].waiting_time=process[i].turnaround_tme-process[i].burst;
        tt_sum=tt_sum+process[i].turnaround_tme;
        wt_sum=wt_sum+process[i].waiting_time;
    }
}

void main(){
    int n,i;
    printf("**FCFS CPU Scheduling**\n");
    printf("Enter number of process: ");
    scanf("%d",&n);
    printf("Enter arrival times: ");
    for(i=0;i<n;i++)
        scanf("%d",&process[i].arrival);
    printf("Enter burst times: ");
    for(i=0;i<n;i++)
        scanf("%d",&process[i].burst);
    for(i=0;i<n;i++)
        process[i].id=i+1;
    sort(n);
    calculate_fcfs(n);
    printf("ID\tAT\tBT\tCT\tTT\tWT");
    for(i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\n",process[i].id,process[i].arrival,process[i].burst,process[i].completion,process[i].turnaround_tme,process[i].waiting_time);
    }
    average_tt=tt_sum/(float)n;
    average_wt=wt_sum/(float)n;
    printf("Average waiting time: %f\n",average_wt);
    printf("Average Turn Around Time time: %f\n",average_tt);
}
