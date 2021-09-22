#include<stdio.h>

int main(){
    int bursturnaround[10]={0},arrival[10]={0},turnaround[10]={0},waiting[10]={0},completion[10]={0};
    int n,sum=0;
    float totalTAT=0,totalWT=0;
    printf("Enter number of processes: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Arrival time of process[%d]:", i+1);
		scanf("%d",&arrival[i]);
	}
	printf("Enter  burst time for each process:\n\n");
		for(int i=0;i<n;i++){
	printf("Burst time of process[%d]:",i+1);
		scanf("%d",&bursturnaround[i]);
		}
    for(int j=0;j<n;j++){
		sum+=bursturnaround[j];
		completion[j]+=sum;
	}
	for(int k=0;k<n;k++){
		turnaround[k]=completion[k]-arrival[k];
		totalTAT+=turnaround[k];
	}
	for(int k=0;k<n;k++){
		waiting[k]=turnaround[k]-bursturnaround[k];
		totalWT+=waiting[k];
	}
	printf("Process\t Arival Time\t Burst Time\t Completion Time\t Turn Arount Time\t Waiting Time\t\n\n");
	
	for(int i=0;i<n;i++){
		printf("P%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",i+1,arrival[i],bursturnaround[i],completion[i],turnaround[i],waiting[i]);
	}
		
	printf("\n\nAverage Turnaround Time = %f\n",totalTAT/n);
	printf("Average WT = %f\n\n",totalWT/n);
	return 0;
}