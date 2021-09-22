#include<stdio.h>

int n, nf, data[100], p[50], hit = 0, i, j, k, pgfaultcnt = 0;
void getData() {
    printf("\nEnter length of page reference sequence:");
    scanf("%d", & n);
    printf("\nEnter the page reference sequence:");
    for (i = 0; i < n; i++)
        scanf("%d", & data[i]);
    printf("\nEnter no of frames:");
    scanf("%d", & nf);
}
void initialize() {
    pgfaultcnt = 0;
    for (i = 0; i < nf; i++)
        p[i] = 9999;
}
int isHit(int data) {
    hit = 0;
    for (j = 0; j < nf; j++) {
        if (p[j] == data) {
            hit = 1;
            break;
        }
    }
    return hit;
}
int getHitIndex(int data) {
    int hitind;
    for (k = 0; k < nf; k++) {
        if (p[k] == data) {
            hitind = k;
            break;
        }
    }
    return hitind;
}
void dispPages() {
    for (k = 0; k < nf; k++) {
        if (p[k] != -1)
            printf(" %d", p[k]);
    }
}
void dispPgFaultCnt() {
    printf("\nTotal no of page faults:%d", pgfaultcnt);
}
void fifo() {
    initialize();
    for (i = 0; i < n; i++) {
        printf("\nFor %d :", data[i]);
        if (isHit( data[i]) == 0) {
            for (k = 0; k < nf - 1; k++)
                p[k] = p[k + 1];
            p[k] = data[i];
            pgfaultcnt++;
            dispPages();
        } else
            printf("No page fault");
    }
    dispPgFaultCnt();
}
void optimal() {
    initialize();
    int near[50];
    for (i = 0; i < n; i++) {
        printf("\nFor %d :", data[i]);
        if (isHit(data[i]) == 0) {
            for (j = 0; j < nf; j++) {
                int pg = p[j];
                int found = 0;
                for (k = i; k < n; k++) {
                    if (pg == data[k]) {
                        near[j] = k;
                        found = 1;
                        break;
                    } else
                        found = 0;
                }
                if (!found)
                    near[j] = 9999;
            }
            int max = -9999;
            int repindex;
            for (j = 0; j < nf; j++) {
                if (near[j] > max) {
                    max = near[j];
                    repindex = j;
                }
            }
            p[repindex] = data[i];
            pgfaultcnt++;
            dispPages();
        } else
            printf("No page fault");
    }
    dispPgFaultCnt();
}
void lru() {
    initialize();
    int least[50];
    for (i = 0; i < n; i++) {
        printf("\nFor %d :", data[i]);
        if (isHit( data[i]) == 0) {
            for (j = 0; j < nf; j++) {
                int pg = p[j];
                int found = 0;
                for (k = i - 1; k >= 0; k--) {
                    if (pg == data[k]) {
                        least[j] = k;
                        found = 1;
                        break;
                    } else
                        found = 0;
                }
                if (!found)
                    least[j] = -9999;
            }
            int min = 9999;
            int repindex;
            for (j = 0; j < nf; j++) {
                if (least[j] < min) {
                    min = least[j];
                    repindex = j;
                }
            }
            p[repindex] = data[i];
            pgfaultcnt++;
            dispPages();
        } else
            printf("No page fault!");
    }
    dispPgFaultCnt();
}
int main() {
    int choice;
    getData();
    printf("\n1.FIFO\n2.Optimal\n3.LRU\n4.Exit");
    do {
        printf("\nEnter your choice:");
        scanf("%d", & choice);
        switch (choice) {
            case 1:
                fifo();
                break;
            case 2:
                optimal();
                break;
            case 3:
                lru();
                break;
            case 4:
                printf("\nExiting\n");
                break;
        }
    } while (choice != 4);
}
