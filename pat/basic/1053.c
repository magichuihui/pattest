#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, D;
    float e;
    scanf("%d %f %d", &N, &e, &D);

    int i, j, K, count;
    float consumption;

    int empty=0, possible=0;
    for (i=0;i<N;i++) {
        scanf("%d", &K);
        count = 0;
        for (j=0;j<K;j++) {
            scanf("%f", &consumption);
            if (consumption<e) count++;
        }
        if (count > K/2) {
            if (K > D) {
                empty++;
            } else {
                possible++;
            }
        }
    }

    printf("%.1f%% %.1f%%\n", (float) possible / N * 100.0, (float) empty / N * 100.0);
}