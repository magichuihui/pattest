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
    
    int i, j, count=0;

    for (i=0;i<N;i++) primary[i] = 1;

    for (i=0;i<N;i++) {
        scanf("%d", &number[i]);
    }

    //qsort(number, N, sizeof(int), comfunc);

    for (i=0;i<N;i++) {
        j=0;
        while (j<i && primary[i]) if (number[j++]>number[i]) primary[i]=0;

        j=i+1;
        while (j<N && primary[i]) if (number[j++]<number[i]) primary[i]=0;

        if (primary[i]) count++;
    }

    printf("%d\n", count);
    for (i=0;i<N;i++) {
        if (primary[i]) {
            printf("%d", number[i]);
            if (count--!=1) printf(" ");
        }
    }
    printf("\n");

}