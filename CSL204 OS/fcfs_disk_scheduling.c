#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int i, j, k, n, m, sum = 0, x, y, h;
    printf("Enter the size of disk\n");
    scanf("%d", &m);
    printf("Enter number of requests\n");
    scanf("%d", &n);
    printf("Enter the requests\n");
    
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        if (a[i] > m) {
            printf("Error, Unknown position %d\n", a[i]);
            return 0;
        }
    }
    printf("Enter the head position\n");
    scanf("%d", &h);

    int temp = h;
    printf("%d", temp);
    for (i = 0; i < n; i++) {
        printf(" -> %d", a[i]);
        
        sum += abs(a[i] - temp);
        temp = a[i];
    }
    printf("\n");
    printf("Total head movements = %d\n", sum);
    return 0;
}