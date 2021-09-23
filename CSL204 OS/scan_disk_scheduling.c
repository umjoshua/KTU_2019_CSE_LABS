#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;
    printf("Enter total disk size\n");
    scanf("%d", &size);
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp;
                temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    int index;
    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }
    printf("%d",initial);
    for (i = index; i < n; i++) {
        TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
        printf(" -> %d", RQ[i]);
        initial = RQ[i];
    }

    TotalHeadMoment = TotalHeadMoment + abs(size - RQ[i - 1] - 1);
    initial = size - 1;
    printf("-> %d",initial);
    for (i = index - 1; i >= 0; i--) {
        TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
        initial = RQ[i];
        printf(" -> %d", RQ[i]);
    }

    printf("\nTotal head movement is %d\n", TotalHeadMoment);
    return 0;
}
