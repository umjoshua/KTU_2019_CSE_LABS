#include<stdio.h>
#include<stdlib.h>
struct fcfs{
	int id;
	int arrival;
	int burst;
	int completion;
	int turn_around;
	int waiting;
}p[20];

int n,wt_sum=0,tt_sum=0;

void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

void sort(){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(p[j].arrival>p[j+1].arrival){
				swap(&p[j].id,&p[j+1].id);
				swap(&p[j].arrival,&p[j+1].arrival);
				swap(&p[j].burst,&p[j+1].burst);
			}
		}
	}
}

int is_available(int i,int time){
	if(p[i].arrival<=time)
		return 1;
	else return 0;
}

void fcfs(){
	int last_time=0;
	for(int i=0;i<n;i++){
		if(is_available(i,last_time)==1){
			p[i].completion=last_time+p[i].burst;
			last_time=p[i].completion;
		}
		else{
			p[i].completion=p[i].arrival+p[i].burst;
			last_time=p[i].completion;
		}
		p[i].turn_around=p[i].completion-p[i].arrival;
		tt_sum+=p[i].turn_around;
		p[i].waiting=p[i].turn_around-p[i].burst;
		wt_sum+=p[i].waiting;
	}
}

void main(){
	printf("FCFS Disk Scheduling\n");
	printf("Enter number of process: ");
	scanf("%d",&n);
	printf("Enter the arrival times: ");
	for(int i=0;i<n;i++){
		scanf("%d",&p[i].arrival);
	}
	printf("Enter the burst times: ");
	for(int i=0;i<n;i++){
		scanf("%d",&p[i].burst);
		p[i].id=i;
	}
	sort();
	fcfs();
	printf("ID\tAT\tBT\tCT\tTT\tWT\n");
	for(int i=0;i<n;i++)
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].arrival,p[i].burst,p[i].completion,p[i].turn_around,p[i].waiting);
	printf("Average waiting time: %f\n",(float)wt_sum/n);
	printf("Average turn around time: %f\n",(float)tt_sum/n);
}
