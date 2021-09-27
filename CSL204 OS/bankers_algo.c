#include <stdio.h>

void main() {
    int n, r, i, j, k;
    printf("\nEnter number of processes:");
    scanf("%d", & n);
    printf("\nEnter the number of resources:");
    scanf("%d", & r);
    int alloc[n][r];
    int max[n][r];
    printf("\nEnter allocation matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", & alloc[i][j]);
        printf("\n");
    }
    printf("\nEnter max matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", & max[i][j]);
        printf("\n");
    }
    int avail[r];
    printf("\nEnter available resources:");
    for (i = 0; i < r; i++)
        scanf("%d", & avail[i]);
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][r];
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < r; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
    printf("The safe Sequence is as follows\n");
    for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
    printf(" P%d\n", ans[n - 1]);
}
