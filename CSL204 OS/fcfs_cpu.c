#include<stdio.h>

int main(){
    int b[10]={0},a[10]={0},t[10]={0},w[10]={0},c[10]={0};
    int n,sum=0;
    float totalTAT=0,totalWT=0;
    printf("Enter number of processes: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Arrival time of process[%d]:", i+1);
		scanf("%d",&a[i]);
	}
	printf("Enter  burst time for each process:\n\n");
		for(int i=0;i<n;i++){
	printf("Burst time of process[%d]:",i+1);
		scanf("%d",&b[i]);
		}
    for(int j=0;j<n;j++){
		sum+=b[j];
		c[j]+=sum;
	}
	for(int k=0;k<n;k++){
		t[k]=c[k]-a[k];
		totalTAT+=t[k];
	}
	for(int k=0;k<n;k++){
		w[k]=t[k]-b[k];
		totalWT+=w[k];
	}
	printf("Process\t Arival Time\t Burst Time\t Completion Time\t Turn Arount Time\t Waiting Time\t\n\n");
	
	for(int i=0;i<n;i++){
		printf("P%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",i+1,a[i],b[i],c[i],t[i],w[i]);
	}
		
	printf("\n\nAverage Turnaround Time = %f\n",totalTAT/n);
	printf("Average WT = %f\n\n",totalWT/n);
	return 0;
}