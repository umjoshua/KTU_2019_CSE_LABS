#include<stdio.h>
#include<stdlib.h>
int mutex=1,i=0, buffer[10], empty=10, full=0;
int wait(int x){
	--x;
	return x;
}
int signal(int x){
	++x;
	return x;
}
void producer(){
	empty=wait(empty);
	mutex=wait(mutex);
	printf("Enter value to produce: ");
	scanf("%d", &buffer[i]);
	i++;
	mutex=signal(mutex);
	full=signal(full);	
}
void consumer(){
	full=wait(full);
	mutex=wait(mutex);
	printf("Consumed item is %d\n",buffer[i-1]);
	i--;
	mutex=signal(mutex);
	empty=signal(empty);
}
void main(){
	int x;
	char ch='y';
	while(ch=='y'){
		printf("\n1.Producer 2.Consumer 3.Exit:  ");
		scanf("%d", &x);
		switch(x){
			case 1: if(mutex==1 && empty!=0)
					producer();
					else
					printf("Buffer is full\n");
					break;
			case 2: if(mutex==1 && full!=0)
					consumer();
					else
					printf("Buffer is empty\n");
					break;
			case 3: printf("Terminating...\n");
					exit(0);
					break;
			default: printf("Invalid choice\n");
		}  
		printf("The buffer is: ");
		for(int j=0;j<i;j++)
			printf("%d ", buffer[j]);
	}
}