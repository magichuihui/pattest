#include <stdio.h>

#define MAX_SIZE 100000

int main(void) {
    int N, K;
    int scores[MAX_SIZE], search[MAX_SIZE], counter[101];

    int i;
    for (i=0;i<102;i++) counter[i] = 0;
    scanf("%d", &N);
    for (i=0;i<N;i++) {
        scanf("%d", &scores[i]);
        counter[scores[i]]++;
    }
    scanf("%d", &K);
    for (i=0;i<K;i++) {
        scanf("%d", &search[i]);
    }

    for (i=0;i<K;i++) {
        printf("%d", counter[search[i]]);
        if (i!=K-1) printf(" ");
    }
    printf("\n");
}