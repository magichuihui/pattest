#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int main(void) {
    int N, M;
    int couples[MAX_SIZE];
    int participate[MAX_SIZE];
    int i;

    for (i=0;i<MAX_SIZE;i++) couples[i] = participate[i] =-1;

    scanf("%d", &N);
    int c1, c2;
    for (i=0;i<N;i++) {
        scanf("%d %d", &c1, &c2);
        couples[c1] = c2;
        couples[c2] = c1;
    }

    scanf("%d", &M);
    for (i=0;i<M;i++) {
        scanf("%d", &c1);
        participate[c1] = 1;
    }

    int count=0, first=1;
    for (i=0;i<MAX_SIZE;i++) {
        if (participate[i]>=1) {
            if (couples[i]==-1 || participate[couples[i]] == -1) {
                participate[i]++;
                count++;
            }
        }
    }
    printf("%d\n", count);
    for (i=0;i<MAX_SIZE;i++) {
        if (participate[i]>1) {
            if (!first) printf(" ");
            printf("%05d", i);
            first=0;
        }
    }
    printf("\n");

}