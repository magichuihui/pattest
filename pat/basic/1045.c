#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int comfunc(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main(void) {
    int N;
    int number[MAX_SIZE], primary[MAX_SIZE];
    scanf ("%d", &N);
    
    int i, count=0;
    int temp;

    for (i=0;i<N;i++) {
        scanf("%d", &temp);
        number[i] = temp;
        primary[i] = temp;
    }

    // for (i=0;i<N;i++) printf("%d %d\n", number[i], primary[i]);return 0;

    qsort(number, N, sizeof(int), comfunc);

    for (i=0;i<N;i++) {
        if (number[i] == primary[i]) count++;
    }

    printf("%d\n", count);
    for (i=0;i<N;i++) {
        if (primary[i]==number[i]) {
            printf("%d", number[i]);
            if (count--!=1) printf(" ");
        }
    }
    printf("\n");

}