#include <stdio.h>
void swap(int *x, int *y){
    int temp= *x;
    *x = *y;
    *y =temp;
}
int main() {
    int i, n, j, m, min, sum = 0, x = 1, btTotal = 0;
    int p[20], bt[20], at[20], wt[20], tat[20], ta = 0;
    float ttt = 0, wtt = 0;

    printf("\nEnter number of processes: ");
    scanf("%d", & n);

    printf("\nEnter the arrival time of process: ", p[i]);
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        scanf(" %d", & at[i]);
    }
    printf("\nEnter the burst time of process: ", p[i]);
    for (i = 0; i < n; i++) {
        scanf(" %d", & bt[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (at[j] > at[i]) {
                swap(&p[j],&p[i]);
                swap(&at[j],&at[i]);
                swap(&bt[j],&bt[i]);
            }
        }
    }

    for (i = 0; i < n; i++) {
        btTotal = btTotal + bt[i];
        min = bt[x];
        for (j = x; j < n; j++) {
            if (bt[j] < min && btTotal >= at[j]) {
                swap(&p[x],&p[j]);
                swap(&at[x],&at[j]);
                swap(&bt[x],&bt[j]);
            }
        }
        x++;
    }

    for (i = 0; i < n; i++) {
        ta = ta + bt[i];
        tat[i] = ta - at[i];
        ttt = ttt + tat[i];
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        sum = sum + bt[i - 1];
        wt[i] = sum - at[i];
        wtt = wtt + wt[i];
    }

    printf("\nProcess\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time");
    for (i = 0; i < n; i++) {
        p[i]=i+1;
        printf("\n p%d\t %d\t\t %d\t\t %d\t\t %d", p[i], at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (wtt / n));
    printf("\nAverage Turn Around Time: %.2f\n", (ttt/ n));
}