#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void * a, const void * b);

int main(void) {
    int N;
    scanf("%d", &N);
    int *rope = (int *) malloc(N * sizeof(int));

    int i;
    for (i=0;i<N;i++) scanf("%d", &rope[i]);

    qsort(rope, N, sizeof(int), compare);

    double length=rope[0] / pow(2.0, N-1);

    for (i=1;i<N;i++) {
        length += rope[i] / pow(2.0, N-i);
    }

    printf("%d\n", (int) floor(length));
}

int compare(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}