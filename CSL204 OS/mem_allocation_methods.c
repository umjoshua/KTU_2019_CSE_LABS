/*
Memory Allocation Methods for fixed partition:
a) First Fit
b) Best Fit
c) Worst Fit
*/

#include<stdio.h>

void firstfit(int block[],int bSize,int process[],int pSize){
    int allocation[pSize];
    for(int i=0;i<pSize;i++)
        allocation[i]=-1;
     for (int i = 0; i < pSize; i++){
        for (int j = 0; j < bSize; j++){
            if (block[j] >= process[i]){
                allocation[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }
    printf("First Fit\n");
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for(int i=0;i<pSize;i++){
        printf("%d\t\t%d\t\t",i+1,process[i]);
        if(allocation[i]!=-1)
            printf("%d",allocation[i]+1);
        else
            printf("Not allocated");
        printf("\n");
    }
}

void bestfit(int block[],int bSize,int process[],int pSize){
    int allocation[pSize];
    for(int i=0;i<pSize;i++)
        allocation[i]=-1;
    for(int i=0;i<pSize;i++){
        int bestIndex=-1;
        for(int j=0;j<bSize;j++){
            if(block[j]>=process[i]){
                if(bestIndex==-1)
                    bestIndex=j;
                else if (block[bestIndex]>block[j])
                    bestIndex=j;
            }
        }
        if(bestIndex!=-1){
            allocation[i]=bestIndex;
            block[bestIndex]-=process[i];
        }
    }
    printf("Best Fit\n");
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for(int i=0;i<pSize;i++){
        printf("%d\t\t%d\t\t",i+1,process[i]);
        if(allocation[i]!=-1)
            printf("%d",allocation[i]+1);
        else
            printf("Not allocated");
        printf("\n");
    }
    
}
void worstfit(int block[],int bSize,int process[],int pSize){
    int allocation[pSize];

    for(int i=0;i<pSize;i++)
        allocation[i]=-1;

    for(int i=0;i<pSize;i++){
        int worstIndex=-1;
        for(int j=0;j<bSize;j++){
            if(block[j]>=process[i]){
                if(worstIndex==-1)
                    worstIndex=j;
                else if (block[worstIndex]<block[j])
                    worstIndex=j;
            }
        }
        if(worstIndex!=-1){
            allocation[i]=worstIndex;
            block[worstIndex]-=process[i];
        }
    }
    printf("Worst Fit\n");
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for(int i=0;i<pSize;i++){
        printf("%d\t\t%d\t\t",i+1,process[i]);
        if(allocation[i]!=-1)
            printf("%d",allocation[i]+1);
        else
            printf("Not allocated");
        printf("\n");
    }
    
}


void main(){
    int bSize,pSize,choice;
    printf("1.First Fit 2.Best Fit 3.Worst Fit\n");
    printf("Enter your choice: ");
        scanf("%d",&choice);
    printf("Enter No. of Blocks: ");
        scanf("%d",&bSize);
    printf("Enter No. of Process: ");
        scanf("%d",&pSize);
    
    int block[bSize];
    int process[pSize];
    
    printf("Enter process sizes\n");
    for(int i=0;i<pSize;i++){
        printf("Enter Process %d Size: ",i+1);
        scanf("%d",&process[i]);
    }
    
    printf("Enter block sizes\n");
    for(int i=0;i<bSize;i++){
        printf("Enter Block %d Size: ",i+1);
        scanf("%d",&block[i]);
    }
    switch (choice){
        case 1:firstfit(block, bSize, process, pSize);
            break;
        case 2:bestfit(block, bSize, process, pSize);
            break;
        case 3:worstfit(block, bSize, process, pSize);
            break;
    }

}