#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b);

int main(void) {
    int N;
    scanf("%d", &N);
    int *rope = (int *) malloc(N * sizeof(int));

    int i;
    for (i=0;i<N;i++) scanf("%d", &rope[i]);

    qsort(rope, N, sizeof(int), compare);

    for (i=0;i<N;i++) printf("%d\n", rope[i]);
}

int compare(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}