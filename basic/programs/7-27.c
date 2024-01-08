#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int a[MAX_SIZE];
    int K, N;
    scanf("%d %d", &N, &K);

    int i, j, temp;
    for (i=0;i<N;i++) {
        scanf("%d", &a[i]);
    }

    for (i=0;i<K;i++) {
        for (j=0;j<N-i-1;j++) {
            // need to swap
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for (i=0;i<N;i++) {
        printf("%d", a[i]);
        if (i!=N-1) printf(" ");
    }
}