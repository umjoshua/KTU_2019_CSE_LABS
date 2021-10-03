/*FIFO Page Replacement Algorithm*/
#include<stdio.h>
#include<stdlib.h>
int capacity,n,pages[50],frames[50],k,pagefault=0,pagehit=0;

int isHit(int item){
	int found=0;
	for(int i=0;i<capacity;i++){
		if(frames[i]==item){
			found =1;
		}
	}
	return found;
}

void main(){
	printf("Enter number of page refrence: ");
	scanf("%d",&n);
	printf("Enter page refrence sequence: ");
	for(int i=0;i<n;i++)
		scanf("%d",&pages[i]);
	printf("Enter size of frame: ");
	scanf("%d",&capacity);

	for(int i=0;i<capacity;i++)
		frames[i]=999;

	for(int i=0;i<n;i++){
		int item=pages[i];
		printf("For %d: ",item);
		if(isHit(item)==0){
			for(int j=0;j<capacity-1;j++){
				frames[j]=frames[j+1];
			}
			frames[capacity-1]=item;
            for(k=0;k<capacity;k++)
            	if(frames[k]!=999)
            	printf("%d ",frames[k]);
            printf("\n");
            pagefault++;
		}
		else{
			printf("No page fault\n");
            pagehit++;
		}
	}
    printf("\nNo. of page faults: %d\n",pagefault);
	printf("No. of page hits: %d\n",pagehit);
}