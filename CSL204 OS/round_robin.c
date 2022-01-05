#include<stdio.h>
struct round_r{
	int id;
    int burst;
    int completion;
    int turn_around;
    int waiting;
    int burst_remain;
}rr[20];

int n,q;

float wt_sum=0,tt_sum=0;
int z=0;

void round_robin(){
	int x=0;
	for(int j=0;j<n*n;j++){
		for(int i=0;i<n;i++){
			if(rr[i].burst_remain>q){
				x=x+q;
				rr[i].burst_remain-=q;
				rr[i].completion=x;
			}
			else if(rr[i].burst_remain==0)
				continue;
			else if(rr[i].burst_remain<=q){
				x=x+rr[i].burst_remain;
				rr[i].completion=x;
				rr[i].burst_remain=0;
                rr[i].turn_around=rr[i].completion;
                rr[i].waiting=rr[i].turn_around-rr[i].burst;
                wt_sum+=rr[i].waiting;
                tt_sum+=rr[i].turn_around;
			}
		}
        if(rr[z].burst_remain==0)
            break;
	}
}

void main(){
	printf("Round Robin Disk Scheduling\n");
	printf("Enter number of process: "); scanf("%d",&n);
	printf("Enter the time quantum: "); scanf("%d",&q);
	printf("Enter the burst times: ");
	for(int i=0;i<n;i++){
		scanf("%d",&rr[i].burst);
		rr[i].burst_remain=rr[i].burst;
        if(rr[i].burst>rr[z].burst)
            z=i;
		rr[i].id=i;
	}

	round_robin();
	printf("ID\tBT\tCT\tTT\tWT\n");
	for(int i=0;i<n;i++)
		printf("%d\t%d\t%d\t%d\t%d\n",rr[i].id,rr[i].burst,rr[i].completion,rr[i].turn_around,rr[i].waiting);
	printf("Average waiting time: %f\n",(float)wt_sum/n);
	printf("Average turn around time: %f\n",(float)tt_sum/n);        
}
